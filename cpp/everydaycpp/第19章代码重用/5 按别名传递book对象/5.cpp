//例19.5  按别名与按值传递book对象的不同
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
	const String&GetNumber()const{return number;}
	float GetPrice()const{return price;}
	void SetTitle(const String&Stitle){title=Stitle;}
	void SetAuthor(const String&Sauthor){author=Sauthor;}
	void SetNumber(const String&Snumber){number=Snumber;}
	void SetPrice(float Sprice){price=Sprice;}
	void SetTotal(const String&ST,const String&SA,const String&SN,float SP){title=ST;author=SA,number=SN,price=SP;}
	book&operator=(const book&s);
    book(const book&rs); //新增的复制构造函数
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
book::book(const book&rs):
title(rs.GetTitle()),
author(rs.GetAuthor()),
number(rs.GetNumber()),
price(rs.GetPrice())
{
	cout<<"book类复制构造函数执行\n";
}
void print1(book one);
void print2(const book &two);
int main()
{
	book love("love","Jacky","001",34.1f);
	cout<<"调用print1输出hate\n";
	print1(love);
	cout<<"调用print2输出hate\n";
	print2(love);
	return 0;
}
void print1(book one)
{
	cout<<"书名："<<one.GetTitle()<<"作者："<<one.GetAuthor()<<"编号："<<one.GetNumber()<<"价格："<<one.GetPrice()<<endl;
}
void print2(const book &two)
{
	cout<<"书名："<<two.GetTitle()<<"作者："<<two.GetAuthor()<<"编号："<<two.GetNumber()<<"价格："<<two.GetPrice()<<endl;
}
