#include <iostream>
#include <string>
using namespace std;

class Product
{
public:
	Product() {cout<< "Product "<<endl;};
	~Product(){cout<< "~Product "<<endl;};
protected:
private:
};

class ProductPart
{
public:
	ProductPart(){ cout<< "ProductPart "<<endl;};
	~ProductPart(){ cout<< "~ProductPart "<<endl;};
	ProductPart* BuildPart(){ return new ProductPart();}
protected:
private:
};
class Builder
{
public:
	virtual ~Builder() { cout<<"~Builder()"<<endl;};
	virtual void BuildPartA(const string& buildPara) = 0;
	virtual void BuildPartB(const string& buildPara) = 0;
	virtual void BuildPartC(const string& buildPara) = 0;
	virtual Product* GetProduct() = 0;
protected:
	Builder()  { cout<<"Builder()"<<endl;};
private:
};

class ConcreteBuilder:public Builder
{
public:
	ConcreteBuilder(){
		cout<<"ConcreteBuilder"<<endl;
	}
	~ConcreteBuilder(){
		cout<<"~ConcreteBuilder"<<endl;
	}
	void BuildPartA(const string& buildPara){
	cout<<"Step1:Build PartA..."<<buildPara<<endl;	
	};
	void BuildPartB(const string& buildPara){
	cout<<"Step1:Build PartB..."<<buildPara<<endl;	
	};
	void BuildPartC(const string& buildPara){
		cout<<"Step1:Build PartC..."<<buildPara<<endl;	
	};
	Product* GetProduct(){
		BuildPartA("pre-defined");
		BuildPartB("pre-defined");
		BuildPartC("pre-defined");
		return new Product();
	}
protected:
private:
};

class Director
{
public:
	Director(Builder* bld){
		_bld = bld;
	}
	~Director();
	void Construct(const string a,const string b,const string c){
		_bld->BuildPartA(a);
		_bld->BuildPartB(b);
		_bld->BuildPartC(c);
	}
protected:
private:
	Builder* _bld;
};

int main(int argc,char* argv[])
{
	Director* d = new Director(new ConcreteBuilder());
	d->Construct("a+","b+","a-");
	return 0;
}