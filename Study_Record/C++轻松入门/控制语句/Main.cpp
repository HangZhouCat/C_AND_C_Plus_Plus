#include <iostream.h>


void luojiyu()
{

	int health = 0;
	int number = 0;
	int school = 0;
	cout << "请输入学生成绩:";
	cin >> number;
	cout << "请输入学生健康状态【(健康1)，不健康(0)】";
	cin >> health;
	cout<<"请输入学生是否具有高中学历【有(1)，没有(0)】";
	cin>>school;
	if (health && school && (number > 500))
	{

		cout<<"可以录取"<<endl;

	}
	else
	{

		cout<<"不可以录取"<<endl;

	}


}
void luojihuo()
{
	int health = 0;
	int number = 0;
	int school = 0;
	int suit = 0,exce = 0;
	cout<<"请输入是否特长生【是(1),否(0)】";
	cin>>suit;
	cout<<"请输入是否保送生【是(1),否(0)】";
	cin>>exce;
	if (suit || exce)
	{


		cout<<"可以录取"<<endl;

	}
	else
	{

			
			cout << "请输入学生成绩:";
			cin >> number;
			cout << "请输入学生健康状态【(健康1)，不健康(0)】";
			cin >> health;
			cout<<"请输入学生是否具有高中学历【有(1)，没有(0)】";
			cin>>school;
			if (health && school && (number > 500))
			{

				cout<<"可以录取"<<endl;

			}
			else
			{

				cout<<"不可以录取"<<endl;

			}


	}


}

void sanyuanyunsuanfu()
{

	int i = 10,j = 15, n = 0;
	n = i>j?i++:++j;
	cout<<"i="<<i<<"\tj="<<j<<"\tn="<<n<<endl;
	n = i-j?i+j:i-10?j:i;
	cout<<"i="<<i<<"\tj="<<j<<"\tn="<<n<<endl;
	

}

void main()
{
	

	sanyuanyunsuanfu();

}