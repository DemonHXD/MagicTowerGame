#include "Map.h"
Map::Map()
{
	//地图数量为2
	mapCount = 2;
}


Map::~Map()
{
}

/*
	初始化地图
*/
void Map::InitMap() {
	//写入初始地图
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
	//写入地图到文件
	FILE * pFile = fopen("res/map/map.txt", "wb");
	fwrite(map, sizeof(map), 1, pFile);
	fclose(pFile);
}

/*
	把地图写入到文件中
*/
void Map::SaveMap() {
	FILE * pFile = fopen("res/map/map.txt", "wb");
	fwrite(map, sizeof(map), 1, pFile);
	fclose(pFile);
}

/*
	从文件中读取地图
*/
void Map::ReadMap() {
	FILE * pFile = fopen("res/map/map.txt", "rb");
	fread(map, sizeof(map), 1, pFile);
	fclose(pFile);
}

/*
	打印地图
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
				cout << "■";
				break;
			case 2:
				cout << "♀";
				break;
			case 3:
			case 4:
				cout << "怪";
				break;
			case 5:
				cout << "门";
				break;
			case 6:
				cout << "防";
				break;
			case 7:
				cout << "攻";
				break;
			case 8:
				cout << "血";
				break;
			case 9:
				cout << "经";
				break;
			case 10:
				cout << "钥";
				break;
			case 11:
				cout << "宝";
				break;
			case 12:
				cout << "上";
				break;
			case 13:
				cout << "下";
				break;
			case 14:
				cout << "人";
				break;
			}
		}
		cout << endl;
	}
}
