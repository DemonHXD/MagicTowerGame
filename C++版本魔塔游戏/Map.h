#include <iostream>
#include "Utils.h"
using namespace std;
#ifndef   _MAP_H
#define   _MAP_H
/*
	��ͼ��
*/
class Map
{
public:
	Map();
	~Map();
	void InitMap();							//��ʼ����ͼ
	void PrintMap(int currentLayer);		//��ӡ��ͼ
	void SaveMap();							//�ѵ�ͼд�뵽�ļ���
	void ReadMap();							//���ļ��ж�ȡ��ͼ
	int map[10][13][13];					//��ͼ����
	int mapCount;							//��ͼ����
private:
	Utils *util = Utils::getInstance();
};

#endif

