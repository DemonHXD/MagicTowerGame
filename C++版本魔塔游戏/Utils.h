#pragma once
#include <conio.h>	 //Ϊ�˶�ȡ�����
#include <Windows.h> //����dos���棨��ȡ����̨������λ�á�����������ɫ��
#include <stdio.h>
#include <string>
/*
	������
*/
using namespace std;
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

	template<typename dataType, typename String>
	void fileWrite(String path, String mode, dataType type, int size);	//�ļ���д

	template<typename array>
	int GetArrLength(array arr);
private:
	Utils();
};

