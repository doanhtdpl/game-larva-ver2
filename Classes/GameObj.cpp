#include "GameObj.h"

GameObj::GameObj() 
{
	
}


void GameObj::insert(char* bucket, char* value)
{
	bucket = value;
}

CCRect GameObj::getBound(int scale)
{
	if( this->body != NULL )
	{
		CCRect bodySize	=	body->boundingBox();
		CCPoint bodyPoint	=	this->getPosition();
		CCRect bound		=	cocos2d::CCRectMake( bodyPoint.x - bodySize.size.width/2 * scale, 
			bodyPoint.y - bodySize.size.height/2*scale, bodySize.size.width* scale, bodySize.size.height * scale);
		return bound;
	}
	return CCRectMake(0, 0, 0, 0);
}

CCRect GameObj::getBound()
{
	if( this->body != NULL )
	{
		CCRect bodySize	=	body->boundingBox();
		CCPoint bodyPoint	=	this->getPosition();
		CCRect bound		=	cocos2d::CCRectMake( bodyPoint.x - bodySize.size.width/2 , 
			bodyPoint.y - bodySize.size.height/2, bodySize.size.width, bodySize.size.height);
		return bound;
	}
	return CCRectMake(0, 0, 0, 0);
}