#include<iostream>
#include "game.h"
#include "game_ui.h"
using namespace std;

//����һ����ά����洢��ͼ����
int Map[13][13];
Hero *g_pHero;
int main()
{
	g_pHero = (Hero*)malloc(sizeof(Hero));

	GameInit();
	Choice();

	return 0;
}