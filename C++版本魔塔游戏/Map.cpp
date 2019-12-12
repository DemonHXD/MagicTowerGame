#include "Map.h"
Map::Map()
{
	//��ͼ����Ϊ2
	mapCount = 2;
}


Map::~Map()
{
}

/*
	��ʼ����ͼ
*/
void Map::InitMap() {
	//д���ʼ��ͼ
	int map[][13][13] = {
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
			{1, 8, 0, 0, 5, 0, 1, 7,10, 0, 1, 0, 1},
			{1, 0, 4, 0, 1, 0, 1, 6, 8, 0, 1, 0, 1},
			{1, 1, 5, 1, 1, 0, 1, 1, 1, 5, 1, 0, 1},
			{1,10, 0, 0, 1, 0, 5, 3, 4, 3, 1, 0, 1},
			{1, 0, 4, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
			{1, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 5, 1, 1},
			{1, 8, 0,10, 1, 0, 0, 0, 1, 0, 0, 0, 1},
			{1, 8,11,10, 1, 0, 2, 0, 1, 0, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		},
		{
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			{1,13, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1},
			{1, 2, 0, 1, 1, 0, 4, 0, 4, 0, 1, 1, 1},
			{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1},
			{1, 0, 1,10,10, 1, 0, 0, 0, 1, 0,14, 1},
			{1, 0, 1,10, 0, 5, 0, 0, 0, 5, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 1,14, 0, 1, 0, 0, 0, 1, 0,14, 1},
			{1, 0, 1, 0, 0, 5, 0, 0, 0, 5, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
			{1, 0, 1, 9, 9, 1, 0, 0, 0, 1, 0, 0, 1},
			{1,12, 1, 9, 0, 5, 0, 0, 0, 5, 0, 0, 1},
			{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
		},
	};
	//д���ͼ���ļ�
	FILE * pFile = fopen("res/map/map.txt", "wb");
	fwrite(map, sizeof(map), 1, pFile);
	fclose(pFile);
}

/*
	�ѵ�ͼд�뵽�ļ���
*/
void Map::SaveMap() {
	FILE * pFile = fopen("res/map/map.txt", "wb");
	fwrite(map, sizeof(map), 1, pFile);
	fclose(pFile);
}

/*
	���ļ��ж�ȡ��ͼ
*/
void Map::ReadMap() {
	FILE * pFile = fopen("res/map/map.txt", "rb");
	fread(map, sizeof(map), 1, pFile);
	fclose(pFile);
}

/*
	��ӡ��ͼ
*/
void Map::PrintMap(int currentLayer)
{
	util->Color(13);
	for (int i = 0; i < 13; i++)
	{
		util->Gotoxy(26, i + 2);
		for (int j = 0; j < 13; j++)
		{
			switch (map[currentLayer][i][j])
			{
			case 0:
				cout << "  ";
				break;
			case 1:
				cout << "��";
				break;
			case 2:
				cout << "��";
				break;
			case 3:
			case 4:
				cout << "��";
				break;
			case 5:
				cout << "��";
				break;
			case 6:
				cout << "��";
				break;
			case 7:
				cout << "��";
				break;
			case 8:
				cout << "Ѫ";
				break;
			case 9:
				cout << "��";
				break;
			case 10:
				cout << "Կ";
				break;
			case 11:
				cout << "��";
				break;
			case 12:
				cout << "��";
				break;
			case 13:
				cout << "��";
				break;
			case 14:
				cout << "��";
				break;
			}
		}
		cout << endl;
	}
}
