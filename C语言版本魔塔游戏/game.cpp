#include "game.h"
#include "game_ui.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>	 //为了读取方向键
#include <Windows.h> 
using namespace std;

/*
	1.登陆界面(开始游戏、结束游戏、读取回忆)
	2.胜利和失败界面。
	3.游戏背景介绍。
	4.游戏地图中有药瓶(不能携带)、钥匙(可以携带)、门。
	5.地图数量至少3张。
*/

/*
	打印地图

	0表示空地
	1表示墙
	2表示人物

	3表示怪物
	4表示怪物

	5表示门
	6表示加防御力
	7表示加攻击
	8表示加血上限
	9表示加经验

	10表示钥匙
	11表示宝物
	12表示上楼梯
	13表示下楼梯

	14表示npc
*/

//声明全局变量
extern int Map[10][13][13];
extern Hero *g_pHero;
int layer;

/*
	开始游戏
*/
void NewGame() {
	//初始角色属性
	Hero hero = { "Jack",1,100,10,5,0,0,0,0,0,10,3 };
	//写入英雄属性到文件
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(&hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//写入初始地图
	int map[10][13][13] = { 
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
			{1, 8, 0, 0, 5, 0, 1, 7,10, 0, 1, 0, 1},
			{1, 0, 4, 0, 1, 0, 1, 6, 8, 0, 1, 0, 1},
			{1, 1, 5, 1, 1, 0, 1, 1, 1, 5, 1, 0, 1},
			{1,10, 0, 0, 1, 0, 5, 3, 4, 3, 1, 0, 1},
			{1, 0, 4, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
			{1, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 5, 1, 1},
			{1, 8, 0,10, 1, 0, 0, 0, 1, 0, 0, 0, 1},
			{1, 8,11,10, 1, 0, 2, 0, 1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		},
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1,12, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 2, 0, 1, 1, 0, 4, 0, 4, 0, 1, 1, 1},
			{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
			{1, 0, 1,10,10, 1, 0, 0, 0, 1, 0,14, 1},
			{1, 0, 1,10, 0, 5, 0, 0, 0, 5, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 1,14, 0, 1, 0, 0, 0, 1, 0,14, 1},
			{1, 0, 1, 0, 0, 5, 0, 0, 0, 5, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 1, 9, 9, 1, 0, 0, 0, 1, 0, 0, 1},
			{1,13, 1, 9, 0, 5, 0, 0, 0, 5, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		},
	};
	//写入地图到文件
	FILE * pFile = fopen("res/map/1.map", "wb");
	fwrite(map, sizeof(map), 1, pFile);
	fclose(pFile);

	//写入游戏相关配置到文件
	layer = 0;
	FILE * pFileLayer = fopen("res/game/config.txt", "wb");
	//fprintf(pFileLayer, "%d", layer);
	fwrite(&layer, sizeof(int), 1, pFileLayer);
	fclose(pFileLayer);

	GameInit();
	GameRun();
}

/*
	游戏初始化
*/
void GameInit()
{
	//读取配置文件信息
	FILE * pFileLayer = fopen("res/game/config.txt", "rb");
	fread(&layer, 4, 1, pFileLayer);
	//fscanf(pFileLayer, "%d", &layer);
	fclose(pFileLayer);

	//读取地图数据
	FILE * pFile = fopen("res/map/1.map", "rb");
	fread(Map, sizeof(Map), 1, pFile);
	fclose(pFile);

	//读取英雄数据
	pFile = fopen("res/hero/hero.txt", "rb");
	fread(g_pHero, sizeof(Hero), 1, pFile);
	fclose(pFile);
	//遍历地图读取英雄的坐标
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (2 == Map[layer][i][j])
			{
				g_pHero->posx = i;
				g_pHero->posy = j;
			}
		}
	}
}


