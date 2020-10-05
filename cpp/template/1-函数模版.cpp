#include <iostream>
#include <vector>
#include <initializer_list>
#include <list>


using namespace std;
/*
范性利用
4行代码代替很多情况
*/

// T 是一种型别 不是类型.

template <class T , class T2>
bool Max(T t1,T2 t2)
{
    return t1 > t2;
}

const int DefaultStackSize = 1024;
template <class T, int  size= DefaultStackSize>

class MyStack{
    public:
    MyStack(T m, int size1):m_maxsize(size1),m_member(m){

    }

    void push(const T& element){
        m_member.push_back(element);
    }
    void pop(T &ele)
    {
        ele = m_member.pop_front();
        m_member.pop();
    }
    private:
    T m_member;
     int m_maxsize;
};




template< class Typ, int MaxStack >
class Stack {
   int EmptyStack;
   Typ items[MaxStack];
   int top;
public:
   Stack();
   ~Stack();
   void push(Typ);
   Typ pop();
   int empty();
   int full();
};


template< class Typ, int MaxStack >
Stack< Typ, MaxStack >::Stack() {
   EmptyStack = -1;
   top = EmptyStack;
}

template< class Typ, int MaxStack >
Stack< Typ, MaxStack >::~Stack()
{  delete[] items; }

template< class Typ, int MaxStack >
void Stack< Typ, MaxStack >::push(Typ c)
{  items[ ++top ] = c; }

template< class Typ, int MaxStack >
Typ Stack< Typ, MaxStack >::pop()
{  return items[ top-- ]; }

template< class Typ, int MaxStack >
int Stack< Typ, MaxStack >::full()
{  return top + 1 == MaxStack; }

template< class Typ, int MaxStack >
int Stack< Typ, MaxStack >::empty()
{  return top == EmptyStack; }



int test_STCAK() {
   Stack<char, 10> s; // 10 chars
   char ch;
   while ((ch = cin.get()) != '\n')
      if (!s.full()) s.push(ch);
   while (!s.empty())
      cout << s.pop();
   cout << endl;
   Stack<double, 4> ds; // 4 doubles
   double d[] =
      {1.0, 3.0, 5.0, 7.0, 9.0, 0.0};
   int i = 0;
   while (d[i] != 0.0 && !ds.full())
      if (!ds.full()) ds.push(d[i++]);
   while (!ds.empty())
      cout << ds.pop() << "  ";
   cout << endl;
   return 0;
}

int main(int argc, const char** argv) {

    test_STCAK();
    if(Max(1,2))
    {
        std::cout<< "1 > 2"<<std::endl;
    }
    else
    {
        std::cout<< "1 < 2" <<std::endl;
    }


    if(Max('a','b'))
    {
        std::cout<< "a > b"<<std::endl;
    }
    else
    {
        std::cout<< "a < b" <<std::endl;
    
    }


    if(Max(1,'b'))
    {
        std::cout<< "a > b"<<std::endl;
    }
    else
    {
        std::cout<< "a < b" <<std::endl;
    
    }

    //std::list<int> v = { 1, 2, 3, 4, 5 }; 
    std::vector<int > v= {1,2,3,5};
    //Stack(v,v.size());

   // MyStack<std::vector<int > ,int > x(v,5);

    return 0;
}