//������Ϊģ��ͨѶ¼����ϵͳ
//���������в˵�����ӡ���ʾ��ɾ�������ҡ��޸ġ���ա��˳�

#include <iostream>
#include <string>
#define MAX 1000

using namespace std;

struct Person
{
	string m_Name;  //����
	int m_Sex;  //�Ա�1-�� 2-Ů
	int m_Age;  //����
	string m_Phone;  //�绰����
	string m_Address;  //סַ
};

struct Addressbooks
{
	Person personArray[MAX];  //ͨѶ¼�������ϵ����
	int m_Size;  //��ǰͨѶ¼�е���ϵ����
};

void Menu();  //�˵�
void Exit();  //�˳�
void Addperson(Addressbooks* Abs);  //���
void Showperson(Addressbooks* Abs);  //��ʾ
void Deleteperson(Addressbooks* Abs);  //ɾ��
void Findperson(Addressbooks* Abs);  //����
void Modperson(Addressbooks* Abs);  //�޸�
void Empty(Addressbooks* Abs);  //���
int Judgeperson(Addressbooks* Abs,string name);  //�ж���ϵ���Ƿ����

int main()
{
	//����ͨѶ¼���͵ı���
	Addressbooks Abs;
	//��ʼ����Ա����
	Abs.m_Size = 0;

	//��ʼ���û�ѡ��ʱ������
	int number = 0;
	
	while (true)
	{
		Menu(); //�˵�

		cin >> number;

		switch (number)//�����û������ṩ��ͬ�Ĺ���
		{
		case 1:  //���
			Addperson(&Abs);
			break;
		case 2: 
			Showperson(&Abs);//��ʾ
			break;
		case 3:  //ɾ��
		    Deleteperson(&Abs);
		    break;
		case 4:  //����
			Findperson(&Abs);
			break;
		case 5:  //�޸�
			Modperson(&Abs);
			break;
		case 6:  //���
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
	cout << "*****1.�����ϵ��*****" << endl;
	cout << "*****2.��ʾ��ϵ��*****" << endl;
	cout << "*****3.ɾ����ϵ��*****" << endl;
	cout << "*****4.������ϵ��*****" << endl;
	cout << "*****5.�޸���ϵ��*****" << endl;
	cout << "*****6.�����ϵ��*****" << endl;
	cout << "*****            *****" << endl;
	cout << "*****0.�˳�***********" << endl;
	cout << "**********************" << endl;
}

void Exit()
{
	cout << "�˳��ɹ�����ӭ�´�ʹ��" << endl;
	system("pause");
}

void Addperson(Addressbooks* Abs)
{
	//���ж�ͨѶ¼�Ƿ������������򱨴�
	if (Abs->m_Size == MAX)
	{
		cout << "ͨѶ¼����������ʧ��" << endl;
	}
	else 
	{
		//�����ϵ�˾�����Ϣ
		//����
		string name;
		cout << "����������" << endl;
		cin >> name;
		Abs->personArray[Abs->m_Size].m_Name = name;

		//�Ա�
		int sex;
		cout << "�������Ա�" << endl;
		cout << "1--��   2--Ů" << endl;
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
				cout << "��������" << endl;
		}*/

		//����
		int age;
		cout << "����������" << endl;
		cin >> age;
	    Abs->personArray[Abs->m_Size].m_Age = age;

		//�绰����
		string phonenumber;
		cout << "������绰����" << endl;
		cin >> phonenumber;
		Abs->personArray[Abs->m_Size].m_Phone = phonenumber;

		//סַ
		string address;
		cout << "������סַ" << endl;
		cin >> address;
		Abs->personArray[Abs->m_Size].m_Address = address;

		//����ͨѶ¼��ǰ����
		Abs->m_Size++;

		cout << "��ӳɹ�" << endl;
	}

	system("pause");  //�밴���������
	system("cls");  //����
}

void Showperson(Addressbooks* Abs)
{
	//�ж������Ƿ�Ϊ0��Ϊ0��ʾΪ��
	//����Ϊ0����ʾ���м�¼����Ϣ
    
	if (Abs->m_Size == 0)
		cout<<"ͨѶ¼Ϊ��"<<endl;
	else
	{
		for (int i = 0;i < Abs->m_Size;i++)
		{
			cout << "��ţ�" << i + 1 << "\t";  //��ˮƽ�Ʊ��\t������
			cout << "������" << Abs->personArray[i].m_Name << "\t";
			/*if (Abs->personArray[i].m_Sex == 1)//ע���Ա���ʾ�Ľ��
				cout << "�Ա���" << "\t";
			else if (Abs->personArray[i].m_Sex == 2)
				cout << "�Ա�Ů" << "\t";*/
			//����Ŀ������Ż�
			cout << "�Ա�" << (Abs->personArray[i].m_Sex==1 ? "��":"Ů") <<"\t";

			cout << "���䣺" << Abs->personArray[i].m_Age << "\t";
			cout << "�绰���룺" << Abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << Abs->personArray[i].m_Address << endl;
			cout <<"-----"<< endl;
		}
	}

	system("pause");  //�밴���������
	system("cls");  //����
}

void Deleteperson(Addressbooks* Abs)
{
	cout << "������Ҫɾ����ϵ�˵�������" << endl;
	string deletename;
	cin >> deletename;
	if (Judgeperson(Abs, deletename) == -1)  //δ�鵽
		cout << "���޴���" << endl;
	else  //�鵽����ɾ����ǰ������ɾ��λ�ú������
	{
		for (int i = Judgeperson(Abs, deletename);i < Abs->m_Size;i++)
		{
			//����ǰ�Ƹ��Ǽ���
			Abs->personArray[i] = Abs->personArray[i+1];
		}
		Abs->m_Size--;  //����ͨѶ¼����
		cout<<"ɾ���ɹ�"<<endl;
	}

	system("pause");  //�밴���������
	system("cls");  //����
}

void Findperson(Addressbooks* Abs)
{
	cout<<"������Ҫ���ҵ���ϵ��������"<<endl;
	string findname;
	cin >> findname;

	int result = Judgeperson(Abs, findname);
	if (result==-1)
	{
		cout<<"���޴���"<<endl;
	}
	else
	{
		cout << "��ţ�" << result + 1 << "\t";  //��ˮƽ�Ʊ��\t������
		cout << "������" << Abs->personArray[result].m_Name << "\t";
		cout << "�Ա�" << (Abs->personArray[result].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺" << Abs->personArray[result].m_Age << "\t";
		cout << "�绰���룺" << Abs->personArray[result].m_Phone << "\t";
		cout << "סַ��" << Abs->personArray[result].m_Address << endl;
	}

	system("pause");  //�밴���������
	system("cls");  //����
}

void Modperson(Addressbooks* Abs)
{
	cout<<"������Ҫ�޸ĵ���ϵ��������"<<endl;
	string name;
	cin >> name;

	int ret = Judgeperson(Abs,name);
	if (ret == -1)
		cout << "���޴���" << endl;
	else
	{
		//�޸�����
		string modname;
		cout << "�������޸ĺ��������" << endl;
		cin >> modname;
		Abs->personArray[ret].m_Name = modname;

		//�޸��Ա�
		int modsex = 0;
		cout << "�������޸ĺ���Ա�" << endl;
		cout << "1--��   2--Ů" << endl;
		cin >> modsex;
		Abs->personArray[ret].m_Age = modsex;

		//�޸�����
		int modage = 0;
		cout << "�������޸ĺ�����䣺" << endl;
		cin >> modage;
		Abs->personArray[ret].m_Age = modage;

		//�޸ĵ绰����
		string modphone;
		cout << "�������޸ĺ�ĵ绰���룺" << endl;
		cin >> modphone;
		Abs->personArray[ret].m_Phone = modphone;

		//�޸�סַ
		string modaddress;
		cout << "�������޸ĺ��סַ��" << endl;
		cin >> modaddress;
		Abs->personArray[ret].m_Address = modaddress;

		cout<<"�޸ĳɹ�"<<endl;
	}

	system("pause");  //�밴���������
	system("cls");  //����
}

void Empty(Addressbooks* Abs)
{
	cout << "ȷ��Ҫ���������ϵ����" << endl;
	cout << "ȷ��������1  ȡ���밴�����" << endl;
	int button = 0;
	cin >> button;
	if (button == 1)
	{
		Abs->m_Size = 0;
		cout << "��ճɹ�" << endl;
	}

	system("pause");  //�밴���������
	system("cls");  //����
}

int Judgeperson(Addressbooks* Abs, string name)  //�����򷵻���ϵ����ͨѶ¼��λ�ã��������򷵻�-1 
{
	for (int i = 0;i < Abs->m_Size;i++)
	{
		if (Abs->personArray[i].m_Name == name)
		{
			return i;  //�ҵ��˷��������±�
		}
	} 
	return -1;  //��������δ�ҵ�������-1
}
