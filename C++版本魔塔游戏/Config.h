#ifndef   _CONFIG_H
#define   _CONFIG_H
#include <string>
#include <iostream>
using namespace std;
/*
	����������
*/
class Config
{
public:
	Config();
	Config(int layer);
	~Config();
	void ReadConfig();				//�������ļ���ȡ
	void WriteConfig();				//д�뵽�����ļ�
	
	int m_layer;					//��ǰ����
	string m_save[3] = {"�浵һ", "�浵��", "�浵��"};	//�浵λ��Ϊ�ַ������飬�浵������Ϊ�浵ʱ��
	//int 
};
#endif

