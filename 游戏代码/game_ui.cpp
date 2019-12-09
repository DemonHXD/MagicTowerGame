#include "game_ui.h"
#include "game.h"
#include <conio.h>	 //为了读取方向键
#include <time.h>
#include <Windows.h> //控制dos界面（获取控制台上坐标位置、设置字体颜色）
#include <iostream>
using namespace std;

/*
	获取屏幕光标位置
*/
void Gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*
	文字颜色函数
*/
int Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);  
	return 0;
}

/*
	菜单选项
 */
void Choice() {
	Rabbit();
	int n;
	int i, j = 1;
	Gotoxy(32, 2);
	Color(13);
	printf(" 魔 塔 2 0 1 9 ");
	Color(14);          			//黄色边框
	for (i = 3; i <= 14; i++)   	//输出上下边框===
	{
		for (j = 15; j <= 60; j++)  //输出左右边框||
		{
			Gotoxy(j, i);
			if (i == 3 || i == 14) printf("=");
			else if (j == 15 || j == 59) printf("||");
		}
	}

	Color(12);
	Gotoxy(25, 6);
	printf("1.游戏开始");
	Gotoxy(40, 6);
	printf("2.读取回忆");
	Gotoxy(25, 10);
	printf("3.游戏规则");
	Gotoxy(40, 10);
	printf("4.结束游戏");
	Gotoxy(21, 16);
	Color(5);
	printf("请选择[1 2 3 4]:[ ]\b\b");
	scanf("%d", &n);    //输入选项
	switch (n)
	{
	case 1:
		GameRun();          //游戏开始
		//NewGame();
		//ReadMemory();
		break;
	case 2:
		ReadMemory();      	//读取回忆
		break;
	case 3:
		Explation();     	//游戏规则及按键说明
		break;
	case 4:
		Close();    		//结束游戏
		break;
	}
}

/*
	帮助菜单
*/
void helpMenu() {
	Color(3);
	Gotoxy(26, 16);
	cout << "[1]回到主菜单";

	Gotoxy(40, 16);
	cout << "[2]存档";
}

/**
* 绘制小狗
*/
void Rabbit()
{
	Color(3);
	Gotoxy(64, 4);
	printf("┏-┓  ┏-┓");
	Gotoxy(64, 5);
	printf("┃ ┃  ┃ ┃");
	Gotoxy(64, 6);
	printf("┃ ┃  ┃ ┃");
	Gotoxy(63, 7);
	printf("_┃");
	Gotoxy(74, 7);
	printf("┃_");
	Gotoxy(62, 8);
	printf("┃");
	Gotoxy(76, 8);
	printf("┃");
	Gotoxy(62, 9);
	printf("┃            ┃");
	Gotoxy(62, 10);
	printf("┃");
	Gotoxy(76, 10);
	printf("┃");
	Gotoxy(62, 11);
	printf("┃            ┃");
	Gotoxy(62, 12);
	printf("┗━┳━━┳━┛");
	Gotoxy(64, 13);
	printf("┏┫    ┣┓");
	Gotoxy(62, 14);
	printf("—┺┻━┻┻┹—");
	Color(5);
	Gotoxy(67, 7);
	printf("`~ ＇~`");
	Color(4);
	Gotoxy(67, 8);
	printf("○   ○");
	Color(13);
	Gotoxy(65, 9);
	printf("〃");
	Gotoxy(74, 9);
	printf("〃");
	Color(12);
	Gotoxy(69, 11);
	printf("┻");


}