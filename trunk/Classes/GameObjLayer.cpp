#include "GameObjLayer.h"
#include "FileUtil.h"
#include "string"
#include "BugFactory.h"
#include "Bug.h"

bool GameObjLayer::init()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	file = FileUtil::getFileUtilInstance();
	file->LoadCSV();
	CCDictionary* mymap = file->getBugDictionary();

	for (int i = 0; i < mymap->count(); ++i)
	{
		stringstream ss;
		ss << (i + 1 );
		string id = ss.str();
		Bug* bug = new Bug(file->getInfoFromBucket(id,file->getBugDictionary()));
		arrBug.push_back(bug);
	}

	srand( time(0) );
	for ( int i = 0 ; i < arrBug.size(); ++i)
	{
		int x = rand() % (int)( visibleSize.width );
		int y = rand() % (int)( visibleSize.height );
		if( x < arrBug.at(i)->getBound().size.width / 2)
			x += arrBug.at(i)->getBound().size.width / 2;
		if(y < arrBug.at(i)->getBound().size.height / 2)
			y += arrBug.at(i)->getBound().size.height / 2;
		arrBug.at(i)->setLocation(ccp(x,y));
		this->addChild(arrBug.at(i));
	}

	flagAcc = false;
	timeDuringAccUpdate = 0;
	d = 0;
	this->scheduleUpdate();
	return true;
}

void GameObjLayer::ccTouchesBegan(CCSet*  pTouches, CCEvent* pEvent)
{
	//CCTouch* touch = (cocos2d::CCTouch*)( pTouches->anyObject() );
	//
	//CCPoint point = touch->getLocation();
	////CCPoint point1 = CCDirector::sharedDirector()->convertToGL(point);

	//for (int i = 0; i < arrBug.size(); i++)
	//{
	//	if ( arrBug.at(i)->getBound().containsPoint( point ) )
	//	{
	//		arrBug.at(i)->setVisible(false);
	//	}
	//}

	CCSetIterator iter = pTouches->begin();
	for ( ; iter != pTouches->end(); iter++ )
	{
		CCTouch* touch = (CCTouch*)( *iter );
		CCPoint point = touch->getLocation();
		for (int i = 0; i < arrBug.size(); i++)
		{
			if ( arrBug.at(i)->getBound().containsPoint( point ) )
			{
				arrBug.at(i)->setVisible(false);
				break;
			}
		}
	}
}

void GameObjLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	//CCTouch* touch = (cocos2d::CCTouch*)( pTouches->anyObject() );
	//
	//CCPoint point = touch->getLocation();
	//CCPoint point1 = CCDirector::sharedDirector()->convertToGL(point);
	///*int i = rand() % 3;
	//arrBug.at(i)->setLocation(point); */

	//for (int i = 0; i < arrBug.size(); i++)
	//{
	//	if ( arrBug.at(i)->getBound().containsPoint( point1 ) )
	//	{
	//		arrBug.at(i)->setVisible(false);
	//	}
	//}
}

void GameObjLayer::didAccelerate(CCAcceleration* pAccelerationValue)
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

			if (speedAcc < -200)//is shaking
			{
				isShaking = true;
				d += sqrt( pow( (pAccelerationValue->x - last_x), 2) + pow( (pAccelerationValue->y - last_y) ,2 ) + pow( (pAccelerationValue->z - last_z), 2) );

				//update vector Acc Delta
				vectorAccDelta.x = ( pAccelerationValue->x - last_x ) * 9.81f;
				vectorAccDelta.y = ( pAccelerationValue->y - last_y ) * 9.81f;
			}else if (speedAcc > 200)
			{
				isShaking = true;
				d += sqrt( pow( (pAccelerationValue->x - last_x), 2) + pow( (pAccelerationValue->y - last_y) ,2 ) + pow( (pAccelerationValue->z - last_z), 2) );

				//update vector Acc Delta
				vectorAccDelta.x = ( pAccelerationValue->x - last_x ) * 9.81f;
				vectorAccDelta.y = ( pAccelerationValue->y - last_y ) * 9.81f;
			}
			else
			{
				isShaking = false;
				d -= 5.0f;
				if (d < 0)
				{
					d = 0.0f;
				}
				vectorAccDelta = CCPoint(0 , 0);
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

	float vx = vectorAccDelta.x * 30;
	float vy = vectorAccDelta.y * 30;
}

void GameObjLayer::getBugs(std::vector<Bug*> arr)
{

}

void GameObjLayer::update(float delta)
{
	timeDuringAccUpdate += delta;
	//srand( time(0) );
	
	for (int i = 0; i < arrBug.size(); ++i)
	{
		//int curPower = rand() % 400 + 100;
		arrBug.at(i)->setCurPower( d * 30 );
	}
}
