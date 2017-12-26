#include <stdio.h>
void main(void)
{

		//定义变量时没有指定其初始值，稍后使用再赋值。
		int a,b,c;
		a = 1;
		b = 2;
		c = 3;
		printf("%x\t%d\n",&a,a);
		printf("%x\t%d\n",&b,b);
		printf("%x\t%d\n",&c,c);


	//定义变量时直接指定初始值
//	int a = 1,b = 2, c = 3;


	//定义变量时没有指定其初始值，使用变量前也未进行赋值
//
//	int a,b,c;
//
//		printf("%x\t%d\n",&a,a);
//		printf("%x\t%d\n",&b,b);
//		printf("%x\t%d\n",&c,c);

		getchar();


}