/*
#include <iostream>
using namespace std;
int main()
{
	char man[12];
	cin>>man;
	cout<<man<<endl;
	return 0;
}
*/
/*
#include <iostream>
using namespace std;
int main()
{
	char man[12];
	cin.get(man,12);
	cout<<man<<endl;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main()
{
	char man[]={'H','e','l','l','o',0,'w','o','r','l','d','\0'};
	cout<<man<<endl;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
int main()
{
	char man[12]={'H','e','l','l','o',' ','w','o','r','l','d','\0'};
	cout<<man<<endl;
	return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{
	char man[12]={"Hello world"};
	cout<<man<<endl;
	cout<<"strlen(man)£º"<<strlen(man)<<endl;
	cout<<"sizeof(man)£º"<<sizeof(man)<<endl;
	man[5]='\0';
	cout<<man<<endl;
	cout<<"strlen(man)£º"<<strlen(man)<<endl;
	cout<<"sizeof(man)£º"<<sizeof(man)<<endl;
	return 0;
}
