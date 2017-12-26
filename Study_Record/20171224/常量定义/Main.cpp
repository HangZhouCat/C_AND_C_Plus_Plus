#include <stdio.h>

#define B 6 //#define是将B定义成一种符号,此时B只是6的别名，在编译期间用6去取代B的值,define相当于替换。
void main(void)
{

	//const是将PI定义成变量，但告诉编译器它的值是固定不变的。
	const int PI = 3.14;

	printf("%d\n",PI);

	printf("%d\n",B);

	getchar();

}