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
	Config(int layer, string save[]);
	~Config();
	void ReadConfig(Config *&config);					//从配置文件读取
	void WriteConfig(Config *&config);					//写入到配置文件
	void InitConfig();									//初始化配置

	int m_layer;										//当前层数
	string m_save[3];									//存档位置为字符串数组，存档后内容为存档时间
};
#endif

