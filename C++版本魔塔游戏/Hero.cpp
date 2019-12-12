#include "Hero.h"

Hero::Hero()
{
}

Hero::Hero(string name, int lv, int hp, int att, int def,
	int posx, int posy, int offSetX, int offSetY, int exp, int money, int key) {
	m_name = name;
	m_lv = lv;
	m_hp = hp;
	m_att = att;
	m_def = def;
	m_posx = posx;
	m_posy = posy;
	m_offSetX = offSetX;
	m_offSetY = offSetY;
	m_exp = exp;
	m_money = money;
	m_key = key;
}


Hero::~Hero()
{
}


/*
	保存英雄属性
*/
void Hero::SaveHero(Hero *&hero) {
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);
}

/*
	读取英雄属性
*/
void Hero::ReadHero(Hero *&hero) {
	FILE * pFile = fopen("res/hero/hero.txt", "rb");
	fread(hero, sizeof(Hero), 1, pFile);
	fclose(pFile);
}

/*
	初始化英雄
*/
void Hero::InitHero() {
	//初始角色属性
	Hero *hero = new Hero("Jack", 1, 100, 10, 5, 0, 0, 0, 0, 0, 10, 3);
	//写入英雄属性到文件
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);
}

/*
	获取英雄当前的位置
*/
void Hero::GetHeroPosition(Map *&map, int layer) {
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (2 == map->map[layer][i][j])
			{
				m_posx = i;
				m_posy = j;
			}
		}
	}
}

/*
	打印英雄属性
*/
void Hero::PrintHero()
{
	util->Color(13);
	util->Gotoxy(10, 2);
	cout << "英雄姓名：" << m_name << endl;
	util->Gotoxy(10, 4);
	cout << "英雄等级：" << m_lv << endl;
	util->Gotoxy(10, 6);
	cout << "英雄攻击：" << m_att << endl;
	util->Gotoxy(10, 8);
	cout << "英雄防御：" << m_def << endl;
	util->Gotoxy(10, 10);
	cout << "英雄血量：" << m_hp << endl;
	util->Gotoxy(10, 12);
	cout << "英雄经验：" << m_exp << endl;
	util->Gotoxy(10, 14);
	cout << "包裹钥匙：" << m_key << endl;
	util->Gotoxy(10, 16);
	cout << "包裹金币：" << m_money << endl;

	util->Gotoxy(60, 2);
	cout << "战斗信息";
	util->Gotoxy(53, 4);
	cout << "角色";
	util->Gotoxy(59, 4);
	cout << "血量";
	util->Gotoxy(65, 4);
	cout << "攻击";
	util->Gotoxy(71, 4);
	cout << "防御";
}


/*
	升级
*/
void Hero::LvUp(int Exp)
{
	m_exp += Exp;
	while (m_exp >= m_lv * 10)// 判断经验是否足够升级
	{
		m_exp -= m_lv * 10;
		++m_lv;
		m_hp = m_lv * 100;
		//英雄的其他属性提升:
	}
}
