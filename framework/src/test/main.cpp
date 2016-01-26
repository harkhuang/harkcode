#include "marc.h"
#include "wsocket.h"

#include <debug.h>
#include <iostream>


using namespace std;


int main()
{   
    char arr[100] = {"the message is from wsocket ..."};
    cout << "=========================" << endl;
	CWSocket a;

#if  1
    char lpszaddress[100] = {"127.0.0.1"};
    int nport = 1988;
    int nconnecttimeout = 100;
    if (a.Connect(lpszaddress,  nport,  nconnecttimeout))
    {
          cout << "connect success" << endl;
    };
  //  a.SetAddressPort(lpszaddress,  nport,  nconnecttimeout);
#endif

    int n, m;
    m = a.CreateServerSocket(1988);
    n = a.SendData(arr,100);
    a.GetError();
    cout << "CreateServerSocket return value is:" << m <<endl;
    cout << "SendData return value is:"<< n <<endl;
    return 0;
}

