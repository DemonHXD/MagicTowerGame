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
	hero->InitHero();

	//д���ʼ��ͼ
	map->InitMap();

	//д����Ϸ������õ��ļ�
	config->InitConfig();

	//��Ϸ��ʼ��
	GameInit();

	//������Ϸ
	Run();
}

/*
	��Ϸ��ʼ��
*/
void Game::GameInit()
{
	//��ȡ�����ļ���Ϣ
	config->ReadConfig(config);

	//��ȡ��ͼ����
	map->ReadMap();

	//��ȡӢ������
	hero->ReadHero(hero);

	//������ͼ��ȡӢ�۵�����
	hero->GetHeroPosition(map, config->m_layer);
}

/*
	��ӡս����Ϣ
*/
void Game::PrintFight(Monster monster) {
	if (monster.m_hp > 0)
	{
		util->Color(12);
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
		util->Gotoxy(53, 7);
		cout << monster.m_name;
		util->Gotoxy(59, 7);
		cout << monster.m_hp;
		util->Gotoxy(65, 7);
		cout << monster.m_att;
		util->Gotoxy(71, 7);
		cout << monster.m_def;
	}
}

/*
	��ӡϵͳ��Ϣ
*/
void Game::PrintSystemInfo() {
	util->Color(14);
	util->Gotoxy(60, 9);
	cout << "ϵͳ��Ϣ";
	util->Gotoxy(53, 10);
	cout << msg;

}

/*
	��Ϸ�浵
*/
void Game::Save() {
	//Sleep(800);
	//util->Gotoxy(26, 18);
	//cout << "��Ϸ���ȱ���ɹ�!" << endl;
	//Sleep(1500);
	//system("CLS");
	ShowSaveGame();
	util->Gotoxy(26, 18);
	cout << "������浵λ��[1,2,3]: ";
	int Input = getch();
	fflush(stdin);//ˢ�����뻺����
	SaveGameSelect(Input - '0');
}

/*
	Ӣ���ƶ�
*/
int Game::HeroMove()
{
	int Input = getch();
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
		break;
	}
	if (0 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{
		//�޸ĵ�ͼ����
		map->map[config->m_layer][hero->m_posx][hero->m_posy] -= 2;//���뿪

		map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] += 2;
		//�޸���������
		hero->m_posx += hero->m_offSetX;
		hero->m_posy += hero->m_offSetY;

	}
	else if (3 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] || 4 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{
		return map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY];
	}
	else if (5 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY])
	{//�������ŵ����
		if (hero->m_key > 0) {
			hero->m_key -= 1;
			HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 5);
		}
	}
	else if (8 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//������Ѫ�����
		hero->m_hp += 400;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 8);
	}
	else if (6 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//�����ӷ��������
		hero->m_def += 4;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 6);
	}
	else if (7 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//�����ӹ��������
		hero->m_att += 4;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 7);
	}
	else if (10 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//����Կ�׵����
		hero->m_key += 1;
		HeroMoveAndUpdate(hero->m_offSetX, hero->m_offSetY, 10);
	}
	else if (12 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//������¥�ݵ����
		IntoNextLayer();
	}
	else if (13 == map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY]) {
		//������¥�ݵ����
		config->m_layer--;
		//���³�ʼ��һ�����ǵ�λ��
		hero->GetHeroPosition(map, config->m_layer);
	}
	return 0;
}

/*
	Ӣ���ƶ�������λ��
*/
void Game::HeroMoveAndUpdate(int OffSetX, int OffSetY, int move) {
	map->map[config->m_layer][hero->m_posx][hero->m_posy] -= 2;//���뿪
	map->map[config->m_layer][hero->m_posx + OffSetX][hero->m_posy + OffSetY] += 2 - move;
	//�޸���������
	hero->m_posx += OffSetX;
	hero->m_posy += OffSetY;
}

/*
	������һ��
*/
void Game::IntoNextLayer()
{
	config->m_layer++;
	if (config->m_layer < map->mapCount) {
		//Save();
		//���³�ʼ��һ�����ǵ�λ��
		hero->GetHeroPosition(map, config->m_layer);
		//GameInit();
	}
	else {
		config->m_layer--;
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
			map->map[config->m_layer][hero->m_posx][hero->m_posy] = 0;//Ӣ��ԭ����λ������Ϊ0
			//�������ڵ�λ������2.
			map->map[config->m_layer][hero->m_posx + hero->m_offSetX][hero->m_posy + hero->m_offSetY] = 2;
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
		map->PrintMap(config->m_layer);
		//��ӡϵͳ��Ϣ
		PrintSystemInfo();
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

/*
	ѡ��浵
*/
void Game::SaveGameSelect(int select) {
	//����Ӣ������
	hero->SaveHero(hero);
	//�����ͼ
	map->SaveMap();
	config->m_save[select - 1] = util->GetCurrentionTime();
	//д����Ϸ������õ��ļ�
	config->WriteConfig(config);
	util->Gotoxy(26, 20);
	cout << "�浵�ɹ�!!!";
	Sleep(1500);
	system("CLS");
}

/*
	�鿴�浵
*/
void Game::ShowSaveGame() {
	util->Gotoxy(53, 10);
	cout << "*************************";
	util->Gotoxy(53, 11);
	cout << config->m_save[0];
	util->Gotoxy(53, 12);
	cout << config->m_save[1];
	util->Gotoxy(53, 13);
	cout << config->m_save[2];
	util->Gotoxy(53, 14);
	cout << "*************************";

}
