#ifndef _GAME_H
#define _GAME_H

//Ӣ������
struct Hero
{
	//�����������͵�ѡ��,�ṹ�����
	char name[10];
	int lv;
	int hp;
	int Att;
	int Def;
	int posx;//��ǰλ�õ�������
	int posy;//��ǰλ�õ�������
	int OffSetX;//�ƶ�ʱ��ƫ����
	int OffSetY;//�ƶ�ʱ��ƫ����
	int Exp;//��ǰ�ľ���ֵ
	int Money;//���
	int Key;//Կ��
};

//��������
struct Monster
{
	char name[10];
	int hp;
	int Att;
	int Def;
	int Exp;
};

//��Ϸ��ʼ��
void GameInit();

//��ӡ��ͼ
void PrintMap();

//Ӣ���ƶ�
int  HeroMove();

//Ӣ���ƶ�������λ��
void HeroMoveAndUpdate(int OffSetX, int OffSetY, int move);

//ս��
bool Fight(int Kind);

//��ӡս����Ϣ
void PrintFight(Monster monster);

//��ӡӢ������
void PrintHero();

//����
void LvUp(int Exp);

//��Ϸ����
void GameRun();

//������Ϸ
void Close();

//�浵
void SaveGame();

//�µ���Ϸ
void NewGame();

//��ȡ����
void ReadMemory();

//��Ϸ���򼰰���˵��
void Explation();

#endif 



