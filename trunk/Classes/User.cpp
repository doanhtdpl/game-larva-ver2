#include "User.h"


User::User(void)
{
}

User::User(string name)
{
	this->name = name;
	score = 0;
	level = 1;
	bugsCatched =	CCDictionary::create();
	item		=	CCDictionary::create();
}

void User::CatchBug(Bug* bug)
{
	string x = bug->getId();
	if (bugsCatched->objectForKey(x) != NULL)
	{
		CCString* count = (CCString*)bugsCatched->valueForKey(x);
		int increase = count->floatValue() + 1;
		CCString* add = CCString::create(ConvertInt(increase));
		bugsCatched->setObject(add,x);
	}
	else
	{
		CCString* count = CCString::create("1");
		bugsCatched->setObject(count,x);
	}
}

string User::ConvertInt(int num)
{
	stringstream ss;//create a stringstream
	ss << num;//add number to the stream
	return ss.str();
}
void User::Save()
{
	CCFileUtils* fileUtils = CCFileUtils::sharedFileUtils();
	bugsCatched->writeToFile("BugsCatched.plist");
	item->writeToFile("Item.plist");
	string writablePath = fileUtils->getWritablePath() + "User.txt";
	FILE *fp = fopen(writablePath.c_str(), "w");
	string data = name + "\n" + ConvertInt(score) + "\n" + ConvertInt(level);
	fputs(data.c_str(), fp);
	fclose(fp);
}

void User::Load()
{
	if (CCFileUtils::sharedFileUtils()->isFileExist("BugsCatched.plist"))
	{
		bugsCatched = CCDictionary::createWithContentsOfFile("BugsCatched.plist");
		item = CCDictionary::createWithContentsOfFile("Item.plist");
		string path = CCFileUtils::sharedFileUtils()->getWritablePath() + "User.txt";
		unsigned long size = 0;
		char* pBuffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(path.c_str(), "rt", &size);
		stringstream ss(pBuffer);
		string line;
		getline(ss, line);
		name  = line;
		getline(ss, line);
		score = atoi(line.c_str());
		getline(ss, line);
		level = atoi(line.c_str());
	}
}
User::~User(void)
{
}
