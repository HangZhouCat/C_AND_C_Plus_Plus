#include <iostream.h>
void Fibonacci()
{
//用数组求Fibonacci数列
	int i = 0;
	int f[20] = {1,1};
	for (i = 2;i < 20;i++)
	{

		f[i] = f[i-2] + f[i-1];		//后项的结构等于前两项只和
		

	}
	for (i = 0;i < 20; i++)
	{

		if (i%5 == 0)			//判断是否等于5
		{

				cout<<endl;			//每五个字符输出1个换行

		}
		cout<<f[i]<<" ";			//输出数组的每1元素

	}
}
void disp(int nArray[],int len)
{
//将数组作为参数传给函数
	for (int i = 0;i<len;i++)
	{

		nArray[i] = 0;			//把nArray的每个元素变成0

	}
}
void Array_arg_fun()
{
	
	int nArray[] = {10,20,30,40};
	int i = 0;
	disp(nArray,4);
	for (i = 0;i < 4;i++)
	{
		cout<<nArray[i]<<",";		//输出数据
	}
	cout<<endl;

}
void main()
{
	int nArray[10] ;
	int n = sizeof(nArray) / sizeof(nArray[0]);
	cout<<n;

}