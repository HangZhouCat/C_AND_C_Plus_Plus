#include <iostream.h>
enum WEEK {SUM,MON,TUE,WED,THU,FRI,SAT};	//声明枚举类型WEEK

void main()
{

	WEEK week1,week2,week3;		//声明枚举变量
	week1 = MON;				//枚举变量赋值
	week2 = WED;
	week3 = SAT;
	cout<<week1<<" "<<week2<<" "<<week3<<endl;		//输出枚举变量值
}