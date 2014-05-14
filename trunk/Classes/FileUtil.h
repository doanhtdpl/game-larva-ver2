#ifndef __FILE_UTIL_
#define __FILE_UTIL_

#include "cocos2d.h"
#include "ObjFactory.h"
#include <map>
#include "Image.h"
using namespace std;
using namespace cocos2d;

#define filebug "Bug.csv"
#define filerock "Rock.csv"
#define fileimage "Image.csv"
#define fileitem "Item.csv"
class FileUtil
{

public:
	~FileUtil(void);
	static FileUtil* getFileUtilInstance();
	CCDictionary* getImageDictionary();
	CCDictionary* getBugDictionary();
	CCDictionary* getRockDictionary();
	CCDictionary* getItemDictionary();
	CCDictionary* ReadCSV(char* );
	string ReadTXT(char*,char* );
	vector<string> Split(string, char);
	vector<string> getInfoFromBucket(string,CCDictionary*);
	void LoadCSV();
private:
	FileUtil(void);
	static FileUtil* instance;
	CCDictionary *configs;
	CCDictionary* getSelectedDictionary(char*);
};

#endif