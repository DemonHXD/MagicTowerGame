#include <iostream>
using namespace  std;


struct Hero
{
	//考虑数据类型的选择,结构体对齐
	char name[10];
	int lv;
	int hp;
	int Att;
	int Def;
	int posx;//当前位置的行坐标
	int posy;//当前位置的列坐标
	int OffSetX;//移动时行偏移量
	int OffSetY;//移动时列偏移量
	int Exp;//当前的经验值
	int Money;//金币
	int Key;//钥匙
};

struct Monster
{
	char name[10];
	int hp;
	int Att;
	int Def;
	int Exp;
};
int main()
{
	Hero hero = { "Jack",1,100,10,5,0,0,0,0,0,10,3};
	FILE * pFileHero = fopen("hero.txt", "wb");
	fwrite(&hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);
	//Monster Monkey = { "悟空",50,6,3,50 };
	//FILE * pFileMonkey = fopen("monster3.txt", "wb");
	//fwrite(&Monkey, sizeof(Monster), 1, pFileMonkey);
	//fclose(pFileMonkey);
	//Monster Wolf = { "雪狼",100,8,5,100 };
	//pFileMonkey = fopen("monster4.txt", "wb");
	//fwrite(&Wolf, sizeof(Monster), 1, pFileMonkey);
	//fclose(pFileMonkey);


	/*
		0表示空地
		1表示墙
		2表示人物

		3表示怪物
		4表示怪物 

		5表示门 
		6表示加防御力 
		7表示加攻击
		8表示加血上限
		9表示加经验

		10表示钥匙
		11表示宝物
		12表示上楼梯
		13表示下楼梯
	*/
	//int Map[13][13] = {
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	//	{1,12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	//	{1, 8, 0, 0, 5, 0, 1, 7,10, 0, 1, 0, 1},
	//	{1, 0, 4, 0, 1, 0, 1, 6, 8, 0, 1, 0, 1},
	//	{1, 1, 5, 1, 1, 0, 1, 1, 1, 5, 1, 0, 1},
	//	{1,10, 0, 0, 1, 0, 5, 3, 4, 3, 1, 0, 1},
	//	{1, 0, 4, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	//	{1, 1, 5, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	//	{1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 5, 1, 1},
	//	{1, 8, 0,10, 1, 0, 0, 0, 1, 0, 0, 0, 1},
	//	{1, 8,11,10, 1, 0, 2, 0, 1, 0, 0, 0, 1},
	//	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	//};
	//FILE * pFile = fopen("1.map", "wb");
	//fwrite(Map, sizeof(Map), 1, pFile);
	//fclose(pFile);



	/*
		动态地图的读写
	int Map[10][10]={
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
	};
	int RowSize=10;
	int ColSize=10;
	FILE * pFile=fopen("1.map","wb");
	fwrite(&RowSize,sizeof(int),1,pFile);
	fwrite(&ColSize,sizeof(int),1,pFile);
	fwrite(Map,sizeof(Map),1,pFile);
	fclose(pFile);

	int RowSize,ColSize;//定义一个二维数组行列的大小
	int **pMap;
	//从文件中读取数组的行列大小
	FILE * pFile=fopen("1.map","rb");
	fread(&RowSize,sizeof(int),1,pFile);
	fread(&ColSize,sizeof(int),1,pFile);
	fclose(pFile);
	//申请动态二维数组
	pMap=(int**)malloc(sizeof(int*)*RowSize);//申请一段连续内存，保存每一行的首地址
	for (int i=0;i<RowSize;i++)
	{
		pMap[i]=(int*)malloc(sizeof(int)*ColSize);//申请一段连续内存，保存每一行的元素
	}
	//从文件中读取数组的元素
	pFile=fopen("1.map","rb");
	fseek(pFile,sizeof(int)*2,SEEK_SET);//从文件开始回执偏移两个int型大小
	for (int i=0;i<RowSize;i++)
	{
		fread(pMap[i],sizeof(int),ColSize,pFile);
	}
	fclose(pFile);

	for (int i=0;i<10;i++)
	{
		for (int j=0;j<10;j++)
		{
			cout<<pMap[i][j];
		}
		cout<<endl;
	}*/
	return 0;
}