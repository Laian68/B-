//Copyright Laian 2021-2022. [All Rights Reserved]
//������־��v1.5��2022/8/5��1.����getch()��2.�޸���֪bug�������û����� 
#include<bits/stdc++.h>
#include<conio.h>
#include<unistd.h>
using namespace std;

string str,pin="..12.1",pinc,zl;
void play(string output)
{
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i];
		usleep(50000);
	}
}
void lock()
{
	int x=-2,i;
	for(i=0;i<str.size();i++)
	{
		str[i]+=x;
		x=-x;
	}
}
void unlock()
{
	int x=2,i;
	for(i=0;i<str.size();i++)
	{
		str[i]+=x;
		x=-x;
	}
}
void un()
{
	int x=0xff;
	for(int i=0;i<6;i++) pin[i]+=(-x);
}
int main()
{
	system("title �ַ������ܽ��ܹ��� v1.5");
	cout<<"��1���ܣ���2���ܣ��������\n";
	zl=getch();
	un();
	if(zl!="1"&&zl!="2")
	{
		cout<<"Oops! Be serious!\n";
		system("pause");
		return 0;
	}
	un();
	if(zl=="1")
	{
		system("cls");
		cout<<"����������ַ�����\n";
		cin>>str;
		lock();
		system("cls");
		cout<<"[Result]\n";
		cout<<str<<endl<<endl;
		system("pause");
	}
	else
	{
		system("cls");
		cout<<"����pin���Լ�����";
		cin>>pinc;
		un();
		if(pin!=pinc)
		{
			cout<<"Oops! The pin you just input is WRONG!\n";
			system("pause");
			return 0;
		}
		system("cls");
		play("��ȷ��\n�𾴵Ĺ���Ա�û���������������ַ�����\n");
		cin>>str;
		unlock();
		system("cls");
		play("[Result]\n");
		play(str);
		cout<<endl<<endl;
		system("pause");
	}
	return 0;
}
