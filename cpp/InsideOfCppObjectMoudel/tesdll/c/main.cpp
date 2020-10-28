#include <iostream>
using namespace std;

class X
{
public: 
	X(){};
	virtual ~X(){};
	void foo()
	{
		cout<< "foo func."<<endl;
	}

	X foobar() 
	{ 
		X xx; 
		X *px = new X; 

		// foo() is virtual function 
		xx.foo(); 
		px->foo(); 

		delete px; 
		return xx; 
	}; 
private:
};




int main()
{
	X x;
	return 0;
}

/*
void foobar( X &_result ) 
{ 
	// construct _result 
	// _result replaces local xx ... 
	_result.X::X(); 

	// expand X *px = new X; 
	px = _new( sizeof( X )); 
	if ( px != 0 ) 
		px->X::X(); 

	// expand xx.foo(): suppress virtual mechanism 
	// replace xx with _result 
	foo( &_result ); 

	// expand px->foo() using virtual mechanism 
	( *px->_vtbl[ 2 ] )( px ) 
		// expand delete px; 
		if ( px != 0 ) { 
			( *px->_vtbl[ 1 ] )( px ); // destructor 
			_delete( px ); 
		} 

		// replace named return statement 
		// no need to destroy local object xx 
		return; 
}; 
*/