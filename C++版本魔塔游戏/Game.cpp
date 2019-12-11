#include "Game.h"
Game::Game()
{
}

Game::~Game()
{
}

/*
	��ʼ��Ϸ
*/
void Game::NewGame() {
	//��ʼ��ɫ����
	Hero *hero = new Hero( "Jack",1,100,10,5,0,0,0,0,0,10,3 );
	//д��Ӣ�����Ե��ļ�
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//д���ʼ��ͼ
	map->InitMap();

	//д����Ϸ������õ��ļ�
	layer = 0;
	FILE * pFileLayer = fopen("res/game/config.txt", "wb");
	//fprintf(pFileLayer, "%d", layer);
	fwrite(&layer, sizeof(int), 1, pFileLayer);
	fclose(pFileLayer);

	GameInit();
	Run();
}

/*
	��Ϸ��ʼ��
*/
void Game::GameInit()
{
	//��ȡ�����ļ���Ϣ
	FILE * pFileLayer = fopen("res/game/config.txt", "rb");
	fread(&layer, 4, 1, pFileLayer);
	fclose(pFileLayer);

	//��ȡ��ͼ����
	map->ReadMap();

	//��ȡӢ������
	FILE * pFile = fopen("res/hero/hero.txt", "rb");
	fread(hero, sizeof(Hero), 1, pFile);
	fclose(pFile);
	//������ͼ��ȡӢ�۵�����
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
	��ӡս����Ϣ
*/
void Game::PrintFight(Monster monster) {
	util->Color(13);
	//��ӡӢ�۵�ս������
	util->Gotoxy(53, 6);
	cout << hero->m_name;
	util->Gotoxy(59, 6);
	cout << hero->m_hp;
	util->Gotoxy(65, 6);
	cout << hero->m_att;
	util->Gotoxy(71, 6);
	cout << hero->m_def;

	//��ӡ�����ս������
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
	��Ϸ�浵
*/
void Game::Save() {
	//����Ӣ������
	FILE * pFileHero = fopen("res/hero/hero.txt", "wb");
	fwrite(hero, sizeof(Hero), 1, pFileHero);
	fclose(pFileHero);

	//�����ͼ
	map->SaveMap();


	//д����Ϸ������õ��ļ�
	FILE * pFileLayer = fopen("res/game/config.txt", "wb");
	//fprintf(pFileLayer, "%d", layer);
	fwrite(&layer, 4, 1, pFileLayer);
	fclose(pFileLayer);
}

/*
	Ӣ���ƶ�
*/
int Game::HeroMove()
{
	int Input = getch();
	//system("CLS");
	//flush(Input);
	fflush(stdin);//ˢ�����뻺����
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
		GameInit();//��ʼ����Ϸ
		Choice();//�������˵�
		break;
	case '2':
		Save();
		Sleep(800);
		util->Gotoxy(26, 18);
		cout << "��Ϸ���ȱ���ɹ�!" << endl;
		Sleep(1500);
		system("CLS");
		break;
	}
	if (0 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{
		//�޸ĵ�ͼ����
		map->map[layer][hero->m_posx][hero->m_posy] -= 2;//���뿪

		map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] += 2;
		//�޸���������
		hero->m_posx += hero->m_offSetX;
		hero->m_posy += hero->m_offSetY;

	}
	else if (3 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] || 4 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{
		return map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY];
	}
	else if (5 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{//�������ŵ����
		if (hero->m_key > 0) {
			hero->m_key -= 1;
			HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 5);
		}
	}
	else if (8 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//������Ѫ�����
		hero->m_hp += 400;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 8);
	}
	else if (6 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//�����ӷ��������
		hero->m_def += 4;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 6);
	}
	else if (7 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//�����ӹ��������
		hero->m_att += 4;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 7);
	}
	else if (10 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//����Կ�׵����
		hero->m_key += 1;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 10);
	}
	else if (12 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//������¥�ݵ����
		IntoNextLayer();
	}
	else if (13 == map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//������¥�ݵ����
		layer--;
		Save();
		//���³�ʼ��һ�����ǵ�λ��
		GameInit();
	}
	return 0;
}

/*
	Ӣ���ƶ�������λ��
*/
void Game::HeroMoveAndUpdate(int OffSetX, int OffSetY, int move) {
	map->map[layer][hero->m_posx][hero->m_posy] -= 2;//���뿪
	map->map[layer][hero->m_posx + OffSetX][hero->m_posy + OffSetY] += 2 - move;
	//�޸���������
	hero->m_posx += OffSetX;
	hero->m_posy += OffSetY;
}

