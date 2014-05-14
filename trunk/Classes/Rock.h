//---------------------------------------
//Name:    So Tuan Hoang
//Class:   Rock
//Project: Game Larva
//Purpose: Object rock make effect in game
//---------------------------------------

#ifndef ___ROCK__H_
#define ___ROCK__H_

#include <cocos2d.h>
#include "GameObj.h"
using namespace cocos2d;

class Rock : public GameObj 
{
public:
	Rock();
	void	  update(float dt);

	float	  getVx();
	void	  setVx(float );
	float	  getVy();
	void	  setVy(float );
	float	  getLastVx();
	void	  setLastVx(float );
	float	  getLastVy();
	void	  setLastVy(float );
	float ax;
	float ay;
protected:
private:
	CCRect screen;
	float vx;
	float vy;
	float last_vx;
	float last_vy;
	float a;
	float time_move;
	~Rock();
};
#endif // !___ROCK__H_