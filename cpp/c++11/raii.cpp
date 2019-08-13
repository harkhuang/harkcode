// TODO:
/*

如何使用RAII？
当我们在一个函数内部使用局部变量，
当退出了这个局部变量的作用域时，
这个变量也就被销毁了；
当这个变量是类对象时，
这个时候，
就会自动调用这个类的析构函数，
而这一切都是自动发生的，
不要程序员显示的去调用完成。
这个也太好了，RAII就是这样去完成的。
由于系统的资源不具有自动释放的功能，
而C++中的类具有自动调用析构函数的功能。
如果把资源用类进行封装起来，
对资源操作都封装在类的内部，
在析构函数中进行释放资源。
当定义的局部变量的生命结束时，
它的析构函数就会自动的被调用，
如此，
就不用程序员显示的去调用释放资源的操作了。

 */



/// 使用raii 的代码

#include <iostream> 
using namespace std; 

class ArrayOperation 
{ 
public : 
    ArrayOperation() 
    { 
        m_Array = new int [10]; 
    } 

    void InitArray() 
    { 
        for (int i = 0; i < 10; ++i) 
        { 
            *(m_Array + i) = i; 
        } 
    } 

    void ShowArray() 
    { 
        for (int i = 0; i <10; ++i) 
        { 
            cout<<m_Array[i]<<endl; 
        } 
    } 

    ~ArrayOperation() 
    { 
        cout<< "~ArrayOperation is called" <<endl; 
        if (m_Array != NULL ) 
        { 
            delete[] m_Array;  // 非常感谢益可达非常犀利的review，详细可以参加益可达在本文的评论 2014.04.13
            m_Array = NULL ; 
        } 
    } 

private : 
    int *m_Array; 
}; 

bool OperationA(); 
bool OperationB(); 

int main() 
{ 
    ArrayOperation arrayOp; 
    arrayOp.InitArray(); 
    arrayOp.ShowArray(); 
    return 0;
}



// 如果不适用
#include <iostream> 
using namespace std; 

bool OperationA(); 
bool OperationB(); 

int main() 
{ 
    int *testArray = new int [10]; 

    // Here, you can use the array 
    if (!OperationA()) 
    { 
        // If the operation A failed, we should delete the memory 
        delete [] testArray; 
        testArray = NULL ; 
        return 0; 
    } 

    if (!OperationB()) 
    { 
        // If the operation A failed, we should delete the memory 
        delete [] testArray; 
        testArray = NULL ; 
        return 0; 
    } 

    // All the operation succeed, delete the memory 
    delete [] testArray; 
    testArray = NULL ; 
    return 0; 
} 

bool OperationA() 

{ 
    // Do some operation, if the operate succeed, then return true, else return false 
    return false ; 
} 

bool OperationB() 

{ 
    // Do some operation, if the operate succeed, then return true, else return false 
    return true ; 
}

