#include <iostream.h>
void Point_Level1()
{
//指针变量的使用
	int n = 10;
	int *pn = &n;
	cout<<"n="<<n<<endl;
	cout<<"pn指向的值为:"<<*pn<<endl;
	n += 25;		
	cout<<"n="<<n<<endl;
	cout<<"pn指向的值为:"<<*pn<<endl;
	*pn = *pn * 10;
	cout<<"n="<<n<<endl;
	cout<<"pn指向的值为:"<<*pn<<endl;
}
void Point_Level2()
{
//指向指针变量的指针
	int n = 10,i= 18;
	int *pn = &n;
	int **pp = &pn;
	cout<<"n="<<n<<endl;
	cout<<"pn="<<pn<<endl;
	cout<<"*pn="<<*pn<<endl;
	cout<<"pp="<<pp<<endl;
	**pp = 5;			//相当于对n的操作
	cout<<"n="<<n<<endl;
	*pp = &i;		//改变pp中的值，让其指向变量i
	cout<<"pn="<<pn<<endl;		//pn中是i的地址值
	cout<<"*pn="<<*pn<<endl;
}
void Point_Add_Sub()
{
//指针变量的加减运算
	int array[5] = {1,2,3,4,5},n = 1;
	int *p	= &array[0];
	for (int i = 0;i < 5;i++)
	{

		cout<<"p中的地址为："<<p<<"\t其数值为:"<<*p<<endl;
		p = p + n;

	}


}
void Point_Array_1()
{
//数组名是数组的首地址
	int array[5] = {1,2,3,4,5};
	int *p = &array[0];
	cout<<"p="<<p<<endl;
	cout<<"array="<<&array<<endl;


}
void Point_Array_2()
{
//用指针改变数组中元素的值
	int array[5] = {1,3,5,7,9};
	int *p = array;		//把指针指向array
	for (int i = 0;i < 5;i++)
	{

		*(p+i) = i * 2;		//把指针指向的元素编程偶数
		cout<<array[i]<<" ";

	}
	cout<<endl;


}

void Point_Array_3()
{
//一维数组中元素的指针表示法
	
	int array[5] = {1,2,3,4,5};
	for (int i = 0;i < 5;i++)
	{


			cout<<"array["<<i<<"]="<<array[i]<<endl;
			cout<<"*(array+"<<i<<")="<<*(array+i)<<endl;		

	}


}
void Point_Array_4()
{
//字符数组和字符指针
	char *pStr = NULL;		//初始化为空
	char str[] = "this is C++ programe";		//初始化字符数组
	pStr = "this is C++ program";		//赋值给字符指针
	cout<<"pstr="<<pStr<<endl;
	cout<<"str="<<str<<endl;


}
void Point_Const()
{
//错误改变常量指针指向的数据的值
	int i = 8;
	int n = 18;
	const int *p = &i;		//常量指针指向变量i
//	*p = 28;			//修改常量指针指向的数据的值，产生编译错误
	cout<<*p<<endl;


}
void Point_Const1()
{
//正确改变常量指针指向的数据值及指向地址
	int i = 8;
	int n = 18;
	const int *p = &i;		//常量指针指向变量i
	i = 28;					//改变常量i的值
	cout<<*p<<endl;
	p = &n;					//把常量指针p指向n
	cout<<*p<<endl;
	


}
void Point_Const2()
{
//指针常量的正确使用方法
	int i = 8;
	int n = 8;
	int *const p = &i;		//定义指针常量p，并初始化指向变量i
	*p = 12;				//通过指针常量来改变其指向的变量i的值
	cout<<*p<<endl;
	i = i + n;
	cout<<*p<<endl;

}
void Point_Fun_Swap(int *px,int *py)
{
//定义交换函数
	int temp = *px;
	*px = *py;
	*py = temp;
	
}
void Point_Fun()
{
//指针作为参数，对两个变量值进行交换
	
	int a = 88,b = 208;
	cout<<"a="<<a<<"\tb="<<b<<endl;
	Point_Fun_Swap(&a,&b);
	cout<<"a="<<a<<"\tb="<<b<<endl;

}
void Point_Array_Copy(int *pDst, const int *pSrc,int slen)
{

	for (int i = 0;i < slen;i++)
	{

		*pDst++ = *pSrc++;

	}

}
void Point_Array_Copy_disp(int *p,int len)
{

	
	for (int i=0;i<len;i++)
	{

		cout<<*(p+i)<<"";


	}

	cout<<endl;

}
void Point_Array_Copy_Main()
{

	int array1[20] = {0};



}
void main()
{


	Point_Fun();


}