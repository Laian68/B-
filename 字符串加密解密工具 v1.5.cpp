//Copyright Laian 2021-2022. [All Rights Reserved]
//更新日志：v1.5（2022/8/5）1.引进getch()；2.修复已知bug，增进用户体验 
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
	system("title 字符串加密解密工具 v1.5");
	cout<<"按1加密，按2解密，输入命令：\n";
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
		cout<<"输入待加密字符串：\n";
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
		cout<<"输入pin码以继续：";
		cin>>pinc;
		un();
		if(pin!=pinc)
		{
			cout<<"Oops! The pin you just input is WRONG!\n";
			system("pause");
			return 0;
		}
		system("cls");
		play("正确！\n尊敬的管理员用户，请输入待加密字符串：\n");
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
