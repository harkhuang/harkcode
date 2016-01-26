#include "marc.h"
#include "wsocket.h"

#include <debug.h>
#include <iostream>


using namespace std;


int main()
{   
    char arr[100] = {"the message is from wsocket ..."};
    //SAFESTRZERO(arr);
    cout << "Hello World!" << endl;
	CWSocket a;
    char lpszaddress[100] = {"127.0.0.1"};
    int nport = 1988;
    int nconnecttimeout = 100;

    if(true ==  a.Connect( lpszaddress,  nport,  nconnecttimeout))
    {
        printf("connect success\n");
    }
    a.SendData(arr,100);
    return 0;
}

