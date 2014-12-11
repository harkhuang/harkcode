#include <iostream>
using namespace std;
class rectangle
{
public:
	class point
	{
	public:
		void setx(int x){itsx=x;}
		void sety(int y){itsy=y;}
		int getx()const{return itsx;}
		int gety()const{return itsy;}
	private:
		int itsx;
		int itsy;
	};
	    point GetUpLeft()const{return upleft;}
        point GetLowLeft()const{return lowerleft;}
		point GetUpRight()const{return upright;}
		point GetLowRight()const{return lowerright;}

	rectangle(int top,int left,int bottom,int right);
	~rectangle(){}

	int GetTop()const{return Top;}
	int GetLeft()const{return Left;}
	int GetBottom()const{return Bottom;}
	int GetRight()const{return Right;}

	void SetUpLeft(){upleft.setx(Left);upleft.sety(Top);}
	void SetLowLeft(){lowerleft.setx(Left);lowerleft.sety(Bottom);}
	void SetUpRight(){upright.setx(Right);upright.sety(Top);}
	void SetLowRight(){lowerright.setx(Right);lowerright.sety(Bottom);}

	void SetTop(int top){Top=top;}
	void SetLeft(int left){Left=left;}
	void SetRight(int right){Right=right;}
	void SetBottom(int bottom){Bottom=bottom;}

	int GetArear()const{int width=Right-Left;int height=Bottom-Top;return (width*height);}
    	
private:
	point upleft;	
	point lowerleft;
	point upright;
    point lowerright;

   int Top;
   int Left;
   int Bottom;
   int Right;	
};
rectangle::rectangle(int top,int left,int bottom,int right)
{
	Top=top;
	Left=left;
	Bottom=bottom;
	Right=right;

	upleft.setx(Left);
	upleft.sety(Top);

	upright.setx(Right);
	upright.sety(Top);

	lowerright.setx(Right);
	lowerright.sety(Bottom);

	lowerleft.setx(Left);
	lowerleft.sety(Bottom);
}
	class point 
	{
	public:
		int GetArear (rectangle &rec){return rec.GetArear();}
	};

int main()
{
	rectangle date(40,50,60,80);
	cout<<"左边为："<<date.GetLeft()<<endl;
	cout<<"下边为："<<date.GetBottom()<<endl;
	cout<<"左下的X坐标为："<<date.GetLowLeft().getx()<<endl;
	cout<<"左下的y坐标为："<<date.GetLowLeft().gety()<<endl;
	cout<<"矩形面积为:"<<date.GetArear()<<endl;
	cout<<"重新设置Left和Bottom值"<<endl;
	date.SetLeft(0);
	date.SetBottom(100);
	date.SetLowLeft();
	cout<<"左边为："<<date.GetLeft()<<endl;
	cout<<"下边为："<<date.GetBottom()<<endl;
	cout<<"左下的X坐标为："<<date.GetLowLeft().getx()<<endl;
	cout<<"左下的y坐标为："<<date.GetLowLeft().gety()<<endl;
	point pt;
	cout<<"矩形面积为:"<<pt.GetArear(date)<<endl;
	return 0;
}