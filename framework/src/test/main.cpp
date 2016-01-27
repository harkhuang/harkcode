#include "marc.h"
#include "wsocket.h"

#include <debug.h>
#include <iostream>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <netdb.h>

using namespace std;

#define SERVERPORT "1988"

int main()
{   
    char arr[100] = {"the message is from wsocket ..."};

#if  1
    cout << "===========test connect  Raw sockets client ==============" << endl;
	CWSocket a;
    char address[100] = {"127.0.0.1"};
    int sd;
    struct sockaddr_in raddr;
   // sockaddr_in raddr;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd<0) {
        perror("socket()");
        exit(1);
    }
    else{
        cout<<"connect success"<<endl;
    }
    raddr.sin_family = AF_INET;
    raddr.sin_port = htons(atoi(SERVERPORT));
    inet_pton(AF_INET, address, &raddr.sin_addr);
    if (connect(sd, (const sockaddr*)&raddr, sizeof(raddr))<0) {
        perror("connect()");
        exit(1);
    }
    else
    cout << "=========end connect socket================" << endl;
#endif

#if  1
    char lpszaddress[100] = {"127.0.0.1"};
    int nport = 1988;
    int nconnecttimeout = 100;
    CWSocket csocket;

   // TODO: add factory pattern
   // CWSocket* csocket = new CWSocket();
   // csocket->CreateProductB();


    if (csocket.Connect(lpszaddress,  nport,  nconnecttimeout))
    {
          cout << "connect success" << endl;
    }
    else
    {
         cout << "connect failed" << endl;
    }
  //  a.SetAddressPort(lpszaddress,  nport,  nconnecttimeout);
#endif




#if 1

     cout <<"=========test send buffer to server================"<<endl;
    int n = -1;


    // if success  return the send buff length.
    n = csocket.SendData(arr,100);

    cout << n   <<endl;
    if (n> 0)
    {
          cout << "SendData success"  <<endl;
    }
    else
    {
         cout << "SendData error"  <<endl;
    }
      //  cout << "SendData return value is:"<< n <<endl;
    cout <<"=========end test send buffer to server================"<<endl;

#endif
    return 0;
}

