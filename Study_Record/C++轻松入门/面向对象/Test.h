// Test.h: interface for the CTest class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST_H__29343CF9_C597_4840_811F_5944C3033728__INCLUDED_)
#define AFX_TEST_H__29343CF9_C597_4840_811F_5944C3033728__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTest  
{
//	int num;
public:
	int num;
	CTest();
	virtual ~CTest();
	void init(int n = 10);			//有默认值的成员函数init
	int getSum();
	void add(int i);
	void setSum(int i);
	int dispSum();
private:
	int sum;

};

#endif // !defined(AFX_TEST_H__29343CF9_C597_4840_811F_5944C3033728__INCLUDED_)
