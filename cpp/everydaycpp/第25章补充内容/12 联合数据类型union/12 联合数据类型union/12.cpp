#include <iostream>
#include <string>
using namespace std;
union people
{
	char name;
	short int age;
	float weight;
};
void show(people);
int main()
{
	people Jack={'x'};
	show(Jack);

}
void show(people p)
{
	cout<<p.name<<endl;
	cout<<p.age<<endl;
	cout<<p.weight<<endl;
}
