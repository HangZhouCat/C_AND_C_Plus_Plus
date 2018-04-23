// Test.cpp: implementation of the CTest class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include "Test.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CTest::CTest()
{


}

CTest::~CTest()
{

}
void CTest::add(int i)
{
	num += i;
}
void CTest::init(int n)
{

	num = n;

}
int CTest::getSum()
{

	return num;

}
void CTest::setSum(int i)
{
	sum = i;
}
int CTest::dispSum()
{

	return sum;
}
