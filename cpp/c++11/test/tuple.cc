#include "stdafx.h"
#include <iomanip>
#include <condition_variable>
#include <deque>
#include <functional>
#include <iostream>
#include <fstream>
#include <thread>
#include <map>
#include <unordered_map>
#include <string>
#include <mutex>

#include <algorithm>
#include <sstream>
#include <future>
#include <tuple>


#include <random>
using namespace std;

struct Node {
    char id; 
    int value;
    Node(char i, int v) : id(i), value(v) {}
    Node() : id(0), value('z') {}
};

int main() {
   tuple<int, string, char> t(32, "Penny wise", 'a');
   tuple<int, string, char> t = {32, "Penny wise", 'a'};  // Wont compile, constructor is explicit

   cout << get<0>(t) << endl;
   cout << get<1>(t) << endl;
   cout << get<2>(t) << endl;

   get<1>(t) = "Pound foolish";
   cout << get<1>(t) << endl;

   string& s = get<1>(t);
   s = "Patience is virtue"; 
   cout << get<1>(t) << endl;   
   //get<3>(t);  // Won't compile, t only has 3 fields
   // get<1>(t) is similar to t[1] for vector

   int i = 1;
   //get<i>(t); // Won't compile, i must be a compile time constant


   tuple<int, string, char> t2;  // default construction 
   t2 = tuple<int, string, char>(12, "Curiosity kills the cat", 'd'); 
   t2 = make_tuple(12, "Curiosity kills the cat", 'd'); 

   if (t > t2) {  // Lexicographical comparison
       cout << "t is larger than t2" << endl;
   }

   t = t2;  // member by member copying


// Tuple can store references !!  STL containers such as vectors cannot.  Pair can.
   string st = "In for a penny";
   tuple<string&> t3(st);  
   //auto t3 = make_tuple(ref(st));  // Do the same thing
   get<0>(t3) = "In for a pound";  // st has "In for a pound"
   cout << st << endl;
   t2 = make_tuple(12, "Curiosity kills the cat", 'd'); 
   int x;
   string y;
   char z;
   std::make_tuple(std::ref(x), std::ref(y), std::ref(z)) = t2;  // assign t2 to x, y, z
   std::tie(x,y,z) = t2;  // same thing
   std::tie(x, std::ignore, z) = t2;  // get<1>(t2) is ignored

// Other features
   auto t4 = std::tuple_cat( t2, t3 );  // t4 is tuple<int, string, char, string>
   cout << get<3>(t4) << endl;  // "In for a pound" 

   // type traits
   cout << std::tuple_size<decltype(t4)>::value << endl;  // Output: 4
   std::tuple_element<1, decltype(t4)>::type dd; // dd is a string
   
}







// tuple vs struct

tuple<string, int> getNameAge() { 
   return make_tuple("Bob", 34);
}

int main() {
   struct Person { string name; int age; } p;
   tuple<string, int> t;

   cout << p.name << " " << p.age << endl;
   cout << get<0>(t) << " " << get<1>(t) << endl;

   // As a one-time only structure to transfer a group of data
   string name;
   int age;
   tie(name, age) = getNameAge();

   // Comparison of tuples
   tuple<int, int, int> time1, time2; // hours, minutes, seconds
   if (time1 > time2) 
      cout << " time1 is a later time";

   // Multi index map
   map<tuple<int,int,int>, string> timemap;
   timemap.insert(make_pair(make_tuple(12, 2, 3), "Game start"));
	cout << timemap[make_tuple(2,3,4)]; 
   unordered_map<tuple<int,int,int>, string> timemap;

   // Little trick
   int a, b, c;
   tie(b, c, a) = make_tuple(a, b, c);

}














