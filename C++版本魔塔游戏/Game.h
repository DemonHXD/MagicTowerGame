#ifndef   _GAME_H
#define   _GAME_H
#include <iostream>
#include "Monster.h"
#include "Hero.h"
#include "Utils.h"
#include "Map.h"
#include "Config.h"
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
	void PrintSystemInfo();							//��ӡϵͳ��Ϣ
	void SaveGameSelect(int select);				//ѡ��浵
	void ShowSaveGame();							//�鿴�浵
private:
	Hero *hero = new Hero();						//Ӣ��
	Map  *map  = new Map();							//��ͼ
	Utils *util = Utils::getInstance();				//ʵ����ʵ��	
	Config *config = new Config(0);					//������Ϣ	��ʼ������Ϊ0
	string msg = "";
};		
#endif

