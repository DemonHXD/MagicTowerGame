#include "game_ui.h"
#include "game.h"
#include <conio.h>	 //Ϊ�˶�ȡ�����
#include <time.h>
#include <Windows.h> //����dos���棨��ȡ����̨������λ�á�����������ɫ��
#include <iostream>
using namespace std;

/*
	��ȡ��Ļ���λ��
*/
void Gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*
	������ɫ����
*/
int Color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);  
	return 0;
}

/*
	�˵�ѡ��
 */
void Choice() {
	Rabbit();
	int n;
	int i, j = 1;
	Gotoxy(32, 2);
	Color(13);
	printf(" ħ �� 2 0 1 9 ");
	Color(14);          			//��ɫ�߿�
	for (i = 3; i <= 14; i++)   	//������±߿�===
	{
		for (j = 15; j <= 60; j++)  //������ұ߿�||
		{
			Gotoxy(j, i);
			if (i == 3 || i == 14) printf("=");
			else if (j == 15 || j == 59) printf("||");
		}
	}

	Color(12);
	Gotoxy(25, 6);
	printf("1.��Ϸ��ʼ");
	Gotoxy(40, 6);
	printf("2.��ȡ����");
	Gotoxy(25, 10);
	printf("3.��Ϸ����");
	Gotoxy(40, 10);
	printf("4.������Ϸ");
	Gotoxy(21, 16);
	Color(5);
	printf("��ѡ��[1 2 3 4]:[ ]\b\b");
	scanf("%d", &n);    //����ѡ��
	switch (n)
	{
	case 1:
		GameRun();          //��Ϸ��ʼ
		//NewGame();
		//ReadMemory();
		break;
	case 2:
		ReadMemory();      	//��ȡ����
		break;
	case 3:
		Explation();     	//��Ϸ���򼰰���˵��
		break;
	case 4:
		Close();    		//������Ϸ
		break;
	}
}

/*
	�����˵�
*/
void helpMenu() {
	Color(3);
	Gotoxy(26, 16);
	cout << "[1]�ص����˵�";

	Gotoxy(40, 16);
	cout << "[2]�浵";
}

/**
* ����С��
*/
void Rabbit()
{
	Color(3);
	Gotoxy(64, 4);
	printf("��-��  ��-��");
	Gotoxy(64, 5);
	printf("�� ��  �� ��");
	Gotoxy(64, 6);
	printf("�� ��  �� ��");
	Gotoxy(63, 7);
	printf("_��");
	Gotoxy(74, 7);
	printf("��_");
	Gotoxy(62, 8);
	printf("��");
	Gotoxy(76, 8);
	printf("��");
	Gotoxy(62, 9);
	printf("��            ��");
	Gotoxy(62, 10);
	printf("��");
	Gotoxy(76, 10);
	printf("��");
	Gotoxy(62, 11);
	printf("��            ��");
	Gotoxy(62, 12);
	printf("�����ש����ש���");
	Gotoxy(64, 13);
	printf("����    �ǩ�");
	Gotoxy(62, 14);
	printf("���ީߩ��ߩߩݡ�");
	Color(5);
	Gotoxy(67, 7);
	printf("`~ ��~`");
	Color(4);
	Gotoxy(67, 8);
	printf("��   ��");
	Color(13);
	Gotoxy(65, 9);
	printf("��");
	Gotoxy(74, 9);
	printf("��");
	Color(12);
	Gotoxy(69, 11);
	printf("��");


}