/*
	打印地图
*/
void PrintMap()
{
	Color(13);
	for (int i = 0; i < 13; i++)
	{
		Gotoxy(26, i+2);
		for (int j = 0; j < 13; j++)
		{
			switch (Map[layer][i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "■";
				break;
			case 2:
				cout << "♀";
				break;
			case 3:
			case 4:
				cout << "怪";
				break;
			case 5:
				cout << "门";
				break;
			case 6:
				cout << "防";
				break;
			case 7:
				cout << "攻";
				break;
			case 8:
				cout << "血";
				break;
			case 9:
				cout << "经";
				break;
			case 10:
				cout << "钥";
				break;
			case 11:
				cout << "宝";
				break;
			case 12:
				cout << "上";
				break;
			case 13:
				cout << "下";
				break;			
			case 14:
				cout << "人";
				break;
			}
		}
		cout << endl;
	}
	cout << layer;
}

/*
	打印英雄属性
*/
void PrintHero()
{
	Color(13);
	Gotoxy(10, 2);
	cout << "英雄姓名：" << g_pHero->name << endl;
	Gotoxy(10, 4);
	cout << "英雄等级：" << g_pHero->lv << endl;
	Gotoxy(10, 6);
	cout << "英雄攻击：" << g_pHero->Att << endl;
	Gotoxy(10, 8);
	cout << "英雄防御：" << g_pHero->Def << endl;
	Gotoxy(10, 10);
	cout << "英雄血量：" << g_pHero->hp << endl;
	Gotoxy(10, 12);
	cout << "英雄经验：" << g_pHero->Exp << endl;	
	Gotoxy(10, 14);
	cout << "包裹钥匙：" << g_pHero->Key << endl;
	Gotoxy(10, 16);
	cout << "包裹金币：" << g_pHero->Money << endl;

	Gotoxy(60, 2);
	cout << "战斗信息";
	Gotoxy(53, 4);
	cout << "角色";
	Gotoxy(59, 4);
	cout << "血量";
	Gotoxy(65, 4);
	cout << "攻击";
	Gotoxy(71, 4);
	cout << "防御";
}

/*
	打印战斗信息
*/
void PrintFight(Monster monster) {
	Color(13);
	//打印英雄的战斗数据
	Gotoxy(53, 6);
	cout << g_pHero->name;
	Gotoxy(59, 6);
	cout << g_pHero->hp;
	Gotoxy(65, 6);
	cout << g_pHero->Att;
	Gotoxy(71, 6);
	cout << g_pHero->Def;

	//打印怪物的战斗属性
	Gotoxy(53, 8);
	cout << monster.name;
	Gotoxy(59, 8);
	cout << monster.hp;
	Gotoxy(65, 8);
	cout << monster.Att;
	Gotoxy(71, 8);
	cout << monster.Def;
}

/*
	游戏存档
*/
void SaveGame() {

	Hero hero = { 
		"Jack",
		g_pHero->lv,
		g_pHero->hp,
		g_pHero->Att,
		g_pHero->Def,
		g_pHero->posx,
		g_pHero->posy,
		g_pHero->OffSetX,
		g_pHero->OffSetY,
		g_pHero->Exp,
		g_pHero->Money,
		g_pHero->Key};
	//保存英雄属性
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(&hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//保存地图
	FILE * pFile = fopen("res/map/1.map", "wb");
	fwrite(Map, sizeof(Map), 1, pFile);
	fclose(pFile);

	//写入游戏相关配置到文件
	FILE * pFileLayer = fopen("res/game/config.txt", "wb");
	//fprintf(pFileLayer, "%d", layer);
	fwrite(&layer, 4, 1, pFileLayer);
	fclose(pFileLayer);
}

/*
	英雄移动
*/
int  HeroMove()
{
	int Input = getch();
	//system("CLS");
	//flush(Input);
	fflush(stdin);//刷新输入缓存区
	g_pHero->OffSetX = g_pHero->OffSetY = 0;
	switch (Input)
	{
	case 's':
	case 'S':
		g_pHero->OffSetX += 1;
		break;
	case 'w':
	case 'W':
		g_pHero->OffSetX -= 1;
		break;
	case 'a':
	case 'A':
		g_pHero->OffSetY -= 1;
		break;
	case 'd':
	case 'D':
		g_pHero->OffSetY += 1;
		break;
	case '1':
		system("CLS");
		GameInit();//初始化游戏
		Choice();//进入主菜单
		break;
	case '2':
		SaveGame();
		Sleep(800);
		Gotoxy(26, 18);
		cout << "游戏进度保存成功!" << endl;
		Sleep(1500);
		system("CLS");
		break;
	}
	if (0 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY])
	{
		//修改地图数据
		Map[layer][g_pHero->posx][g_pHero->posy] -= 2;//人离开

		Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY] += 2;
		//修改人物坐标
		g_pHero->posx += g_pHero->OffSetX;
		g_pHero->posy += g_pHero->OffSetY;

	}
	else if (3 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY] || 4 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY])
	{
		return Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY];
	}
	else if (5 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY])
	{//碰到是门的情况
		if (g_pHero->Key > 0) {
			g_pHero->Key -= 1;
			HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 5);
		}
	}
	else if (8 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//碰到加血的情况
		g_pHero->hp += 400;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 8);
	}
	else if (6 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//碰到加防御的情况
		g_pHero->Def += 4;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 6);
	}
	else if (7 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//碰到加攻击的情况
		g_pHero->Att += 4;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 7);
	}
	else if (10 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//碰到钥匙的情况
		g_pHero->Key += 1;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 10);
	}
	else if (12 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//碰到上楼梯的情况
		layer++;
		SaveGame();
		//重新初始化一下主角的位置
		GameInit();
	}	
	else if (13 == Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//碰到下楼梯的情况
		layer--;
		SaveGame();
		//重新初始化一下主角的位置
		GameInit();
	}
	return 0;
}

