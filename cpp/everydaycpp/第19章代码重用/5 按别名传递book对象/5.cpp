//��19.5  �������밴ֵ����book����Ĳ�ͬ
#include"String.h"
class book 
{
public:
	book();
	~book(){cout<<"book����������ִ��\n";}
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
    book(const book&rs); //�����ĸ��ƹ��캯��
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
{cout<<"book��Ĭ�Ϲ��캯��ִ��\n";}
book::book(char*Title,char*Author,char*Number,float Price):
title(Title),
author(Author),
number(Number),
price(Price)
{cout<<"book�๹�캯��ִ��\n";}
book&book::operator=(const book&s)
{
	cout<<"book��operator=()����ִ��\n";
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
	cout<<"book�ิ�ƹ��캯��ִ��\n";
}
void print1(book one);
void print2(const book &two);
int main()
{
	book love("love","Jacky","001",34.1f);
	cout<<"����print1���hate\n";
	print1(love);
	cout<<"����print2���hate\n";
	print2(love);
	return 0;
}
void print1(book one)
{
	cout<<"������"<<one.GetTitle()<<"���ߣ�"<<one.GetAuthor()<<"��ţ�"<<one.GetNumber()<<"�۸�"<<one.GetPrice()<<endl;
}
void print2(const book &two)
{
	cout<<"������"<<two.GetTitle()<<"���ߣ�"<<two.GetAuthor()<<"��ţ�"<<two.GetNumber()<<"�۸�"<<two.GetPrice()<<endl;
}
