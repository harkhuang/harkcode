/*
 * 2. Uniform Initialization
 */
#include <iostream>
#include <vector>

// 匿名初始化构造  
#include <initializer_list> 
// C++ 03
class Dog
 {     // Aggregate class or struct
   public:
      int age;
     std::string name;
};

Dog d0 ;
d0.age = 5;
d

Dog d0 = {5, "Henry"};   // Aggregate Initialization

// C++ 11 extended the scope of curly brace initialization
class Dog1 {
   public:
      Dog1(int age, std::string name) {};
};
Dog1 d1 = {5, "Henry"}; 


/* Uniform Initialization Search Order:
 * 1. Initializer_list constructor
 * 2. Regular constructor that takes the appropriate parameters.
 * 3. Aggregate initializer.
 */

Dog d1{3};

class Dog {
   public:
   int age;                                // 3rd choice

   Dog(int a) {                            // 2nd choice
      age = a;
   }

   Dog(const std::initializer_list<int>& vec) { // 1st choice
      age = *(vec.begin());      
   }
};



int main()
{
   return 0;
}