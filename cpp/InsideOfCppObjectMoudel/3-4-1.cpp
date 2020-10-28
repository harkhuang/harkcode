// 3-4 Data Member 之多从继承


#include <iostream>

class Point2d{
    public:
    virtual void  foo_Point2d() {};
    protected:
    float x_ , y_ ;
};


class Point3d :public Point2d{
    public:
    protected:
    float z_;
};

class Vertex{
    public: 
     virtual void  foo_Vertex() {};

     protected:
     Vertex *next;
};

class Vertex3d : public Vertex , public Point3d{
    public:
    protected:
    float _mumble;
};


void  mumble(const Vertex &){

}




int main()
{
    Vertex3d v;

    mumble(v); // 这种调用是不自然的.
    return 0;
}