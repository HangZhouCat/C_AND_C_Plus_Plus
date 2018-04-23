#include "Saving.h"
void CSaving::init(int n){			//初始化

		accoundId = 10000;
		balance = 0;
}
void CSaving::saving(float money){		//成员函数  存钱

		balance += money;

}
void CSaving::saving(float money1,float money2)
{
	//重载的成员函数的实现
	balance = balance + money1 + money2;
}
void CSaving::assume(float money){		//成员函数	取钱

		balance -= money;

}
void CSaving::disp(){					//成员函数	打印

		cout<<"账号："<<accoundId<<endl;
		cout<<"余额:"<<balance<<endl;

}