// Constant.cpp: implementation of the CConstant class.
//
//////////////////////////////////////////////////////////////////////

#include "Constant.h"
#include <iostream.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//CConstant::CConstant(int x,int y)
//{
//	m_x = x;
//	m_y = y;
//
//}

CConstant::CConstant (int n):nNum(n),rNum(nNum)
{
//通过初始化列表来初始化常数据成员
	cout<<nNum<<":"<<rNum<<endl;

}
CConstant::~CConstant()
{

}
void CConstant::disp()
{
	
	cout<<"x="<<m_x<<"***y="<<m_y<<endl;


}

void CConstant::disp() const
{
//常成员函数实现
	cout<<"x="<<m_x<<"$$$y="<<m_y<<endl;

}
