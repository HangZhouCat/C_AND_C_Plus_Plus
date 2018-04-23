#include "Saving.h"
#include "Test.h"
#include "Shoes.h"
#include "Constant.h"
void saving()
{
//用对象来实现银行账户的操作
	CSaving s;		//定义CSaving对象s
	float money = 0;
	s.init();		//初始化对象s
	cout<<"请输入存款金额:";
	cin>>money;
	s.saving(money);		//调用对象的成员函数saving
	cout<<"请输入取款金额:";
	cin>>money;
	s.assume(money);		//调用对象的成员函数assume
	s.disp();				//调用对象的成员函数disp



}
void saving_point()
{
//使用指针对象来实现操作银行账号
	CSaving s;		//定义CSaving对象s
	CSaving *p = &s;		//把p指向对象s
	float money = 0;
	p->init();
	cout<<"请输入存款金额:";
	cin>>money;

	p->saving(money);		//调用对象的成员函数saving
	cout<<"请输入取款金额:";
	cin>>money;
	p->assume(money);		//调用对象的成员函数assume
	p->disp();				//调用对象的成员函数disp
}
void saving_2()
{
//两个对象的数据成员值是不同的
	CSaving s1,s2;
	s1.init(10000);
	s2.init(20000);
	s1.saving(100);
	s2.saving(250);
	s1.assume(50);
	s2.assume(50);
	s1.disp();
	s2.disp();
}
void member_fun()
{
//给成员函数的参数设置默认值
	CTest t1,t2;
	t1.init();				//没有给参数传值，使用默认参数值
	t2.init(5);
	cout<<t1.getSum()<<" "<<t2.getSum()<<endl;
}
void access_control()
{
//给类成员加上访问控制符
	CTest t;				//生成CTest类的对象
	t.num = 10;				//修改成员num的值
	t.add(10);
	cout<<"t.num="<<t.num<<endl;

	t.setSum(521);			//通过类中的函数来修改类中private变量sum的值

	cout<<"t.sum="<<t.dispSum()<<endl;		//通过类中的函数来访问private变量sum的值
	

}
void Constructor()
{
//构造函数Demo
	CShoes shoes;			//调用默认构造函数
	CShoes shoes1(38,"白色");			//调用带参数的构造函数
	CShoes shoes2(shoes1);				//拷贝构造函数-----用shoes1对象来初始化shoes2
	cout<<"鞋对象的初始尺码为："<<shoes.getSize()<<"颜色为:"<<shoes.getColor()<<endl;
	cout<<"鞋对象的初始尺码为："<<shoes1.getSize()<<"颜色为:"<<shoes1.getColor()<<endl;
	cout<<"鞋对象的初始尺码为："<<shoes2.getSize()<<"颜色为:"<<shoes2.getColor()<<endl;
}
void Constant_Class()
{
//类中的常类型
	CConstant t1(5);			//一般对象		
	const CConstant t2(8);		//常对象
	t1.disp();
	t2.disp();			//通过常对象来调用常成员函数
}
void main()
{

	Constant_Class();

}