/*
	������һ��
*/
void Game::IntoNextLayer()
{
	layer++;
	if (layer < map->mapCount) {
		Save();
		//���³�ʼ��һ�����ǵ�λ��
		GameInit();
	}
	else {
		layer--;
		util->Gotoxy(26, 18);
		cout << "��ʱ���ܼ��ظ����ͼ";
		Sleep(1500);
		system("CLS");
		
	}
}

/*
	ս��
*/
bool Game::Fight(int Kind)
{
	// ��������
	Monster monster;
	//����·��
	char path[50] = "res/monster/monster";
	char Numchar[4];
	//������ת�����ַ���
	itoa(Kind, Numchar, 10);
	char temp[10] = ".txt";
	strcat(strcat(path, Numchar), temp);
	//���ļ��ж�ȡ���������
	FILE* pFile = fopen(path, "rb");
	fread(&monster, sizeof(Monster), 1, pFile);
	fclose(pFile);
	//�Զ�ս��
	while (true)
	{
		//�ж�Ӣ��Ѫ��>0
		if (hero->m_hp > 0)
		{
			if (hero->m_att > monster.m_def)//�ж�Ӣ�۵Ĺ���>����ķ�����
			{
				monster.m_hp -= hero->m_att - monster.m_def;

			}
			else
			{
				monster.m_hp -= 1;
			}
		}
		else
			return false;//ʧ��
		if (monster.m_hp > 0)
		{

			if (monster.m_att > hero->m_def)//�ж�Ӣ�۵Ĺ���>����ķ�����
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
			//�޸ĵ�ͼ����
			map->map[layer][hero->m_posx][hero->m_posy] = 0;//Ӣ��ԭ����λ������Ϊ0
			//�������ڵ�λ������2.
			map->map[layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] = 2;
			hero->m_posx += hero->m_offSetX;
			hero->m_posy += hero->m_offSetY;
			//������������:
			hero->LvUp(monster.m_exp);
			system("CLS");
			return true;//ʤ��
		}
		// ��ӡս����Ϣ
		PrintFight(monster);
		Sleep(1000);
		
	}

}

/*
	������Ϸ
*/
void  Game::Run()
{
	GameInit();
	system("CLS");
	while (1)
	{
		//��ӡӢ������
		hero->PrintHero();
		//��ӡ��ͼ
		//PrintMap();
		map->PrintMap(layer);
		//�����˵�
		helpMenu();
		int Kind = HeroMove();
		if (3 == Kind || 4 == Kind)
		{
			Fight(Kind);
		}
	}
}

/*
	������Ϸ
*/
void Game::Close() {
	system("exit");
}

/*
	��ȡ����
*/
void Game::ReadMemory() {
	Run();
}

/*
	��Ϸ���򼰰���˵��
*/
void Game::Explation() {

}

/*
	�˵�ѡ��
 */
void Game::Choice() {
	util->Rabbit();
	int n;
	int i, j = 1;
	util->Gotoxy(32, 2);
	util->Color(13);
	cout << " ħ �� 2 0 1 9 ";
	util->Color(14);          			//��ɫ�߿�
	for (i = 3; i <= 14; i++)   	//������±߿�===
	{
		for (j = 15; j <= 60; j++)  //������ұ߿�||
		{
			util->Gotoxy(j, i);
			if (i == 3 || i == 14) cout << "=";
			else if (j == 15 || j == 59) cout << "||";
		}
	}

	util->Color(12);
	util->Gotoxy(25, 6);
	cout << "1.��Ϸ��ʼ";
	util->Gotoxy(40, 6);
	cout << "2.��ȡ����";
	util->Gotoxy(25, 10);
	cout << "3.��Ϸ����";
	util->Gotoxy(40, 10);
	cout << "4.������Ϸ";
	util->Gotoxy(21, 16);
	util->Color(5);
	cout << "��ѡ��[1 2 3 4]:[ ]\b\b";
	cin >> n;    //����ѡ��
	switch (n)
	{
	case 1:
		NewGame();          //�µ���Ϸ��ʼ
		break;
	case 2:
		ReadMemory();      	//��ȡ����
		break;
	case 3:
		Explation();     	//��Ϸ���򼰰���˵��
		break;
	case 4:
		Close();    		//������Ϸ
		break;
	}
}

/*
	�����˵�
*/
void Game::helpMenu() {
	util->Color(3);
	util->Gotoxy(26, 16);
	cout << "[1]�ص����˵�";

	util->Gotoxy(40, 16);
	cout << "[2]�浵";
}