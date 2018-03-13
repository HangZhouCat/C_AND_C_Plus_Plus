#include <iostream.h>
#include <string.h>
struct user 
{

	char name[10];
	int age;

};
struct man {

	char name[10];
	int age;
	char sex;

};

typedef struct user USER;			//定义新结构类型名
typedef struct man MAN;
MAN GetMan();			//声明函数其返还类型为MAN
void disp(MAN *p);
void func(USER us);
void func1(USER *pUser);
void func2(USER &us);

void func(USER us)
{

  us.age += 2;
  strcpy(us.name, "HAHA");

}
void func1(USER *pUser)
{

	pUser->age += 2;
	strcpy(pUser->name,"HAHAHA");

}
void func2(USER &us)
{

	us.age += 2;
	strcpy(us.name,"HAHAHA");

}

void JieGouTransAddress()
{

	USER user1 = {"LILY",20	};
	func1(&user1);
	cout<<"姓名:"<<user1.name<<"年龄:"<<user1.age<<endl;


}

void JieGouTransValue()
{
//结构的传数值调用

	USER user1 = {"LILY",20	};
	func(user1);
	cout<<"姓名:"<<user1.name<<"年龄:"<<user1.age<<endl;
}
void JieGouQuote()
{
//结构的引用调用

	USER user1 = {"LILY",20	};
	func2(user1);
	cout<<"姓名:"<<user1.name<<"年龄:"<<user1.age<<endl;


}
void disp(MAN *p)
{

	cout<<" 姓名: "<<p->name<<" 年龄: "<<p->age<<" 性别: "<<p->sex<<endl;

}
MAN GetMan()
{

	MAN t;
	cout<<"请输入该人的姓名，年龄，和性别，中间用空格分割:";
	cin>>t.name>>t.age>>t.sex;		//接收用户输入的信息
	return t;

}

void JieGouReturn()
{
//结构作为返回值
	MAN manArray[3];			//定义MAN结构数组
	for (int i=0;i<3;i++)
	{

		manArray[i] = GetMan();		//调用GetMan接收输入
		disp(&manArray[i]);			//显示

	}
	
}

void main()
{

	JieGouReturn();


}