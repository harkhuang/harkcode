

#include "marc.h"
#include "wsocket.h"


#include <iostream>


using namespace std;


int main()
{   
	char arr[100];
	SAFESTRZERO(arr);
    cout << "Hello World!" << endl;
	
	CWSocket a;
    char lpszaddress[100] = {"127.0.0.1"};
    int nport = 1988;
    int nconnecttimeout = 100;
    a.Connect( lpszaddress,  nport,  nconnecttimeout);


    return 0;
}

