//例19.4.2  在book类中增加输出语句
#include"String.h"
class book 
{
public:
	book();
	~book(){cout<<"book类析构函数执行\n";}
	book(char*,char*,char*,float);
	const String&GetTitle()const{return title;}
	String&GetTitle(){return title;}
	const String&GetAuthor()const{return author;}
    String&GetAuthor(){return author;}
	const String&GetNumber()const{return number;}
	float GetPrice()const{return price;}
	void SetTitle(const String&Stitle){title=Stitle;}
	void SetAuthor(const String&Sauthor){author=Sauthor;}
	void SetNumber(const String&Snumber){number=Snumber;}
	void SetPrice(float Sprice){price=Sprice;}
	void SetTotal(const String&ST,const String&SA,const String&SN,float SP){title=ST;author=SA,number=SN,price=SP;}
	book&operator=(const book&s);
private:
	String title;
	String author;
	String number;
    float price;
};
book::book():
title(""),
author(""),
number(""),
price(0)
{cout<<"book类默认构造函数执行\n";}
book::book(char*Title,char*Author,char*Number,float Price):
title(Title),
author(Author),
number(Number),
price(Price)
{cout<<"book类构造函数执行\n";}
book&book::operator=(const book&s)
{
	cout<<"book类operator=()函数执行\n";
    title=s.GetTitle();
	author=s.GetAuthor();
	number=s.GetNumber();
	price=s.GetPrice();
	return *this;
}
int main()
{
	book love("love","Jacky","001",34.1f);
	book hate("hat","Mick","002",56.2f);
	String LoveAndHate=love.GetAuthor()+hate.GetAuthor();
	cout<<"LoveAndHate的作者："<<LoveAndHate<<endl;
	love.SetAuthor(LoveAndHate);
	cout<<love.GetTitle()<<"的作者："<<love.GetAuthor()<<endl;
	return 0;
}
