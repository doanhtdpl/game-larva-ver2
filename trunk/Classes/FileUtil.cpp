#include "FileUtil.h"
#include "BugFactory.h"
#include "RockFactory.h"

FileUtil* FileUtil::instance = NULL;

FileUtil::FileUtil(void)
{
	configs = CCDictionary::create();
}

FileUtil* FileUtil::getFileUtilInstance()
{
	if (instance == NULL)
	{
		instance = new FileUtil();
	}
	return instance;
}
FileUtil::~FileUtil(void)
{
}

vector<string> FileUtil::Split(string s, char key)
{
	vector<string> arr;
	string sTemp = "";
	int index = 0;
	while(index < s.length())
	{
		while(s[index] != key && index < s.length() && s[index] != ' ')
		{
			sTemp += s[index];
			index++;
		}
		if(sTemp.size() > 0)
			arr.push_back(sTemp);
		index++;
		sTemp.clear();
	}
	return arr;
}

CCDictionary* FileUtil::ReadCSV(char* fileName)
{
	CCDictionary* myMap = CCDictionary::create();
	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(fileName);
	unsigned long size = 0;
	char* pBuffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(path.c_str(), "rt", &size);
	std::stringstream ss(pBuffer);
	std::string line;
	std::getline(ss, line, '\n');
	while (std::getline(ss, line) && line[0] > 0) {
		vector<string> arr = Split(line,',');
		CCString* rowinfo = CCString::create(line);
		myMap->setObject(rowinfo,arr[0]);
	}
	configs->setObject(myMap,fileName);
	return myMap;
}

string FileUtil::ReadTXT(char* filename,char* bucket)
{
	std::string path = CCFileUtils::sharedFileUtils()->fullPathForFilename(filename);

	unsigned long size = 0;
	char* pBuffer = (char*)CCFileUtils::sharedFileUtils()->getFileData(path.c_str(), "rt", &size);

	std::stringstream ss(pBuffer);
	std::string line;
	while (std::getline(ss, line) && line[0] > 0) {
		vector<string> temp = Split(line,':');
		if(temp.at(0) == bucket)
		{
			return temp.at(1);
		}
	}
	return NULL;
}

void FileUtil::LoadCSV()
{
	ReadCSV(filebug);
	ReadCSV(fileimage);
	ReadCSV(filerock);
}

CCDictionary* FileUtil::getSelectedDictionary(char* filename)
{
	return  dynamic_cast<CCDictionary*>(configs->objectForKey(filename) );
}

CCDictionary* FileUtil::getImageDictionary()
{
	return getSelectedDictionary(fileimage);
}

CCDictionary* FileUtil::getBugDictionary()
{
	return getSelectedDictionary(filebug);
}

CCDictionary* FileUtil::getRockDictionary()
{
	return getSelectedDictionary(filerock);
}

CCDictionary* FileUtil::getItemDictionary()
{
	return getSelectedDictionary(fileitem);
}
vector<string> FileUtil::getInfoFromBucket(string bucket,CCDictionary* dic)
{
	string info = (dynamic_cast<CCString*>(dic->objectForKey(bucket)))->getCString();
	return this->Split(info,',');
	
}