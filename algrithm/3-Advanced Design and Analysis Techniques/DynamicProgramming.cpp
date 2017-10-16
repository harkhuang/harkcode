#include<iostream>  
using namespace std;  
int v[11] = {0,1,5,8,9,10,17,17,20,24,30};  
int cut_rod(int n)//左端最优解为p，右端钢板剩余长度n，对右端继续切割   
{  
    if(n==0)return 0;  
    int q = -99999999;  
    for(int i=1;i<=n;i++)  
        q = max(q,v[i]+cut_rod(n-i));//cut_rod(n)返回长度为n的钢棒，所能获得的最大价值   
    return q;  
}  
int main()  
{  
	int a;
	scanf("%d",&a);
	printf("%d",a);
    int p = 0;  
    for(int k=1;k<=10;k++)  
        cout<<cut_rod(k)<<endl;  

    getchar();
}  

/*
1
5
8
10
13
17
18
22
25
30
*/