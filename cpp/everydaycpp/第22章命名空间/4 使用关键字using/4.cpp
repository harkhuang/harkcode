/*
#include <iostream>
using namespace std;
namespace num
{
	int x=10;
	int y=20;
}
int main()
{
	using namespace num;
	cout<<"x:"<<x<<" y:"<<y<<endl;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
namespace num
{
	int x=10;
	int y=20;
}
int main()
{
	{
		using namespace num;
		cout<<"x:"<<x<<" y:"<<y<<endl;
	}
	cout<<"x:"<<x<<" y:"<<y<<endl;   //´íÎó
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
namespace num1
{
	int x=10;
	int y=20;
}
namespace num2
{
	int x=30;
	int y=40;
}
int main()
{
	using namespace num1;
	using namespace num2;
	cout<<"x:"<<x<<" y:"<<y<<endl;
	return 0;
}
*/


/*
#include <iostream>
using namespace std;
namespace num1
{
	int x=10;
	int y=20;
}
namespace num2
{
	int x=30;
	int y=40;
}
int main()
{
	using  num1::x;
	using  num2::y;
	cout<<"x:"<<x<<" y:"<<y<<endl;
	return 0;
}
*/

/*
#include <iostream>
using namespace std;
namespace num1
{
	int x=10;
}
namespace num2
{
	int x=30;
}
int main()
{
	using  num1::x;
	using  num2::x;
	cout<<"x:"<<x<<endl;
	return 0;
}
*/

#include <iostream>
using namespace std;
namespace num
{
	int x=10;
}
int main()
{
	int x=5;
	using namespace num;
	cout<<"x:"<<x<<endl;
	return 0;
}
