#include <iostream>
using namespace std;

/*桥接  举例就是创建不同颜色形状不同的窗口*/

//笔刷接口
class Brush
{
public:
    virtual ~Brush(){
    };
    virtual void Operation() = 0;
protected:
    Brush(){
    };
private:
};

//窗体
class Windows
{
public:
    virtual ~Windows(){
    };
    virtual void Operation() = 0;
protected:

    Windows(){
    };
private:
};

//实现窗体 (下拉菜单,对话框,选择菜单等其中一种)
class RefinedWindows:public Windows
{
public:
    //
    RefinedWindows(Brush* imp){
        cout<<"make Windows body"<<endl;
        _imp = imp;
    };
    ~RefinedWindows(){
    };
    void Operation(){
        _imp->Operation();
    };
protected:
private:
    //笔刷句柄
    Brush* _imp;
};

class ConcreteRedBrush:public Brush
{
public:
    ConcreteRedBrush(){
        cout<<"ConcreteRedBrush...."<<endl;
    };
    ~ConcreteRedBrush(){
    };
    virtual void Operation(){
        cout<<"brush the Windows Red"<<endl;
    };
protected:
private:
};
class ConcreteBrushGreen:public Brush
{
public:
    ConcreteBrushGreen(){
        cout<<"ConcreteBrushGreen...."<<endl;
    };
    ~ConcreteBrushGreen(){};
    virtual void Operation(){
        cout<<"brush the Windows Green"<<endl;
    };
protected:
private:
};



void Brush::Operation()
{
    cout<<"Brush....imp..."<<endl;
}


//可以让一个手机选择性的拥有不同的软件
int main(int argc,char* argv[])
{
    //实现一个刷子
    Brush* imp = new ConcreteRedBrush();
    //根据刷子实现一个窗体
    Windows* abs = new RefinedWindows(imp);
    //由于刷子不同 窗体不同构建出的实体不同
    abs->Operation();
    return 0;
}