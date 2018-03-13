#include <iostream.h>
#include <conio.h>
void suanshuyunsuanfu()
{


	int num1,num2,num3,num4,num5;

	num1 = 3+8;
	num2 = 10-7;
	num3 = num2 * num1;	//乘法运算
	num4 = num3/5;		//除法运算
	num5 = num3%2;		//取余运算

	cout<<"num1="<<num1<<"\n";
	cout<<"num2="<<num2<<"\n";
	cout<<"num3="<<num3<<"\n";
	cout<<"num4="<<num4<<"\n";
	cout<<"num5="<<num5<<"\n";


}
void zizengAndzijian()
{

	int a,b;
	a = 20,b=20;

	cout<<"a++ ="<< a++ <<endl;
	cout<<"++b ="<< ++b <<endl;
	



}
void weiyunsuanfu()
{

	int n = 7;
	int left_n = 0;
	left_n = n << 4;	//把n的值7左移4位，即112再赋值给left_n
	cout << "left_n=" <<left_n <<endl;
	


}
void guanxiyunsuanfu()
{

		char m = 'm';		//字符m即109
		char n = 'n';		//字符n即110
		int i = 0;
		i = m < n;			//110大于109，所以i的值为1
		cout<<"i="<<i<<endl;
		i = (m==n-1);		//109等于110-1，所以i的值为1
		cout<<"i="<<i<<endl;


}

void yinyongbianliang()
{
//引用变量

	int num = 10;
	int &rNum = num;			//对引用rNum的初始化
	rNum = 20;					//实际是改变num的值
	int temp = rNum;			//把num的值赋给temp
	cout<<"num="<<num<<"temp="<<temp<<endl;

}

void main()
{

	
	yinyongbianliang();

	
}


