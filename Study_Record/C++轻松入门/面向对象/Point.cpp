// Point.cpp: implementation of the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "Point.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPoint::CPoint(int x,int y)			//带参数的构造函数
{


	m_x = x;
	m_y = y;

}

void CPoint::copy(CPoint *point)
{

	m_x = CPoint->m_x;			//通过对象指针访问该对象数据成员，赋值
	m_y = CPoint->m_y;			//给调用成员函数的对象的数据成员

}


void CPoint::disp()
{
	
}

CPoint::~CPoint()
{

}
