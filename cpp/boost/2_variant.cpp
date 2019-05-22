#include "boost\variant.hpp"
#include <vector>
#include <iostream>
#include <array>
#include <string>

using namespace std;

class DoubleVisitor : public boost::static_visitor<> {
public:
   void operator() (int& i) const {  
       i += i;
   }
   void operator() (string& str) const { 
       str += str;
   }
};

void Double( boost::variant<int, string> u) {
}

int main()
{
//   C union:
   union {int i; float f;} u;   // u contains either int or float
   u.i = 34;
   cout << u.i << endl; 
   u.f = 2.3;  // u.i is overwritten
   cout << u.i << endl;  // output garbages
// Problem: it can only work with POD (Plain Old Data)

   //union {int i; string s;} u;   //  Won't compile


// variant is an union for C++
   boost::variant<int, string> u1, u2;
   u1 = 2;
   u2 = "Hello";
   cout << u1 <<  endl;
   cout << u2 << endl;
   //u1 = u1 * 2;  // * is not overloaded for variant
   u1 = boost::get<int>(u1) * 2;    // get() return a reference of the int
	                                 // if variant<int*, string>, get() returns pointer of int
	                                 
   cout << boost::get<int>(u1) <<  endl;  // output: 64
   //cout << boost::get<string>(u1) << endl;  // crash.  variant is discriminated union container
   //  if retrieval failed, get() returns a null pointer or throws an exception: bad_get
   u1 = "good";  // u1 becomes a string
   u1 = 32;   // u1 becomes an int again

	
	// A variant is never empty
   boost::variant<int, string> u3;
   cout << boost::get<int>(u3) <<  endl;
   
   // Problem with boost::get(): we don't always know what type is saved in the variant

   //Using visitor
   boost::apply_visitor( DoubleVisitor(), u1 );
   cout << boost::get<int>(u1) <<  endl;  // output: 128

   boost::apply_visitor( DoubleVisitor(), u2 );
   cout << boost::get<string>(u2) << endl; // output: HelloHello

   std::vector< boost::variant<int, string> > arr;
   arr.push_back("good");
   arr.push_back(25);
   arr.push_back("bad");
   for (auto x : arr) {
       boost::apply_visitor( DoubleVisitor(), x);
   }
}


