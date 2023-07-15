//本程序为模拟通讯录管理系统
//基础功能有菜单、添加、显示、删除、查找、修改、清空、退出

#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

struct Person
{
	string m_Name;  //姓名
	int m_Sex;  //性别：1-男 2-女
	int m_Age;  //年龄
	string m_Phone;  //电话号码
	string m_Address;  //住址
};

struct Addressbooks
{
	Person personArray[MAX];  //通讯录中最大联系人数
	int m_Size;  //当前通讯录中的联系人数
};

void Menu();  //菜单
void Exit();  //退出
void Addperson(Addressbooks* Abs);  //添加
void Showperson(Addressbooks* Abs);  //显示
void Deleteperson(Addressbooks* Abs);  //删除
void Findperson(Addressbooks* Abs);  //查找
void Modperson(Addressbooks* Abs);  //修改
void Empty(Addressbooks* Abs);  //清空
int Judgeperson(Addressbooks* Abs,string name);  //判断联系人是否存在

int main()
{
	//创建通讯录类型的变量
	Addressbooks Abs;
	//初始化人员个数
	Abs.m_Size = 0;

	//初始化用户选择时的输入
	int number = 0;
	
	while (true)
	{
		Menu(); //菜单

		cin >> number;

		switch (number)//根据用户输入提供不同的功能
		{
		case 1:  //添加
			Addperson(&Abs);
			break;
		case 2: 
			Showperson(&Abs);//显示
			break;
		case 3:  //删除
		    Deleteperson(&Abs);
		    break;
		case 4:  //查找
			Findperson(&Abs);
			break;
		case 5:  //修改
			Modperson(&Abs);
			break;
		case 6:  //清空
			Empty(&Abs);
			break;
		case 0:
			Exit();
			return 0;
			break;

		default:
			break;
		}
	}

	system("pause");
	return 0;
}

void Menu()
{
	cout << "**********************" << endl;
	cout << "*****1.添加联系人*****" << endl;
	cout << "*****2.显示联系人*****" << endl;
	cout << "*****3.删除联系人*****" << endl;
	cout << "*****4.查找联系人*****" << endl;
	cout << "*****5.修改联系人*****" << endl;
	cout << "*****6.清空联系人*****" << endl;
	cout << "*****            *****" << endl;
	cout << "*****0.退出***********" << endl;
	cout << "**********************" << endl;
}

void Exit()
{
	cout << "退出成功，欢迎下次使用" << endl;
	system("pause");
}

void Addperson(Addressbooks* Abs)
{
	//先判断通讯录是否已满，已满则报错
	if (Abs->m_Size == MAX)
	{
		cout << "通讯录已满，操作失败" << endl;
	}
	else 
	{
		//添加联系人具体信息
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		Abs->personArray[Abs->m_Size].m_Name = name;

		//性别
		int sex;
		cout << "请输入性别" << endl;
		cout << "1--男   2--女" << endl;
		cin >> sex;
		Abs->personArray[Abs->m_Size].m_Sex = sex;
		
		/*while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				Abs->personArray[Abs->m_Size].m_Sex = sex;
				break;
			}
			else
				cout << "输入有误！" << endl;
		}*/

		//年龄
		int age;
		cout << "请输入年龄" << endl;
		cin >> age;
	    Abs->personArray[Abs->m_Size].m_Age = age;

		//电话号码
		string phonenumber;
		cout << "请输入电话号码" << endl;
		cin >> phonenumber;
		Abs->personArray[Abs->m_Size].m_Phone = phonenumber;

		//住址
		string address;
		cout << "请输入住址" << endl;
		cin >> address;
		Abs->personArray[Abs->m_Size].m_Address = address;

		//更新通讯录当前人数
		Abs->m_Size++;

		cout << "添加成功" << endl;
	}

	system("pause");  //请按任意键继续
	system("cls");  //清屏
}

