#ifndef _GAME_H
#define _GAME_H

//英雄属性
struct Hero
{
	//考虑数据类型的选择,结构体对齐
	char name[10];
	int lv;
	int hp;
	int Att;
	int Def;
	int posx;//当前位置的行坐标
	int posy;//当前位置的列坐标
	int OffSetX;//移动时行偏移量
	int OffSetY;//移动时列偏移量
	int Exp;//当前的经验值
	int Money;//金币
	int Key;//钥匙
};

//怪物属性
struct Monster
{
	char name[10];
	int hp;
	int Att;
	int Def;
	int Exp;
};

//游戏初始化
void GameInit();

//打印地图
void PrintMap();

//英雄移动
int  HeroMove();

//英雄移动并更新位置
void HeroMoveAndUpdate(int OffSetX, int OffSetY, int move);

//战斗
bool Fight(int Kind);

//打印战斗信息
void PrintFight(Monster monster);

//打印英雄属性
void PrintHero();

//升级
void LvUp(int Exp);

//游戏运行
void GameRun();

//结束游戏
void Close();

//存档
void SaveGame();

//新的游戏
void NewGame();

//读取回忆
void ReadMemory();

//游戏规则及按键说明
void Explation();

#endif 



