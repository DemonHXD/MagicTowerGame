#include <iostream>
using namespace  std;


struct Hero
{
	//�����������͵�ѡ��,�ṹ�����
	char name[10];
	int lv;
	int hp;
	int Att;
	int Def;
	int posx;//��ǰλ�õ�������
	int posy;//��ǰλ�õ�������
	int OffSetX;//�ƶ�ʱ��ƫ����
	int OffSetY;//�ƶ�ʱ��ƫ����
	int Exp;//��ǰ�ľ���ֵ
	int Money;//���
	int Key;//Կ��
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
	//Monster Monkey = { "���",50,6,3,50 };
	//FILE * pFileMonkey = fopen("monster3.txt", "wb");
	//fwrite(&Monkey, sizeof(Monster), 1, pFileMonkey);
	//fclose(pFileMonkey);
	//Monster Wolf = { "ѩ��",100,8,5,100 };
	//pFileMonkey = fopen("monster4.txt", "wb");
	//fwrite(&Wolf, sizeof(Monster), 1, pFileMonkey);
	//fclose(pFileMonkey);


	/*
		0��ʾ�յ�
		1��ʾǽ
		2��ʾ����

		3��ʾ����
		4��ʾ���� 

		5��ʾ�� 
		6��ʾ�ӷ����� 
		7��ʾ�ӹ���
		8��ʾ��Ѫ����
		9��ʾ�Ӿ���

		10��ʾԿ��
		11��ʾ����
		12��ʾ��¥��
		13��ʾ��¥��
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
		��̬��ͼ�Ķ�д
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

	int RowSize,ColSize;//����һ����ά�������еĴ�С
	int **pMap;
	//���ļ��ж�ȡ��������д�С
	FILE * pFile=fopen("1.map","rb");
	fread(&RowSize,sizeof(int),1,pFile);
	fread(&ColSize,sizeof(int),1,pFile);
	fclose(pFile);
	//���붯̬��ά����
	pMap=(int**)malloc(sizeof(int*)*RowSize);//����һ�������ڴ棬����ÿһ�е��׵�ַ
	for (int i=0;i<RowSize;i++)
	{
		pMap[i]=(int*)malloc(sizeof(int)*ColSize);//����һ�������ڴ棬����ÿһ�е�Ԫ��
	}
	//���ļ��ж�ȡ�����Ԫ��
	pFile=fopen("1.map","rb");
	fseek(pFile,sizeof(int)*2,SEEK_SET);//���ļ���ʼ��ִƫ������int�ʹ�С
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