void Showperson(Addressbooks* Abs)
{
	//判断人数是否为0，为0提示为空
	//若不为0，显示所有记录的信息
    
	if (Abs->m_Size == 0)
		cout<<"通讯录为空"<<endl;
	else
	{
		for (int i = 0;i < Abs->m_Size;i++)
		{
			cout << "序号：" << i + 1 << "\t";  //用水平制表符\t更美观
			cout << "姓名：" << Abs->personArray[i].m_Name << "\t";
			/*if (Abs->personArray[i].m_Sex == 1)//注意性别显示的结果
				cout << "性别：男" << "\t";
			else if (Abs->personArray[i].m_Sex == 2)
				cout << "性别：女" << "\t";*/
			//用三目运算符优化
			cout << "性别：" << (Abs->personArray[i].m_Sex==1 ? "男":"女") <<"\t";

			cout << "年龄：" << Abs->personArray[i].m_Age << "\t";
			cout << "电话号码：" << Abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << Abs->personArray[i].m_Address << endl;
			cout <<"-----"<< endl;
		}
	}

	system("pause");  //请按任意键继续
	system("cls");  //清屏
}

void Deleteperson(Addressbooks* Abs)
{
	cout << "请输入要删除联系人的姓名：" << endl;
	string deletename;
	cin >> deletename;
	if (Judgeperson(Abs, deletename) == -1)  //未查到
		cout << "查无此人" << endl;
	else  //查到了则删除，前移所有删除位置后的数据
	{
		for (int i = Judgeperson(Abs, deletename);i < Abs->m_Size;i++)
		{
			//数据前移覆盖即可
			Abs->personArray[i] = Abs->personArray[i+1];
		}
		Abs->m_Size--;  //更新通讯录人数
		cout<<"删除成功"<<endl;
	}

	system("pause");  //请按任意键继续
	system("cls");  //清屏
}

void Findperson(Addressbooks* Abs)
{
	cout<<"请输入要查找的联系人姓名："<<endl;
	string findname;
	cin >> findname;

	int result = Judgeperson(Abs, findname);
	if (result==-1)
	{
		cout<<"查无此人"<<endl;
	}
	else
	{
		cout << "序号：" << result + 1 << "\t";  //用水平制表符\t更美观
		cout << "姓名：" << Abs->personArray[result].m_Name << "\t";
		cout << "性别：" << (Abs->personArray[result].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << Abs->personArray[result].m_Age << "\t";
		cout << "电话号码：" << Abs->personArray[result].m_Phone << "\t";
		cout << "住址：" << Abs->personArray[result].m_Address << endl;
	}

	system("pause");  //请按任意键继续
	system("cls");  //清屏
}

void Modperson(Addressbooks* Abs)
{
	cout<<"请输入要修改的联系人姓名："<<endl;
	string name;
	cin >> name;

	int ret = Judgeperson(Abs,name);
	if (ret == -1)
		cout << "查无此人" << endl;
	else
	{
		//修改姓名
		string modname;
		cout << "请输入修改后的姓名：" << endl;
		cin >> modname;
		Abs->personArray[ret].m_Name = modname;

		//修改性别
		int modsex = 0;
		cout << "请输入修改后的性别：" << endl;
		cout << "1--男   2--女" << endl;
		cin >> modsex;
		Abs->personArray[ret].m_Age = modsex;

		//修改年龄
		int modage = 0;
		cout << "请输入修改后的年龄：" << endl;
		cin >> modage;
		Abs->personArray[ret].m_Age = modage;

		//修改电话号码
		string modphone;
		cout << "请输入修改后的电话号码：" << endl;
		cin >> modphone;
		Abs->personArray[ret].m_Phone = modphone;

		//修改住址
		string modaddress;
		cout << "请输入修改后的住址：" << endl;
		cin >> modaddress;
		Abs->personArray[ret].m_Address = modaddress;

		cout<<"修改成功"<<endl;
	}

	system("pause");  //请按任意键继续
	system("cls");  //清屏
}

void Empty(Addressbooks* Abs)
{
	cout << "确定要清空所有联系人吗？" << endl;
	cout << "确定请输入1  取消请按任意键" << endl;
	int button = 0;
	cin >> button;
	if (button == 1)
	{
		Abs->m_Size = 0;
		cout << "清空成功" << endl;
	}

	system("pause");  //请按任意键继续
	system("cls");  //清屏
}

int Judgeperson(Addressbooks* Abs, string name)  //存在则返回联系人在通讯录的位置，不存在则返回-1 
{
	for (int i = 0;i < Abs->m_Size;i++)
	{
		if (Abs->personArray[i].m_Name == name)
		{
			return i;  //找到了返回数组下标
		}
	} 
	return -1;  //遍历结束未找到，返回-1
}
