#include <iostream>
using namespace std;

/*�Ž�  �������Ǵ�����ͬ��ɫ��״��ͬ�Ĵ���*/

//��ˢ�ӿ�
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

//����
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

//ʵ�ִ��� (�����˵�,�Ի���,ѡ��˵�������һ��)
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
    //��ˢ���
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


//������һ���ֻ�ѡ���Ե�ӵ�в�ͬ�����
int main(int argc,char* argv[])
{
    //ʵ��һ��ˢ��
    Brush* imp = new ConcreteRedBrush();
    //����ˢ��ʵ��һ������
    Windows* abs = new RefinedWindows(imp);
    //����ˢ�Ӳ�ͬ ���岻ͬ��������ʵ�岻ͬ
    abs->Operation();
    return 0;
}