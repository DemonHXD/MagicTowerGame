#include <iostream>
#include "Utils.h"
using namespace std;
#ifndef   _MAP_H
#define   _MAP_H
/*
	地图类
*/
class Map
{
public:
	Map();
	~Map();
	void InitMap();							//初始化地图
	void PrintMap(int currentLayer);		//打印地图
	void SaveMap();							//把地图写入到文件中
	void ReadMap();							//从文件中读取地图
	int map[10][13][13];					//地图数组
	int mapCount;							//地图数量
private:
	Utils *util = Utils::getInstance();
};

#endif

