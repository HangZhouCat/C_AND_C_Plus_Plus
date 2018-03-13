#include <iostream.h>
inline int intPower(int x);			//声明一个内联函数intPower
int gcdt(int x,int y);
int factorial(int x);

void neilianhanshu()
{


	for (int n =1;n<=10;n++)
	{

		int m = intPower(n);		//调用内联函数intPower
		cout<<n<<"的平方是:"<<m<<endl;

	}


}

inline int intPower(int x)			//定义内联函数intPower
{


	return x*x;

}

void zhijiediguihanshu()
{

		int n = gcdt(20,6);
		cout<<"最大公约数为:"<<n<<endl;

}
int gcdt(int x,int y)
{


	if (x%y==0)
	{

		return y;

	}

	return gcdt(y,x%y);		//再次调用gcdt函数本身		//直接递归调用

}

void jianjiediguidiaoyong()
{



	int n,m;
	cout<<"请输入一个数";
	cin>>n;
	if (n>=0 &&  0 <= 20)
	{

		m = factorial(n);			//调用求阶乘函数
		cout<<n<<"!="<<m<<endl;

	}
	else
	{

		cout<<"输入的数值非法!"<<endl;


	}


}

int factorial(int x)
{


	int t;
	if (x==0)
	{

			 t = 1;

	}
	else
	{


		t = x * factorial(x-1);

	}
	return t;

}


void main()
{

		jianjiediguidiaoyong();

}