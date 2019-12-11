#pragma once
#include "Monster.h"
#include "Hero.h"
#include "Utils.h"
#include "Map.h"
#include <iostream>
using namespace std;
/*
	��Ϸ��
*/
class Game
{
public:
	Game();
	~Game();
	void GameInit();								//��ʼ����Ϸ
	//void PrintMap();								//��ӡ��ͼ
	bool Fight(int Kind);							//ս��
	void PrintFight(Monster monster);				//��ӡս������
	void Run();										//��Ϸ����
	void Close();									//������Ϸ
	void Save();									//�浵
	void NewGame();									//��ʼ�µ���Ϸ
	void ReadMemory();								//����
	void Explation();								//��Ϸ���򼰰���˵��
	void Choice();									//�˵�ѡ��
	void helpMenu();								//�����˵�
	int  HeroMove();								//Ӣ���ƶ�
	void HeroMoveAndUpdate(int, int, int);			//Ӣ���ƶ�������λ��
	void IntoNextLayer();							//������һ��
private:
	Hero *hero = new Hero();						//Ӣ��ʵ��
	Map  *map  = new Map();
	//Map map = new Map();
	Utils *util = Utils::getInstance();
	//int Map[10][13][13];							//��ͼ
	int layer;										//��ǰ����
};

