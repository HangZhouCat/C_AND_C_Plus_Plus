#include <iostream.h>
struct student {			//声明struct student结构

	long id;
	char name[10];
	char sex;
	int age;
	float score;

};

typedef struct student STUDENT;		//定义新类型名

STUDENT sdArray[5] =  {{800123,"LiMin",'M',16,89.5},{800124,"ZengLu",'F',16,96.5},
{800125,"WuMeiMei",'F',16,80.5},{800126,"WangLei",'M',17,88.5},{800127,"SunDong",'M',15,66}
					};

bool findStudent(long id,int &index);		//查找函数声明
void disp(int index);					//显示函数声明

void JieGouType()
{

	STUDENT sd;		//定义结构变量
	cout<<"请输入学生的学号:";
	cin>>sd.id;
	cout<<"请输入学生的姓名:";
	cin>>sd.name;
	cout<<"请输入学生的性别:";
	cin>>sd.sex;
	cout<<"请输入学生的年龄:";
	cin>>sd.age;
	cout<<"请输入学生的成绩:";
	cin>>sd.score;
	cout<<"学号\t姓名\t性别\t年龄\t成绩"<<endl;
						//访问结构成员，最后输出
	cout<<sd.id<<"\t"<<sd.name<<"\t"<<sd.sex<<"\t"<<sd.age<<"\t"<<sd.score<<endl;

}
bool findStudent(long id,int &index)
{

	for (int i = 0;i<5;i++)
	{

		if (sdArray[i].id == id)
		{

			index = i;			//相同就赋值给index
			return true;
		}

	}
	return false;

}
void disp(int index)
{

	cout<<"学号\t姓名\t性别\t年龄\t成绩"<<endl;
	cout<<sdArray[index].id<<"\t"<<sdArray[index].name<<"\t"<<sdArray[index].sex<<"\t"<<sdArray[index].age<<"\t"<<sdArray[index].score<<endl;

}
void JieGouArray()
{
//结构类型的数组和指针

	long id = 0;
	int index = 0;
	cout<<"请输入学号";
	cin>>id;
	if (findStudent(id,index))			//查找学号相同的
	{
	
			disp(index);	

	}
	else
	{

			cout<<"没有该学号相关记录"<<endl;

	}


}
void JieGouPoint()
{
//结构指针
	
	STUDENT *p = NULL;		//声明结构指针
	STUDENT sd = {800123,"LiMin",'M',16,89.5};	//给结构变量赋值
	p = &sd;
	p->age = 18;
	p->score = 86.5;
	
	cout<<"学号\t姓名\t性别\t年龄\t成绩"<<endl;
	cout<<p->id<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->age<<"\t"<<p->score<<endl;

}



void main()
{

	JieGouArray();

}