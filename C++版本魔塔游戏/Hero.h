#pragma 
#include "Utils.h"
#include <iostream>
#include <string>
using namespace std;
/*
	Ӣ����
*/

class Hero
{
public:
	Hero();
	~Hero();
	Hero(string name, int lv, int hp, int att, int def,
		int posx, int posy, int offSetX, int offSetY, int exp, int money, int key);
	void PrintHero();						//��ӡӢ������
	void LvUp(int Exp);						//����
	string m_name;
	int m_lv;				//�ȼ�
	int m_hp;				//Ѫ��
	int m_att;				//����
	int m_def;				//����
	int m_posx;				//��ǰλ�õ�������
	int m_posy;				//��ǰλ�õ�������
	int m_offSetX;			//�ƶ�ʱ��ƫ����
	int m_offSetY;			//�ƶ�ʱ��ƫ����
	int m_exp;				//��ǰ�ľ���ֵ
	int m_money;			//���
	int m_key;				//Կ������
private:
	Utils *util = Utils::getInstance();
};

