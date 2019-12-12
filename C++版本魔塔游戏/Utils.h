
#ifndef   _UTILS_H
#define   _UTILS_H
#include <conio.h>	 //为了读取方向键
#include <Windows.h> //控制dos界面（获取控制台上坐标位置、设置字体颜色）
#include <stdio.h>
#include <string>
#include <ctime>
using namespace std;
/*
	工具类
*/

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
	string GetCurrentionTime();			//返回当前时间
	string to2String(string str);		//字符串不够两位用0补齐

private:
	Utils();
};
#endif 

