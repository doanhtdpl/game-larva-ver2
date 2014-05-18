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

#define m 30

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

	float	  get_ax();
	void	  set_ax(float );
	float	  get_ay();
	void	  set_ay(float );
	float	  getF_x();
	void	  setF_x(float );
	float	  getF_y();
	void	  setF_y(float );
	float	  getVector_ax();
	void	  setVector_ax(float );
	float	  getVector_ay();
	void	  setVector_ay(float );
	void      addF_x(float );
	void      addF_y(float );
protected:
private:
	CCRect screen;
	float ax;
	float ay;

	float F_x;
	float F_y; 
	float vector_ax;
	float vector_ay;

	//float vx;
	//float vy;
	//float last_vx;
	//float last_vy;
	//float a;
	//float time_move;
	~Rock();
};
#endif // !___ROCK__H_