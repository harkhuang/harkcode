#include<iostream>  
using namespace std;  
int v[11] = {0,1,5,8,9,10,17,17,20,24,30};  
int cut_rod(int n)//������Ž�Ϊp���Ҷ˸ְ�ʣ�೤��n�����Ҷ˼����и�   
{  
    if(n==0)return 0;  
    int q = -99999999;  
    for(int i=1;i<=n;i++)  
        q = max(q,v[i]+cut_rod(n-i));//cut_rod(n)���س���Ϊn�ĸְ������ܻ�õ�����ֵ   
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