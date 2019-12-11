#pragma once
/*
	怪兽类
*/
class Monster
{
public:
	Monster();
	~Monster();
	char m_name[10];		//名字
	int m_hp;				//血量
	int m_att;			//攻击
	int m_def;			//防御
	int m_exp;			//提供的经验
};