/*
	英雄移动并更新位置
*/
void HeroMoveAndUpdate(int OffSetX, int OffSetY, int move) {
	Map[layer][g_pHero->posx][g_pHero->posy] -= 2;//人离开
	Map[layer][g_pHero->posx + OffSetX][g_pHero->posy + OffSetY] += 2 - move;
	//修改人物坐标
	g_pHero->posx += OffSetX;
	g_pHero->posy += OffSetY;
}

/*
	战斗
*/
bool Fight(int Kind)
{
	// 创建怪物
	Monster monster;
	//解析路径
	char path[50] = "res/monster/monster";
	char Numchar[4];
	//把数字转换成字符串
	itoa(Kind, Numchar, 10);
	char temp[10] = ".txt";
	strcat(strcat(path, Numchar), temp);
	//从文件中读取怪物的数据
	FILE* pFile = fopen(path, "rb");
	fread(&monster, sizeof(Monster), 1, pFile);
	fclose(pFile);
	//自动战斗
	while (true)
	{
		if (g_pHero->hp > 0 && monster.hp > 0) {

		
		//判断英雄血量>0
		if (g_pHero->hp > 0)
		{
			if (g_pHero->Att > monster.Def)//判断英雄的攻击>怪物的防御力
			{
				monster.hp -= g_pHero->Att - monster.Def;

			}
			else
			{
				monster.hp -= 1;
			}
		}
		else
			return false;//失败
		if (monster.hp > 0)
		{

			if (monster.Att > g_pHero->Def)//判断英雄的攻击>怪物的防御力
			{
				g_pHero->hp -= monster.Att - g_pHero->Def;

			}
			else
			{
				g_pHero->hp -= 1;
			}
		}
		else
		{
			//修改地图数据
			Map[layer][g_pHero->posx][g_pHero->posy] = 0;//英雄原来的位置设置为0
			//怪物所在的位置设置2.
			Map[layer][g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY] = 2;
			g_pHero->posx += g_pHero->OffSetX;
			g_pHero->posy += g_pHero->OffSetY;
			//调用升级函数:
			LvUp(monster.Exp);
			system("CLS");
			return true;//胜利
		}
		PrintFight(monster);
		_sleep(1000);
		}
		else {
			break;
		}
		
		
		//Sleep(1000);
	}
	
}

/*
	升级
*/
void LvUp(int Exp)
{
	g_pHero->Exp += Exp;

	while (g_pHero->Exp >= g_pHero->lv * 10)// 判断经验是否足够升级
	{
		g_pHero->Exp -= g_pHero->lv * 10;
		++g_pHero->lv;
		g_pHero->hp = g_pHero->lv * 100;
		//英雄的其他属性提升:
	}
}

/*
	运行游戏
*/
void GameRun()
{
	GameInit();
	system("CLS");
	while (1)
	{
		//打印英雄属性
		PrintHero();
		//打印地图
		PrintMap();
		//帮助菜单
		helpMenu();
		int Kind = HeroMove();
		if (3 == Kind || 4 == Kind)
		{
			Fight(Kind);
		}
	}
}

/*
	结束游戏
*/
void Close() {
	system("exit");
}

/*
	读取回忆
*/
void ReadMemory() {
	GameRun();
}

/*
	游戏规则及按键说明
*/
void Explation() {

}