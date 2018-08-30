//main.cpp

#include <iostream> 
using namespace std;


class TCPOctetStream;
class TCPState;
// TCP连接的接口类
class TCPConnection
{
public:
  TCPConnection();
  void ActiveOpen(); 
  void PassiveOpen();
  void Close();
  void Send();
  void Acknowledge();
  void Synchronize();


  void ProcessOctet(TCPOctetStream*){};//实现部分为自己补充

private:
  friend class TCPState;
  void ChangeState(TCPState*);

private:
  TCPState* _state;
};

// TCP连接状态类
class TCPState
{
public:
  virtual void Transmit(TCPConnection*, TCPOctetStream*);
  virtual void ActiveOpen(TCPConnection*);// 主动打开（active open）是指客户端发送第一个SYN报文，它主动发起建立TCP连接的请求
  virtual void PassiveOpen(TCPConnection*);// 被动打开（passive open）是指服务端接受第一个SYN报文并且发回一个SYN报文，它响应建立TCP连接的请求。
  virtual void Close(TCPConnection*);
  virtual void Synchronize(TCPConnection*);
  virtual void Acknowledge(TCPConnection*){};//实现部分为自己补充
  virtual void Send(TCPConnection*){};       //实现部分为自己补充
protected:
  void ChangeState(TCPConnection*, TCPState*);
};



// 侦听状态类(TCP连接状态类的子类) 单例代码为自己补充
class TCPListen: public TCPState
{
public:
  static TCPState* Instance()
  {
    if (NULL == m_pTCPListen)
    {
      m_pTCPListen = new TCPListen();
    }
    return m_pTCPListen;
  }
  virtual void Send(TCPConnection*);
private:
  static TCPListen* m_pTCPListen;
};
TCPListen* TCPListen::m_pTCPListen = NULL;  

// 连接成功状态(TCP连接状态类的子类)  单例代码为自己补充
class TCPEstablished: public TCPState
{
public:
  static TCPState* Instance()
  {   
    if (NULL == m_pTCPEstablished)
    {
      m_pTCPEstablished = new TCPEstablished();
    }
    return m_pTCPEstablished;
  }
  virtual void Transmit(TCPConnection*, TCPOctetStream*);
  virtual void Close(TCPConnection*);
private:
  static TCPEstablished* m_pTCPEstablished;
};

TCPEstablished* TCPEstablished::m_pTCPEstablished = NULL;  

// 结束连接状态(TCP连接状态类的子类) 单例代码为自己补充
class TCPClosed: public TCPState
{
public:
  static TCPState* Instance()
  {   
    if (NULL == m_pTCPClosed)
    {
      m_pTCPClosed = new TCPClosed();
    }
    return m_pTCPClosed;
  }
  virtual void ActiveOpen(TCPConnection*); 
  virtual void PassiveOpen(TCPConnection*); 
private:
  static TCPClosed* m_pTCPClosed;
};
TCPClosed* TCPClosed::m_pTCPClosed = NULL;  


//-------------------实现------------------------------
TCPConnection::TCPConnection()
{
  _state = TCPClosed::Instance();
};

void TCPConnection::ChangeState(TCPState* s)
{
  _state = s;
};

void TCPConnection::ActiveOpen()
{
  _state->ActiveOpen(this);
};


void TCPConnection::PassiveOpen()
{
  _state->PassiveOpen(this);
}

void TCPConnection::Close()
{
  _state->Close(this);
}

void TCPConnection::Send() //实现部分为自己补充
{
  _state->Send(this);
}

void TCPConnection::Acknowledge()
{
  _state->Acknowledge(this);
}
void TCPConnection::Synchronize()
{
  _state->Synchronize(this);
}



void TCPState::Transmit(TCPConnection*, TCPOctetStream*){};
void TCPState::ActiveOpen(TCPConnection*){};
void TCPState::PassiveOpen(TCPConnection*){};
void TCPState::Close(TCPConnection*){};
void TCPState::Synchronize(TCPConnection*){};

void TCPState::ChangeState(TCPConnection* t, TCPState* s)
{
  t->ChangeState(s);
}


void TCPClosed::ActiveOpen(TCPConnection* t)
{
  // send SYN,receive SYN,ACK,etc
  cout << ("TCPClosed send SYN,receive SYN,ACK,etc") << endl;
  ChangeState(t, TCPEstablished::Instance());
}

void TCPClosed::PassiveOpen(TCPConnection* t)
{
  ChangeState(t, TCPListen::Instance());
}


void TCPEstablished::Close(TCPConnection* t)
{
  // send FIN,recieve ack of FIN
  cout << ("TCPEstablished send FIN,recieve ack of FIN") << endl;
  ChangeState(t, TCPListen::Instance());
}

void TCPEstablished::Transmit(TCPConnection* t, TCPOctetStream* o)
{

  t->ProcessOctet(o);
}


void TCPListen::Send(TCPConnection* t)
{
  // send SYN,receive SYN,ACK,etc
  cout << ("TCPListen send SYN,receive SYN,ACK,etc") << endl;
  ChangeState(t, TCPEstablished::Instance());
}


int main(int argc,char* argv[]) 
{ 
  TCPConnection* pTCPConnection = new TCPConnection();
  pTCPConnection->ActiveOpen();
  pTCPConnection->Close();
  pTCPConnection->Send();
  system("PAUSE");   
  return 0;
}
