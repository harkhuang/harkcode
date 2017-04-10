#include <stdio.h>
#include <iostream>
class X {public :void foo(){printf("xxxxx\n");}}; 
//  request for member `foo' is ambiguous  歧义 不加virtual 由于
class Y : public virtual X {}; 

class Z : public virtual X {}; 

class A : public Y, public Z {}; 

using namespace std;
int main(int argc, char *argv[])
{

	printf("Hello, world\n");
	printf("X size is %d \n",sizeof(X));
	printf("Y size is %d \n",sizeof(Y));
	printf("Z size is %d \n",sizeof(Z));
	printf("A size is %d \n",sizeof(A));
	
	return 0;
}
