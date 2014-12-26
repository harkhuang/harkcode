#include <iostream>
using namespace std;
class human
{
public:
	void get_stature(){cout<<stature;}
	void GetWeight();
	void SetStature(int x){stature=x;}
	void SetWeight(int x);
private:
	int stature;
	int weight;
};
void human::GetWeight()
{
	cout<<weight;
}
void human::SetWeight(int x)
{
	weight=x;
}
void main()
{
	human Mike;
	Mike.SetStature(8);
	cout<<"迈克的身高";
	Mike.get_stature();
	cout<<endl;
	Mike.SetWeight(80);
	cout<<"迈克的体重";
	Mike.GetWeight();
}