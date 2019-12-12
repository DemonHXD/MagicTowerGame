#include "Utils.h"
Utils::Utils()
{
}


Utils::~Utils()
{
}

/*
	��ȡ��Ļ���λ��
*/
void Utils::Gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

/*
	������ɫ����
*/
int Utils::Color(int c) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

/*
	����С��
*/
void Utils::Rabbit() {
	Color(3);
	Gotoxy(64, 4);
	printf("��-��  ��-��");
	Gotoxy(64, 5);
	printf("�� ��  �� ��");
	Gotoxy(64, 6);
	printf("�� ��  �� ��");
	Gotoxy(63, 7);
	printf("_��");
	Gotoxy(74, 7);
	printf("��_");
	Gotoxy(62, 8);
	printf("��");
	Gotoxy(76, 8);
	printf("��");
	Gotoxy(62, 9);
	printf("��            ��");
	Gotoxy(62, 10);
	printf("��");
	Gotoxy(76, 10);
	printf("��");
	Gotoxy(62, 11);
	printf("��            ��");
	Gotoxy(62, 12);
	printf("�����ש����ש���");
	Gotoxy(64, 13);
	printf("����    �ǩ�");
	Gotoxy(62, 14);
	printf("���ީߩ��ߩߩݡ�");
	Color(5);
	Gotoxy(67, 7);
	printf("`~ ��~`");
	Color(4);
	Gotoxy(67, 8);
	printf("��   ��");
	Color(13);
	Gotoxy(65, 9);
	printf("��");
	Gotoxy(74, 9);
	printf("��");
	Color(12);
	Gotoxy(69, 11);
	printf("��");
}

/*
	��ȡ��ǰʱ��
*/
string Utils::GetCurrentionTime() {
	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��
	time_t now = time(0);
	tm *ltm = localtime(&now);
	string time = "";
	string month = to2String(to_string(1 + ltm->tm_mon));
	string day = to2String(to_string(1 + ltm->tm_mday));
	//string hour = to2String(to_string(ltm->tm_hour));
	//string min = to2String(to_string(ltm->tm_min));
	//string sec = to2String(to_string(ltm->tm_sec));

	time = "*�浵����:"
		+ to_string(1900 + ltm->tm_year) + "��"
		+ month + "��"
		+ day + "��*";
	//+ hour + ":"
	//+ min + ":"
	//+ sec;
	return time;
}

string Utils::to2String(string str) {
	if (str.size() < 2)
	{
		str = "0" + str;
	}
	return str;
}


