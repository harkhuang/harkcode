#include <iostream>
#include <string>
using namespace std;
template<class T>
class human
{
public:
	human(){}
	T GetAge(){return age;}
	T GetStr(){return name;}
	void SetAge(T &a){age=a;}
	void SetStr(T &s){name=s;}
private:
	T name;
	T age;
};
template<template<class T>class T1>
class people 
{
public:
	people(){}
	int GetAge(){return  s1.GetAge();}
	void SetAge(int &a){s1.SetAge(a);}
	string GetStr(){return s2.GetStr();}
	void SetStr(string &s){s2.SetStr(s);}
private:
	T1<int>s1;
	T1<string>s2;
};
int main()
{
	people<human>Jack;
	int i=8;
	string str="hello";
	Jack.SetAge(i);
	cout<<Jack.GetAge()<<endl;
	Jack.SetStr(str);
	cout<<Jack.GetStr()<<endl;
	system("pause");
	return 0;
}
