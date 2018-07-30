 /********************************************************************
 # File Name:    test.cpp
 # Version:      1.0
 # Mail:         shiyanhk@gmail.com 
 # Created Time: 2018-07-30
 *********************************************************************/

#include <iostream>
using namespace std;


extern "C"{
	int hello();
}

int main()
{
	hello();
	return 0;
}
