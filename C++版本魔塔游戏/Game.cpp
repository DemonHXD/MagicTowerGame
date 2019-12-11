#include "Game.h"
Game::Game()
{
}

Game::~Game()
{
}

/*
	开始游戏
*/
void Game::NewGame() {
	//初始角色属性
	Hero *hero = new Hero( "Jack",1,100,10,5,0,0,0,0,0,10,3 );
	//写入英雄属性到文件
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//写入初始地图
	map->InitMap();

	//写入游戏相关配置到文件
	layer = 0;
	FILE * pFileLayer = fopen("res/game/config.txt", "wb");
	//fprintf(pFileLayer, "%d", layer);
	fwrite(&layer, sizeof(int), 1, pFileLayer);
	fclose(pFileLayer);

	GameInit();
	Run();
}

/*
	游戏初始化
*/
void Game::GameInit()
{
	//读取配置文件信息
	FILE * pFileLayer = fopen("res/game/config.txt", "rb");
	fread(&layer, 4, 1, pFileLayer);
	fclose(pFileLayer);

	//读取地图数据
	map->ReadMap();

	//读取英雄数据
	FILE * pFile = fopen("res/hero/hero.txt", "rb");
	fread(hero, sizeof(Hero), 1, pFile);
	fclose(pFile);
	//遍历地图读取英雄的坐标
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (2 == map->map[layer][i][j])
			{
				hero->m_posx = i;
				hero->m_posy = j;
			}
		}
	}
}



/*
	打印战斗信息
*/
void Game::PrintFight(Monster monster) {
	util->Color(13);
	//打印英雄的战斗数据
	util->Gotoxy(53, 6);
	cout << hero->m_name;
	util->Gotoxy(59, 6);
	cout << hero->m_hp;
	util->Gotoxy(65, 6);
	cout << hero->m_att;
	util->Gotoxy(71, 6);
	cout << hero->m_def;

	//打印怪物的战斗属性
	util->Gotoxy(53, 8);
	cout << monster.m_name;
	util->Gotoxy(59, 8);
	cout << monster.m_hp;
	util->Gotoxy(65, 8);
	cout << monster.m_att;
	util->Gotoxy(71, 8);
	cout << monster.m_def;
}

/*
	游戏存档
*/
void Game::Save() {
	//保存英雄属性
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//保存地图
	map->SaveMap();


	//写入游戏相关配置到文件
	FILE * pFileLayer = fopen("res/game/config.txt", "wb");
	//fprintf(pFileLayer, "%d", layer);
	fwrite(&layer, 4, 1, pFileLayer);
	fclose(pFileLayer);
}

/*
	英雄移动
*/
int Game::HeroMove()
{
	int Input = getch();
	//system("CLS");
	//flush(Input);
	fflush(stdin);//刷新输入缓存区
	hero->m_offSetX = hero->m_offSetY = 0;
	switch (Input)
	{
	case 's':
	case 'S':
		hero->m_offSetX += 1;
		break;
	case 'w':
	case 'W':
		hero->m_offSetX -= 1;
		break;
	case 'a':
	case 'A':
		hero->m_offSetY -= 1;
		break;
	case 'd':
	case 'D':
		hero->m_offSetY += 1;
		break;
	case '1':
		system("CLS");
		GameInit();//初始化游戏
		Choice();//进入主菜单
		break;
	case '2':
		Save();
		Sleep(800);
		util->Gotoxy(26, 18);
		cout << "游戏进度保存成功!" << endl;
		Sleep(1500);
		system("CLS");
		break;
	}
	if (0 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{
		//修改地图数据
		map->map[layer][hero->m_posx][hero->m_posy] -= 2;//人离开

		map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] += 2;
		//修改人物坐标
		hero->m_posx += hero->m_offSetX;
		hero->m_posy += hero->m_offSetY;

	}
	else if (3 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] || 4 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{
		return map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY];
	}
	else if (5 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{//碰到是门的情况
		if (hero->m_key > 0) {
			hero->m_key -= 1;
			HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 5);
		}
	}
	else if (8 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//碰到加血的情况
		hero->m_hp += 400;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 8);
	}
	else if (6 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//碰到加防御的情况
		hero->m_def += 4;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 6);
	}
	else if (7 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//碰到加攻击的情况
		hero->m_att += 4;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 7);
	}
	else if (10 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//碰到钥匙的情况
		hero->m_key += 1;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 10);
	}
	else if (12 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//碰到上楼梯的情况
		IntoNextLayer();
	}
	else if (13 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//碰到下楼梯的情况
		layer--;
		Save();
		//重新初始化一下主角的位置
		GameInit();
	}
	return 0;
}

