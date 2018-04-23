// Shoes.cpp: implementation of the CShoes class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <string.h>
#include "Shoes.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CShoes::CShoes()
{
//默认构造函数的实现
	strcpy(color,"红色");
	size = 40;			//初始化数据成员size

}

CShoes::CShoes (int s,char* strColor)
{
//带参数的构造函数的实现
	strcpy(color,strColor);			//初始化数据成员strColor
	size = s;						//初始化数据成员size
}

CShoes::CShoes (const CShoes &s)			
{
//拷贝构造函数的实现
	strcpy(color,s.color);
	size = s.size;

}

CShoes::~CShoes()
{
	size = 0;
	cout<<"销毁对象！"<<endl;


}

int CShoes::getSize()
{
	return size;
}
char* CShoes::getColor()
{
	return color;
}