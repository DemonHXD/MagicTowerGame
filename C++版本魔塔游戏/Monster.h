#ifndef   _MONSTER_H
#define   _MONSTER_H
/*
	������
*/
class Monster
{
public:
	Monster();
	~Monster();
	char m_name[10];		//����
	int m_hp;				//Ѫ��
	int m_att;			//����
	int m_def;			//����
	int m_exp;			//�ṩ�ľ���
};
#endif