/*
	英雄移动并更新位置
*/
void Game::HeroMoveAndUpdate(int OffSetX, int OffSetY, int move) {
	map->map[layer][hero->m_posx][hero->m_posy] -= 2;//人离开
	map->map[layer][hero->m_posx + OffSetX][hero->m_posy + OffSetY] += 2 - move;
	//修改人物坐标
	hero->m_posx += OffSetX;
	hero->m_posy += OffSetY;
}

/*
	进入下一层
*/
void Game::IntoNextLayer()
{
	layer++;
	if (layer < map->mapCount) {
		Save();
		//重新初始化一下主角的位置
		GameInit();
	}
	else {
		layer--;
		util->Gotoxy(26, 18);
		cout << "暂时不能加载更多地图";
		Sleep(1500);
		system("CLS");
		
	}
}

/*
	战斗
*/
bool Game::Fight(int Kind)
{
	// 创建怪物
	Monster monster;
	//解析路径
	char path[50] = "res/monster/monster";
	char Numchar[4];
	//把数字转换成字符串
	itoa(Kind, Numchar, 10);
	char temp[10] = ".txt";
	strcat(strcat(path, Numchar), temp);
	//从文件中读取怪物的数据
	FILE* pFile = fopen(path, "rb");
	fread(&monster, sizeof(Monster), 1, pFile);
	fclose(pFile);
	//自动战斗
	while (true)
	{
		//判断英雄血量>0
		if (hero->m_hp > 0)
		{
			if (hero->m_att > monster.m_def)//判断英雄的攻击>怪物的防御力
			{
				monster.m_hp -= hero->m_att - monster.m_def;

			}
			else
			{
				monster.m_hp -= 1;
			}
		}
		else
			return false;//失败
		if (monster.m_hp > 0)
		{

			if (monster.m_att > hero->m_def)//判断英雄的攻击>怪物的防御力
			{
				hero->m_hp -= monster.m_att - hero->m_def;

			}
			else
			{
				hero->m_hp -= 1;
			}
		}
		else
		{
			//修改地图数据
			map->map[layer][hero->m_posx][hero->m_posy] = 0;//英雄原来的位置设置为0
			//怪物所在的位置设置2.
			map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] = 2;
			hero->m_posx += hero->m_offSetX;
			hero->m_posy += hero->m_offSetY;
			//调用升级函数:
			hero->LvUp(monster.m_exp);
			system("CLS");
			return true;//胜利
		}
		// 打印战斗信息
		PrintFight(monster);
		Sleep(1000);
		
	}

}

/*
	运行游戏
*/
void  Game::Run()
{
	GameInit();
	system("CLS");
	while (1)
	{
		//打印英雄属性
		hero->PrintHero();
		//打印地图
		//PrintMap();
		map->PrintMap(layer);
		//帮助菜单
		helpMenu();
		int Kind = HeroMove();
		if (3 == Kind || 4 == Kind)
		{
			Fight(Kind);
		}
	}
}

/*
	结束游戏
*/
void Game::Close() {
	system("exit");
}

/*
	读取回忆
*/
void Game::ReadMemory() {
	Run();
}

/*
	游戏规则及按键说明
*/
void Game::Explation() {

}

/*
	菜单选项
 */
void Game::Choice() {
	util->Rabbit();
	int n;
	int i, j = 1;
	util->Gotoxy(32, 2);
	util->Color(13);
	cout << " 魔 塔 2 0 1 9 ";
	util->Color(14);          			//黄色边框
	for (i = 3; i <= 14; i++)   	//输出上下边框===
	{
		for (j = 15; j <= 60; j++)  //输出左右边框||
		{
			util->Gotoxy(j, i);
			if (i == 3 || i == 14) cout << "=";
			else if (j == 15 || j == 59) cout << "||";
		}
	}

	util->Color(12);
	util->Gotoxy(25, 6);
	cout << "1.游戏开始";
	util->Gotoxy(40, 6);
	cout << "2.读取回忆";
	util->Gotoxy(25, 10);
	cout << "3.游戏规则";
	util->Gotoxy(40, 10);
	cout << "4.结束游戏";
	util->Gotoxy(21, 16);
	util->Color(5);
	cout << "请选择[1 2 3 4]:[ ]\b\b";
	cin >> n;    //输入选项
	switch (n)
	{
	case 1:
		NewGame();          //新的游戏开始
		break;
	case 2:
		ReadMemory();      	//读取回忆
		break;
	case 3:
		Explation();     	//游戏规则及按键说明
		break;
	case 4:
		Close();    		//结束游戏
		break;
	}
}

/*
	帮助菜单
*/
void Game::helpMenu() {
	util->Color(3);
	util->Gotoxy(26, 16);
	cout << "[1]回到主菜单";

	util->Gotoxy(40, 16);
	cout << "[2]存档";
}