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
	Config(int layer, string save[]);
	~Config();
	void ReadConfig(Config *&config);					//�������ļ���ȡ
	void WriteConfig(Config *&config);					//д�뵽�����ļ�
	void InitConfig();									//��ʼ������

	int m_layer;										//��ǰ����
	string m_save[3];									//�浵λ��Ϊ�ַ������飬�浵������Ϊ�浵ʱ��
};
#endif

