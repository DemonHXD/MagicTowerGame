#ifndef   _CONFIG_H
#define   _CONFIG_H
#include <string>
#include <iostream>
using namespace std;
/*
	参数配置类
*/
class Config
{
public:
	Config();
	Config(int layer);
	~Config();
	void ReadConfig();				//从配置文件读取
	void WriteConfig();				//写入到配置文件
	
	int m_layer;					//当前层数
	string m_save[3] = {"存档一", "存档二", "存档三"};	//存档位置为字符串数组，存档后内容为存档时间
	//int 
};
#endif

