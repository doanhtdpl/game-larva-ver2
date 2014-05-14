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
	n = 3;//
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

	flagAcc = false;
	timeDuringAccUpdate = 0;
	d = 0;
	this->scheduleUpdate();
	return true;
}

void BackgroundLayer::didAccelerate(CCAcceleration* pAccelerationValue)
{
	if (timeDuringAccUpdate > 0.1f)//not first time
	{
		if (flagAcc)
		{
			//posOldAcc = posCurAcc;
			//posCurAcc = pDir->convertToGL(ptTemp);
			//posCurAcc = ptTemp1;
			speedAcc = ( ( pAccelerationValue->x + pAccelerationValue->y + pAccelerationValue->z) 
								- (last_x + last_y + last_z) ) / timeDuringAccUpdate * 1000;
			/*if (speedAcc < 0.0f)
				speedAcc *= -1.0f*/;

			//bugs
			if (speedAcc < -200|| speedAcc > 200)//is shaking  
			{
				isShaking = true;
				d += sqrt( pow( (pAccelerationValue->x - last_x), 2) + pow( (pAccelerationValue->y - last_y) ,2 ) + pow( (pAccelerationValue->z - last_z), 2) );

				//update vector Acc Delta
				vectorAccDelta.x = ( pAccelerationValue->x - last_x ) * 9.81f;
				vectorAccDelta.y = ( pAccelerationValue->y - last_y ) * 9.81f;


			//}else if (speedAcc > 200)
			//{
			//	isShaking = true;
			//	d += sqrt( pow( (pAccelerationValue->x - last_x), 2) + pow( (pAccelerationValue->y - last_y) ,2 ) + pow( (pAccelerationValue->z - last_z), 2) );

			//	//update vector Acc Delta
			//	vectorAccDelta.x = ( pAccelerationValue->x - last_x ) * 9.81f;
			//	vectorAccDelta.y = ( pAccelerationValue->y - last_y ) * 9.81f;
			}
			else
			{
				isShaking = false;
				d -= 5.0f;
				if (d < 0)
				{
					d = 0.0f;
				}
				vectorAccDelta.x = 0.0;
				vectorAccDelta.y = 0.0;
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

			vectorAccDelta = CCPoint(0 , 0);
		}
		timeDuringAccUpdate = 0;
	}

	float vx = vectorAccDelta.x * 150;
	float vy = vectorAccDelta.y * 150;
	for (int i = 0; i < n; i++)
	{
		arrRock[i]->setVx( vx );
		arrRock[i]->setVy( vy );

		arrRock[i]->setLastVx( vx );
		arrRock[i]->setLastVy( vy );

		//if (vx > 0)
		//{
		//	arrRock[i]->ax = -2;
		//}else
		//{
		//	arrRock[i]->ax = 2;
		//}

		//if (vy > 0)
		//{
		//	arrRock[i]->ay = -2;
		//}else
		//{
		//	arrRock[i]->ay = 2;
		//}
	}
}

void BackgroundLayer::update(float delta)
{
	timeDuringAccUpdate += delta;
	//xem lai va cham
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if ( arrRock[i]->getBound().intersectsRect( arrRock[j]->getBound() ) )
			{
				arrRock[i]->setVx( -arrRock[i]->getVx() );
				arrRock[i]->setVy( -arrRock[i]->getVy() );
				arrRock[j]->setVx( -arrRock[i]->getVx() );
				arrRock[j]->setVy( -arrRock[i]->getVy() );
			}
		}
	}
}