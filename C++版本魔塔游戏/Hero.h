#pragma 
#include "Utils.h"
#include <iostream>
#include <string>
using namespace std;
/*
	英雄类
*/

class Hero
{
public:
	Hero();
	~Hero();
	Hero(string name, int lv, int hp, int att, int def,
		int posx, int posy, int offSetX, int offSetY, int exp, int money, int key);
	void PrintHero();						//打印英雄属性
	void LvUp(int Exp);						//升级
	string m_name;
	int m_lv;				//等级
	int m_hp;				//血量
	int m_att;				//攻击
	int m_def;				//防御
	int m_posx;				//当前位置的行坐标
	int m_posy;				//当前位置的列坐标
	int m_offSetX;			//移动时行偏移量
	int m_offSetY;			//移动时列偏移量
	int m_exp;				//当前的经验值
	int m_money;			//金币
	int m_key;				//钥匙数量
private:
	Utils *util = Utils::getInstance();
};

