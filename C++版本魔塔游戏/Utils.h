#include <stdio.h>
#ifndef   _UTILS_H
#define   _UTILS_H
#include <conio.h>	 //Ϊ�˶�ȡ�����
#include <Windows.h> //����dos���棨��ȡ����̨������λ�á�����������ɫ��
/*
	������
*/
class Utils
{
public:
	~Utils();
	//����һ������ʽ����
	static Utils * getInstance()
	{
		static Utils instance;
		return &instance;
	}
	void Gotoxy(int x, int y);			//��ȡ��Ļ���λ��
	int Color(int c);					//������ɫ����
	void Rabbit();						//����С��

private:
	Utils();
};
#endif 

