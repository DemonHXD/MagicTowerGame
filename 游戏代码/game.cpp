#include "game.h"
#include "game_ui.h"
#include <iostream>
#include <stdio.h>
#include <conio.h>	 //Ϊ�˶�ȡ�����
#include <Windows.h> 
using namespace std;

/*
	1.��½����(��ʼ��Ϸ��������Ϸ����ȡ����)
	2.ʤ����ʧ�ܽ��档
	3.��Ϸ�������ܡ�
	4.��Ϸ��ͼ����ҩƿ(����Я��)��Կ��(����Я��)���š�
	5.��ͼ��������3�š�
*/

//����ȫ�ֱ���
extern int Map[13][13];
extern Hero *g_pHero;

void NewGame() {
	//д���ʼ��ɫ����
	Hero hero = { "Jack",1,100,10,5,0,0,0,0,0,10,3 };
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(&hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//д���ʼ��ͼ
	int map[13][13] = {
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
	};
	FILE * pFile = fopen("res/map/1.map", "wb");
	fwrite(map, sizeof(map), 1, pFile);
	fclose(pFile);

	GameInit();
	GameRun();
}

/*
	��Ϸ��ʼ��
*/
void GameInit()
{
	//��ȡ��ͼ����
	FILE * pFile = fopen("res/map/1.map", "rb");
	fread(Map, sizeof(Map), 1, pFile);
	fclose(pFile);
	//��ȡӢ������
	pFile = fopen("res/hero/hero.txt", "rb");
	fread(g_pHero, sizeof(Hero), 1, pFile);
	fclose(pFile);
	//������ͼ��ȡӢ�۵�����
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (2 == Map[i][j])
			{
				g_pHero->posx = i;
				g_pHero->posy = j;
			}
		}
	}
}

/*
	��ӡ��ͼ

	0��ʾ�յ�
	1��ʾǽ
	2��ʾ����

	3��ʾ����
	4��ʾ����

	5��ʾ��
	6��ʾ�ӷ�����
	7��ʾ�ӹ���
	8��ʾ��Ѫ����
	9��ʾ�Ӿ���

	10��ʾԿ��
	11��ʾ����
	12��ʾ��¥��
	13��ʾ��¥��
*/
void PrintMap()
{
	Color(13);
	for (int i = 0; i < 13; i++)
	{
		Gotoxy(26, i+2);
		for (int j = 0; j < 13; j++)
		{
			switch (Map[i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "��";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "Ѫ";
				break;
			case 9:
				cout << "��";
				break;
			case 10:
				cout << "Կ";
				break;
			case 11:
				cout << "��";
				break;
			case 12:
				cout << "��";
				break;
			case 13:
				cout << "��";
				break;
			}
		}
		cout << endl;
	}

}

/*
	��ӡӢ������
*/
void PrintHero()
{
	Color(13);
	Gotoxy(10, 2);
	cout << "Ӣ��������" << g_pHero->name << endl;
	Gotoxy(10, 4);
	cout << "Ӣ�۵ȼ���" << g_pHero->lv << endl;
	Gotoxy(10, 6);
	cout << "Ӣ�۹�����" << g_pHero->Att << endl;
	Gotoxy(10, 8);
	cout << "Ӣ�۷�����" << g_pHero->Def << endl;
	Gotoxy(10, 10);
	cout << "Ӣ��Ѫ����" << g_pHero->hp << endl;
	Gotoxy(10, 12);
	cout << "Ӣ�۾��飺" << g_pHero->Exp << endl;	
	Gotoxy(10, 14);
	cout << "����Կ�ף�" << g_pHero->Key << endl;
	Gotoxy(10, 16);
	cout << "������ң�" << g_pHero->Money << endl;

	Gotoxy(60, 2);
	cout << "ս����Ϣ";
	Gotoxy(53, 4);
	cout << "��ɫ";
	Gotoxy(59, 4);
	cout << "Ѫ��";
	Gotoxy(65, 4);
	cout << "����";
	Gotoxy(71, 4);
	cout << "����";
}

/*
	��ӡս����Ϣ
*/
void PrintFight(Monster monster) {
	Color(13);
	//��ӡӢ�۵�ս������
	Gotoxy(53, 6);
	cout << g_pHero->name;
	Gotoxy(59, 6);
	cout << g_pHero->hp;
	Gotoxy(65, 6);
	cout << g_pHero->Att;
	Gotoxy(71, 6);
	cout << g_pHero->Def;

	//��ӡ�����ս������
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
	��Ϸ�浵
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
	//����Ӣ������
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(&hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//�����ͼ
	FILE * pFile = fopen("res/map/1.map", "wb");
	fwrite(Map, sizeof(Map), 1, pFile);
	fclose(pFile);

	Sleep(800);
	Gotoxy(26, 18);
	cout << "��Ϸ���ȱ���ɹ�!" << endl;
	Sleep(1500);
	system("CLS");
}

/*
	Ӣ���ƶ�
*/
int  HeroMove()
{
	int Input = getch();
	//system("CLS");
	//flush(Input);
	fflush(stdin);//ˢ�����뻺����
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
		GameInit();//��ʼ����Ϸ
		Choice();//�������˵�
		break;
	case '2':
		SaveGame();
		break;
	}
	if (0 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY])
	{
		//�޸ĵ�ͼ����
		Map[g_pHero->posx][g_pHero->posy] -= 2;//���뿪

		Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY] += 2;
		//�޸���������
		g_pHero->posx += g_pHero->OffSetX;
		g_pHero->posy += g_pHero->OffSetY;

	}
	else if (3 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY] || 4 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY])
	{
		return Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY];
	}
	else if (5 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY])
	{//�������ŵ����
		if (g_pHero->Key > 0) {
			g_pHero->Key -= 1;
			HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 5);
		}
	}
	else if (8 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//������Ѫ�����
		g_pHero->hp += 400;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 8);
	}
	else if (6 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//�����ӷ��������
		g_pHero->Def += 4;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 6);
	}
	else if (7 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//�����ӹ��������
		g_pHero->Att += 4;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 7);
	}
	else if (10 == Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY]) {
		//����Կ�׵����
		g_pHero->Key += 1;
		HeroMoveAndUpdate(g_pHero->OffSetX, g_pHero->OffSetY, 10);
	}
	return 0;
}

