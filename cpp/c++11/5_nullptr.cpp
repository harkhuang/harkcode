/*
 * 5. nullptr
 *
 * To replace NULL in C++ 03
 */


#include<iostream>


void foo(int i)    { std::cout << "foo_int" << std::endl; }
void foo(char* pc) { std::cout << "foo_char*" << std::endl; }

int main() {
   foo(NULL);    // Ambiguity  多重语义

   // C++ 11
   foo(nullptr); // call foo(char*)   最好只适用这个
}

