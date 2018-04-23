#ifndef __SAVING_H__
#define __SAVING_H__
#include <iostream.h>
class CSaving
{

	int accoundId;			//数据成员 账号
	int balance;			//数据成员 余额
	

public:
	void init(int n=10000);		//初始化
	void saving(float money);		//成员函数  存钱
	void saving(float money1,float money2);		//saving函数重载
	void assume(float money);		//成员函数	取钱

	
	void disp();					//成员函数	打印




protected:
private:
};
#endif