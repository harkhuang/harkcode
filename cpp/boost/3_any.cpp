
#include <vector>
#include <iostream>
#include <array>
#include <string>
#include "boost\any.hpp"

using namespace std;

int main() {
   boost::any x, y, z;
   x = string("hello");  // string
	x = 2.34;  // double
   y = 'A';   // char
   z = vector<int>();  // dynamic storage allocation
							  // variant uses stack storage, more efficient
   
   //cout << y << endl; // won't compile
   cout << boost::any_cast<char>(y) << endl; //  returns a copy of y's data: 'A'
					// boost::get() returns a reference
					// boost::any_cast() reuturns a copy of data
   cout << boost::any_cast<double>(x) << endl; //  returns a copy of x's data: 2.34
   int i = boost::any_cast<int>(x);  // No static check, only run-time check
                                     // Throws bad_any_cast exception
   cout << boost::any_cast<float>(x) << endl; //  bad_any_cast

   boost::any_cast<vector<int>>(z).push_back(23);
   int i = boost::any_cast<vector<int>>(z).top();  // crash, because z's vector is still empty


   boost::any p;
   p = &i;  // p is a pointer of int, variant can also store pointers
   int* pInt = boost::any_cast<int*>(p);  // returns a pointer

   y.empty(); // return true if y is empty
   if (y.type() == typeid(char))   // run-time type check.  variant has compile-time type check with visitor 
       cout << "y is a char" << endl;
      
   vector<boost::any> many;
   many.push_back(2);
   many.push_back('s');
   many.push_back(x); 
   many.push_back(boost::any());

   
   struct Property {
       string name;
       boost::any value;
   };
   vector<Property> properties;

}



/*
Boost.Variant vs. Boost.Any

As a discriminated union container, the Variant library shares many of the same 
features of the Any library. However, since neither library wholly encapsulates 
the features of the other, one library cannot be generally recommended for use 
over the other.

That said, Boost.Variant has several advantages over Boost.Any, such as:

1. Boost.Variant guarantees the type of its content is one of a finite, user-specified 
   set of types.
2. Boost.Variant provides compile-time checked visitation of its content. (By contrast, 
   the current version of Boost.Any provides no visitation mechanism at all; but even if 
   it did, it would need to be checked at run-time.)
3. Boost.Variant enables generic visitation of its content. (Even if Boost.Any did provide
   a visitation mechanism, it would enable visitation only of explicitly-specified types.)
4. Boost.Variant offers an efficient, stack-based storage scheme (avoiding the overhead of 
   dynamic allocation).

Of course, Boost.Any has several advantages over Boost.Variant, such as:
1. Boost.Any, as its name implies, allows virtually any type for its content, providing 
   great flexibility.
2. Boost.Any provides the no-throw guarantee of exception safety for its swap operation.
3. Boost.Any makes little use of template metaprogramming techniques (avoiding potentially 
   hard-to-read error messages and significant compile-time processor and memory demands).
*/

