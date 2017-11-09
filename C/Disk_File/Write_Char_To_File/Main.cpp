#include "stdio.h"
#include "process.h"

void main()
{

	FILE *fp;		//定义文件指针
	char c;			


	printf("test\n");

	if ((fp=fopen("test.txt","w"))==NULL)		//打开文件
	{

		printf("文件打开失败 \n");

		exit(1);

	}
	else
	{

		c = 'H';
		fputc(c,fp);
		c = 'E';
		fputc(c,fp);
		c = 'L';
		fputc(c,fp);
		c = 'L';
		fputc(c,fp);
		c = 'O';
		fputc(c,fp);
		fclose(fp);
	}
}
