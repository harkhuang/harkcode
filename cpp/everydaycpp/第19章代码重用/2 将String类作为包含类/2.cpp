//例19.2.2   图书类book

#include"String.h"
class book 
{
public:
	book();
	book(char*,char*,char*,float);
	const String&GetTitle()const{return title;}
	const String&GetAuthor()const{return author;}
	const String&GetNumber()const{return number;}
	float GetPrice()const{return price;}
	void SetTitle(const String&Stitle){title=Stitle;}
	void SetAuthor(const String&Sauthor){author=Sauthor;}
	void SetNumber(const String&Snumber){number=Snumber;}
	void SetPrice(float Sprice){price=Sprice;}
	void SetTotal(const String&ST,const String&SA,const String&SN,float SP){title=ST;author=SA,number=SN,price=SP;}
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
{}
book::book(char*Title,char*Author,char*Number,float Price):
title(Title),
author(Author),
number(Number),
price(Price)
{}
int main()
{
	book love("love","Jacky","001",34.1f);
	cout<<"书名："<<love.GetTitle()<<"作者："<<love.GetAuthor()<<"编号："<<love.GetNumber()<<"价格："<<love.GetPrice()<<endl;
	love.SetTotal("hat","Mick","002",56.2f);
	cout<<"书名："<<love.GetTitle()<<"作者："<<love.GetAuthor()<<"编号："<<love.GetNumber()<<"价格："<<love.GetPrice()<<endl;
	book hate=love;
	cout<<"书名："<<hate.GetTitle()<<"作者："<<hate.GetAuthor()<<"编号："<<hate.GetNumber()<<"价格："<<hate.GetPrice()<<endl;
	if(love.GetNumber()==hate.GetNumber())
		cout<<"两本书的编号相同。\n";
	else
		cout<<"两本书的编号不同。\n";
	hate.SetNumber("003");
	if(love.GetNumber()==hate.GetNumber())
		cout<<"两本书的编号相同。\n";
	else
		cout<<"两本书的编号不同。\n";
	return 0;
}
