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
	�ļ���д
*/
template<typename dataType, typename String>
void Utils::fileWrite(String path, String mode, dataType type, int size) {
	FILE * file = fopen(path, mode);
	fwrite(&type, size, 1, file);
	fclose(file);
}

/*
	��������Ĵ�С�����ص�ͼ��һά��С
*/
template<typename array>
int GetArrLength(array arr) {

}
