#ifndef __USER_H_
#define __USER_H_

#include <string>
#include <cocos2d.h>
#include "Bug.h"
using namespace std;
using namespace cocos2d;
class User
{
private:
	string name;
	int score;
	int level;
	CCDictionary* bugsCatched;
	CCDictionary* item;
	
public:
	User(void );
	User(string);
	void CatchBug(Bug*);
	void GetItem();
	void Save();
	void Load();
	string ConvertInt(int);
	~User(void);
};


#endif // ifndef

