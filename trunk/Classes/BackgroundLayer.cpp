#include "BackgroundLayer.h"
#include "Rock.h"

bool BackgroundLayer::init()
{

	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	backGround = CCSprite::create("backGround.png");
	backGround->setScaleX(visibleSize.width / backGround->getContentSize().width);
	backGround->setScaleY(visibleSize.height / backGround->getContentSize().height);
	backGround->setPosition( CCPoint( visibleSize.width / 2, visibleSize.height / 2 ) );
	this->addChild(backGround);

	srand( time(0) );
	this->objs = new cocos2d::CCArray( 0 );
	n = rand() % 50 + 50;
	n = 5;//
	arrRock = new Rock*[n];
	for (int i = 0; i < n; i++)
	{
		arrRock[i] = new Rock();
		CCPoint pos = arrRock[i]->getPosition();
		pos.x = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().width - arrRock[i]->getBound().size.width ) 
			+ arrRock[i]->getBound().size.width / 2;
		pos.y = rand() % (int)( CCDirector::sharedDirector()->getVisibleSize().height - arrRock[i]->getBound().size.height ) 
			+ arrRock[i]->getBound().size.height / 2;
		arrRock[i]->setPosition( pos );
		this->addChild( arrRock[i] );
		objs->addObject( arrRock[i] );
	}

	pLabel = CCLabelTTF::create("Tuan Hoang", "Arial", visibleSize.height / 20);
	pLabel->setPosition( CCPoint(visibleSize.width / 3, visibleSize.height / 4) );
	this->addChild(pLabel);

	//lable rock
	pLabelRock = CCLabelTTF::create("", "Arial", visibleSize.height / 20);
	pLabelRock->setPosition( CCPoint(visibleSize.width / 3, visibleSize.height / 5) );
	this->addChild(pLabelRock);

	FAcc_x = 0;
	FAcc_y = 0;
	//FAcc = CCPoint(0, 0);

	flagAcc = false;
	timeDuringAccUpdate = 0;
//	d = 0;
	//this->setTouchEnabled(false);
	this->scheduleUpdate();
	return true;
}

void BackgroundLayer::didAccelerate(CCAcceleration* pAccelerationValue)
{
	if (timeDuringAccUpdate > 0.1f)//not first time
	{
		if (flagAcc)
		{
			speedAcc = ( ( pAccelerationValue->x + pAccelerationValue->y + pAccelerationValue->z) 
								- (last_x + last_y + last_z) ) / timeDuringAccUpdate * 1000;

			//bugs
			if (speedAcc < -300 || speedAcc > 300)//is shaking  
			{
				//update vector Acc Delta
				vectorAccDelta_x = ( pAccelerationValue->x - last_x ) * 9.81f;
				vectorAccDelta_y = ( pAccelerationValue->y - last_y ) * 9.81f;

				//here
				FAcc_x = ( vectorAccDelta_x / timeDuringAccUpdate ) * 40;
				FAcc_y = ( vectorAccDelta_y / timeDuringAccUpdate ) * 40;

				for (int i = 0; i < n; i++)
				{
					arrRock[i]->addF_x( FAcc_x );
					arrRock[i]->addF_y( FAcc_y );
				}
			}
			else
			{
				vectorAccDelta_x = 0.0;
				vectorAccDelta_y = 0.0;
				for (int i = 0; i < n; i++)
				{
					arrRock[i]->addF_x( 0);
					arrRock[i]->addF_y( 0 );
				}
			}
			last_x = pAccelerationValue->x;
			last_y = pAccelerationValue->y;
			last_z = pAccelerationValue->z;
		}else
		{
			//posOldAcc = posCurAcc = ptTemp1; //pDir->convertToGL(ptTemp);
			flagAcc = true;
			
			last_x = pAccelerationValue->x;
			last_y = pAccelerationValue->y;
			last_z = pAccelerationValue->z;

			vectorAccDelta_y = vectorAccDelta_x = 0;
			//vectorAccDelta = CCPoint(0 , 0);
		}
		timeDuringAccUpdate = 0;
	}
	//pLabel->setString(str);
}

void BackgroundLayer::update(float delta)
{
	timeDuringAccUpdate += delta;
	
	sprintf(strRock, "%.2f  ----   %.2f", arrRock[0]->getF_x(), arrRock[0]->getF_y());
	pLabelRock->setString(strRock);

	float Fx_i;
	float Fy_i;
	//xem lai va cham
	for (int i = 0; i < n - 1; i++)
	{
		//GameObj* obji = (GameObj*) arrRock[i];
		CCRect bound_i = arrRock[i]->getBound();
		bound_i.origin.x += arrRock[i]->get_ax() * 100 * delta * delta;
		bound_i.origin.y += arrRock[i]->get_ay() * 100 * delta * delta;

		for (int j = i + 1; j < n; j++)
		{
			CCRect bound_j = arrRock[j]->getBound();
			bound_j.origin.x += arrRock[j]->get_ax() * 100 * delta * delta;
			bound_j.origin.y += arrRock[j]->get_ay() * 100 * delta * delta;

			if ( bound_i.intersectsRect( bound_j ) )
			{
				Fx_i = arrRock[i]->getF_x();
				Fy_i = arrRock[i]->getF_y();

				if (Fx_i * arrRock[j]->getF_x() > 0)
				{
					arrRock[i]->setF_x( ( Fx_i + arrRock[j]->getF_x() ) / 2 );
					arrRock[j]->setF_x( ( Fx_i + arrRock[j]->getF_x() ) / 2 );
				} 
				else
				{
					arrRock[i]->setF_x( ( arrRock[j]->getF_x() - Fx_i ) / 2 );
					arrRock[j]->setF_x( ( Fx_i - arrRock[j]->getF_x() ) / 2 );
				}
				
				if (Fy_i * arrRock[j]->getF_y() > 0)
				{
					arrRock[i]->setF_y( ( arrRock[j]->getF_y() + Fy_i ) / 2 );
					arrRock[j]->setF_y( ( Fy_i + arrRock[j]->getF_y() ) / 2 );
				} 
				else
				{
					arrRock[i]->setF_y( ( arrRock[j]->getF_y() - Fy_i ) / 2 );
					arrRock[j]->setF_y( ( Fy_i - arrRock[j]->getF_y() ) / 2 );
				}

			}
		}
	}
}