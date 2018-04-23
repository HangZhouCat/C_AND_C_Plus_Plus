#include <iostream.h>
#include <vector>
using namespace std;	//使用名字空间std

void vector_add_element()
{
//向量元素的增加
	vector <int> vec;
	vec.push_back(10);
	vec.push_back(20);


}
void vector_del_element()
{
//向量元素的删除
	vector <int> vec;
	int i = 0;
	for (i = 0; i < 10; i++)
	{

		vec.push_back(i);			//增加数据

	}
	cout<<"增加后的元素个数:"<<vec.size()<<endl;
	for (i = 0;i < 5;i++)
	{

		vec.pop_back();				//删除元素

	}
	cout<<"删除后的元素个数:"<<vec.size()<<endl;
	for (i = 0;i < vec.size();i++)
	{

		cout<<vec[i]<<",";		//输出向量容器中的元素

	}
	cout<<endl;

}
void vector_vist_element()
{
//向量元素的访问
	vector <int> vec;
	int i = 0;
	for (i = 0;i < 10;i++)
	{


		vec.push_back(i);		//增加新元素

	}
	for (i = 0; i < vec.size(); i++)
	{

	
		 cout<<vec[i]<<",";		//访问新元素

	}
	cout<<endl;
	
}
void vector_demo()
{
//向量容器的应用
	int i = 0 ;
	vector <long> vec_f;			//声明vector对象
	int max = 0;
	cout<<"请输入最大个数:"<<endl;
	cin>>max;
	vec_f.push_back(1);				//先把前两项加入
	vec_f.push_back(1);
	for (i = 2;i < max;i++)
	{


		vec_f.push_back(vec_f[i-2] + vec_f[i-2]);
		

	}
	for (i = 0;i < vec_f.size(); i++)
	{


		cout<<vec_f[i]<<",";			//输出向量中的每一元素

	}
	cout<<"\n删除后的数列："<<endl;
	for (i = 0;i < 5;i++)
	{

		vec_f.pop_back();			//删除对象中的元素

	}
	for (i = 0; i < vec_f.size(); i ++)
	{


		cout<<vec_f[i]<<",";			//输出向量中的每一元素

	}
	cout<<endl;

}
void main()
{

		vector_demo();

}
