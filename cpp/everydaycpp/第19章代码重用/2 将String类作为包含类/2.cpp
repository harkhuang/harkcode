//��19.2.2   ͼ����book

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
	cout<<"������"<<love.GetTitle()<<"���ߣ�"<<love.GetAuthor()<<"��ţ�"<<love.GetNumber()<<"�۸�"<<love.GetPrice()<<endl;
	love.SetTotal("hat","Mick","002",56.2f);
	cout<<"������"<<love.GetTitle()<<"���ߣ�"<<love.GetAuthor()<<"��ţ�"<<love.GetNumber()<<"�۸�"<<love.GetPrice()<<endl;
	book hate=love;
	cout<<"������"<<hate.GetTitle()<<"���ߣ�"<<hate.GetAuthor()<<"��ţ�"<<hate.GetNumber()<<"�۸�"<<hate.GetPrice()<<endl;
	if(love.GetNumber()==hate.GetNumber())
		cout<<"������ı����ͬ��\n";
	else
		cout<<"������ı�Ų�ͬ��\n";
	hate.SetNumber("003");
	if(love.GetNumber()==hate.GetNumber())
		cout<<"������ı����ͬ��\n";
	else
		cout<<"������ı�Ų�ͬ��\n";
	return 0;
}
