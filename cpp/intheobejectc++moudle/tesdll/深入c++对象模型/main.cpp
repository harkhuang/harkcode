/*****************************************************************************
* @brief    : 针对c++对象模型的研究
* @author   : huangkui
* @date     :  2017/4/6 8:31
* @version  : ver 1.0
* @inparam  : 
* @outparam : 
*****************************************************************************/
#include <iostream>
using namespace std;

class Point 
{ 
public: 
	Point()
	{
		
	}
	virtual ~Point()
	{
	
	}

	float x() const; 
	static int PointCount(){ return 0;} 
	void ppp()
	{
		cout<<"ppp"<<endl;
	}
protected: 
	virtual ostream& 
	print( ostream &os ) const
	{
		return os;
	}

	float _x; 
	static int _point_count; 
}; 



int main()
{
	Point b;

	(&(Point::ppp))();

	b.PointCount();
	return 0;
}




