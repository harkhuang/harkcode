#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

CRITICAL_SECTION cs;
int gGlobal = 0;

class MyLock
{
public:
    MyLock()
    {
        EnterCriticalSection(&cs);
    }

    ~MyLock()
    {
        LeaveCriticalSection(&cs);
    }

private:
    MyLock( const MyLock &);
    MyLock operator =(const MyLock &);
};

void DoComplex(MyLock &lock ) // 非常感谢益可达犀利的review 2014.04.13
{
}

unsigned int __stdcall ThreadFun(PVOID pv) 
{
    MyLock lock;
    int *para = (int *) pv;

    // I need the lock to do some complex thing
    DoComplex(lock);

    for (int i = 0; i < 10; ++i)
    {
        ++gGlobal;
        cout<< "Thread " <<*para<<endl;
        cout<<gGlobal<<endl;
    }
    return 0;
}

int main()
{
    InitializeCriticalSection(&cs);

    int thread1, thread2;
    thread1 = 1;
    thread2 = 2;

    HANDLE handle[2];
    handle[0] = ( HANDLE )_beginthreadex(NULL , 0, ThreadFun, ( void *)&thread1, 0, NULL );
    handle[1] = ( HANDLE )_beginthreadex(NULL , 0, ThreadFun, ( void *)&thread2, 0, NULL );
    WaitForMultipleObjects(2, handle, TRUE , INFINITE );
    return 0;
}