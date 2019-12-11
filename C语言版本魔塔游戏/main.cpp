#include<iostream>
#include "game.h"
#include "game_ui.h"
using namespace std;

//定义一个二维数组存储地图数据
int Map[10][13][13];
Hero *g_pHero;
int main()
{
	g_pHero = (Hero*)malloc(sizeof(Hero));

	
	Choice();

	return 0;
}