#include<iostream.h>
#include<string.h>
const int UMPIRE=4;
const int N=20;
class Result
{ 
private:
	int num;
	char name[N];
	double score[UMPIRE],max,min,aver; 
public:
	Result(void);          
	Result(int nu,char na[],double x[],int n);
	void set_Result(int nu,char na[],double x[],int n);
	double Max(void)
	{
		return score[UMPIRE-1];
	}
	double Min(void)
	{
		return score[0];
	}
	void sort(void)
	{ 
		int i,j;double t;   
		for (j=0;j<UMPIRE-1;i++)   
		{ 
			for (i=0;i<UMPIRE-j-1;j++)
				if (score[i]>score[i+1])
				{
					t=score[i];score[i]=score[i+1];score[i+1]=t;
				}
		}
	}
	double get_Result(int i)       
    {
		return score[i];
	}
    double get_aver(void)           
	{
		int i;double sum=0;
		for(i=0;i<UMPIRE;i++)
		{ 
			sum+=score[i];
		}
		max=Max();
		min=Min();
		aver=(sum-max-min)/(UMPIRE-2);
		return aver;
	}
	void print_Result(void);
	
};
Result::Result(void)             
{ 
	int i;num=0;
	strcpy(name,"xxx");
	for(i=0;i<UMPIRE;i++)
		score[i]=0;
	max=0;
	min=0;
	aver=0;
}
void Result::set_Result(int nu,char na[],double x[],int n)  
{ 
	int i;double sum=0;
	num=nu;strcpy(name,na);
	for(i=0;i<UMPIRE;i++)
	{
		score[i]=x[i];sum+=score[i];
	}
	max=Max();
	min=Min();
	aver=(sum-max-min)/(UMPIRE-2);
}
void Result::print_Result(void)
{ 
	int i;
	cout<<num<<"  "<<name<<endl;
	for(i=0;i<UMPIRE;i++)
		cout<<"  "<<score[i];
	cout<<endl;
	cout<<"ȥ��һ����߷�:"<<max<<"  ȥ��һ����ͷ�:"<<min<<"  ѡ�ֵ����÷�:"<<aver<<endl; 
}
void print(Result *p,int n);
void input(Result *p,int n);
void sort(Result *p,int n);
void main(void)
{ 
	int n;
	cout<<"����ѡ������:";cin >>n;
	Result *p;
	p=new Result[n];  
	if(p==NULL)
	{ 
		cout<<"�ڴ����ʧ��"<<endl;
		return;
	}
	input(p,n);
	cout<<endl;
	cout<<"ѡ�ֵ÷�����:"<<endl;
	print(p,n);
	cout<<endl;
	cout<<"ѡ����������:"<<endl;
	for (int i=0;i<n;i++)
	{
		p[i].sort();
	}
	sort(p,n);
	print(p,n);     
	delete []p;
}
void input(Result *p,int n)     
{ 
	int i,j,Num;double x[UMPIRE];char Name[N];
	for(i=0;i<n;i++)
	{
		cout<<"������ʼ����ѡ���볡��ʼ����:"<<endl;
		cout<<"��"<<i+1<<"��ѡ�ֵı��:"<<endl;
		cin>>Num;
		cout<<"��"<<i+1<<"��ѡ�ֵ�����:"<<endl;
		cin>>Name;
		cout<<"�����Ϊ��"<<i+1<<"��ѡ�ִ��:"<<endl;
		for(j=0;j<UMPIRE;j++)
		{ 
			cout<<"��"<<j+1<<"�����еĴ��:";
			cin>>x[j];
		}
		p[i].set_Result(Num,Name,x,UMPIRE);
	}
}
void print(Result *p,int n)
{ 
	int i;
	for(i=0;i<n;i++)
		p[i].print_Result(); 
}
void sort(Result *p,int n)
{ 
	Result t;
	int i,j,k;
	for(i=1;i<n;i++)
	{ 
		for(j=0;j<i;j++)
			if(p[i].get_aver()>p[j].get_aver())
				break;t=p[i];
			for(k=i;k>j;k--)
				p[k]=p[k-1];
			p[j]=t;
	}
}
