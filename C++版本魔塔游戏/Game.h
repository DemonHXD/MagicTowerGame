#pragma once
#include "Monster.h"
#include "Hero.h"
#include "Utils.h"
#include "Map.h"
#include <iostream>
using namespace std;
/*
	游戏类
*/
class Game
{
public:
	Game();
	~Game();
	void GameInit();								//初始化游戏
	//void PrintMap();								//打印地图
	bool Fight(int Kind);							//战斗
	void PrintFight(Monster monster);				//打印战斗属性
	void Run();										//游戏运行
	void Close();									//结束游戏
	void Save();									//存档
	void NewGame();									//开始新的游戏
	void ReadMemory();								//读档
	void Explation();								//游戏规则及按键说明
	void Choice();									//菜单选项
	void helpMenu();								//帮助菜单
	int  HeroMove();								//英雄移动
	void HeroMoveAndUpdate(int, int, int);			//英雄移动并更新位置
	void IntoNextLayer();							//进入下一层
private:
	Hero *hero = new Hero();						//英雄实例
	Map  *map  = new Map();
	//Map map = new Map();
	Utils *util = Utils::getInstance();
	//int Map[10][13][13];							//地图
	int layer;										//当前层数
};

