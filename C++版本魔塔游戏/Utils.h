#pragma once
#include <conio.h>	 //为了读取方向键
#include <Windows.h> //控制dos界面（获取控制台上坐标位置、设置字体颜色）
#include <stdio.h>
#include <string>
/*
	工具类
*/
using namespace std;
class Utils
{
public:
	~Utils();
	//创建一个饿汉式单例
	static Utils * getInstance()
	{
		static Utils instance;
		return &instance;
	}
	void Gotoxy(int x, int y);			//获取屏幕光标位置
	int Color(int c);					//文字颜色函数
	void Rabbit();						//绘制小狗

	template<typename dataType, typename String>
	void fileWrite(String path, String mode, dataType type, int size);	//文件读写

	template<typename array>
	int GetArrLength(array arr);
private:
	Utils();
};

