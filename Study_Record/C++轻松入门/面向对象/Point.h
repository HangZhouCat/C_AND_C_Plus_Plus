// Point.h: interface for the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_POINT_H__F824BEE4_095B_472D_ADF4_E91BCD90009D__INCLUDED_)
#define AFX_POINT_H__F824BEE4_095B_472D_ADF4_E91BCD90009D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPoint  
{
public:
	CPoint(int x,int y);
	void copy(CPoint *point);		//在成员函数中，参数是对象指针
	void setXY(int x,int y);
	void disp();
	virtual ~CPoint();
private:
	int m_x;
	int m_y;

};

#endif // !defined(AFX_POINT_H__F824BEE4_095B_472D_ADF4_E91BCD90009D__INCLUDED_)
