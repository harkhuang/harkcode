#include <iostream>
using namespace std;
int main()
{
	char ch[5][5]={{' ',' ','*',' ',' '},{' ','*','*','*',' '},
	{'*','*','*','*','*'},{' ','*','*','*',' '},{' ',' ','*',' ',' '}};
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
			cout<<ch[i][j];
		cout<<"\n";
	}
	return 0;
}