/*
	Ӣ���ƶ�������λ��
*/
void HeroMoveAndUpdate(int OffSetX, int OffSetY, int move) {
	Map[g_pHero->posx][g_pHero->posy] -= 2;//���뿪
	Map[g_pHero->posx + OffSetX][g_pHero->posy + OffSetY] += 2 - move;
	//�޸���������
	g_pHero->posx += OffSetX;
	g_pHero->posy += OffSetY;
}

/*
	ս��
*/
bool Fight(int Kind)
{
	// ��������
	Monster monster;
	//����·��
	char path[50] = "res/monster/monster";
	char Numchar[4];
	//������ת�����ַ���
	itoa(Kind, Numchar, 10);
	char temp[10] = ".txt";
	strcat(strcat(path, Numchar), temp);
	//���ļ��ж�ȡ���������
	FILE* pFile = fopen(path, "rb");
	fread(&monster, sizeof(Monster), 1, pFile);
	fclose(pFile);
	//�Զ�ս��
	while (true)
	{
		if (g_pHero->hp > 0 && monster.hp > 0) {

		
		//�ж�Ӣ��Ѫ��>0
		if (g_pHero->hp > 0)
		{
			if (g_pHero->Att > monster.Def)//�ж�Ӣ�۵Ĺ���>����ķ�����
			{
				monster.hp -= g_pHero->Att - monster.Def;

			}
			else
			{
				monster.hp -= 1;
			}
		}
		else
			return false;//ʧ��
		if (monster.hp > 0)
		{

			if (monster.Att > g_pHero->Def)//�ж�Ӣ�۵Ĺ���>����ķ�����
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
			//�޸ĵ�ͼ����
			Map[g_pHero->posx][g_pHero->posy] = 0;//Ӣ��ԭ����λ������Ϊ0
			//�������ڵ�λ������2.
			Map[g_pHero->posx + g_pHero->OffSetX][g_pHero->posy + g_pHero->OffSetY] = 2;
			g_pHero->posx += g_pHero->OffSetX;
			g_pHero->posy += g_pHero->OffSetY;
			//������������:
			LvUp(monster.Exp);
			system("CLS");
			return true;//ʤ��
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
	����
*/
void LvUp(int Exp)
{
	g_pHero->Exp += Exp;

	while (g_pHero->Exp >= g_pHero->lv * 10)// �жϾ����Ƿ��㹻����
	{
		g_pHero->Exp -= g_pHero->lv * 10;
		++g_pHero->lv;
		g_pHero->hp = g_pHero->lv * 100;
		//Ӣ�۵�������������:
	}
}

/*
	������Ϸ
*/
void GameRun()
{
	GameInit();
	system("CLS");
	while (1)
	{
		//��ӡӢ������
		PrintHero();
		//��ӡ��ͼ
		PrintMap();
		//�����˵�
		helpMenu();
		int Kind = HeroMove();
		if (3 == Kind || 4 == Kind)
		{
			Fight(Kind);
		}
	}
}

/*
	������Ϸ
*/
void Close() {
	system("exit");
}

/*
	��ȡ����
*/
void ReadMemory() {
	GameRun();
}

/*
	��Ϸ���򼰰���˵��
*/
void Explation() {

}