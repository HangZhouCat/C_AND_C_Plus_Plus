#include <iostream.h>
#include <math.h>
#include <string.h>

void GetStrLen()
{
//获取字符串长度函数 
	
	char str1[] = "good morning!";			//初始一个字符数组
	char *pStr = "hello word!";				//定义一个字符串指针
	char str2[80];							//声明一个字符数组
	cout<<"请输入字符串:";
	cin>>str2;								//把输入的字符保存在str2数组中
	cout<<strlen("aabbccddee")<<endl;		//输出指定字符串的长度
	cout<<"str1 的长度是:"<<strlen(str1)<<endl;
	cout<<"pStr 的长度是:"<<strlen(pStr)<<endl;
	cout<<"str2 的长度是:"<<strlen(str2)<<endl;


}
void StrCopy()
{
//字符串复制函数

	char str1[10],str2[10];
	char str3[] = "hello";
	


}
void StrConcat()
{
//字符串连接函数

}
void StrCompare()
{
//字符串比较函数


}

void main()
{

	GetStrLen();

}