



/*###################################################################
 * Learn C++ 11 
 */

/*
 * 1. Initializer List
 */

//C++ 03 initializer list:
int arr[4] = {3, 2, 4, 5};

vector<int> v;
v.push_back(3);
v.push_back(2);
v.push_back(4);
v.push_back(5);



// C++ 11 extended the support 
vector<int> v = {3, 4, 1, 9};   // Calling initializer_list constructor

// All the relevant STL containers have been updated to accept initializer_list.



// Define your own initializer_list constructor:
#include <initializer_list>
class BoVector {
   vector<int> m_vec;
   public:
   BoVector(const initializer_list<int>& v) {
      for (initializer_list<int>::iterator itr = v.begin(); itr!=v.end(); ++ itr)
         m_vec.push_back(*itr);
   }
};

BoVector v = {0, 2, 3, 4};
BoVector v{0, 2, 3, 4};   // effectively the same


// Automatic normal Initialization
class Rectangle {
   public:
   Rectangle(int height, int width, int length){ }
};

void draw_rect(Rectangle r);

int main() {
   draw_rect({5, 6, 9});  // Rectangle{5,6,9} is automatically called
}

// Note: use it with caution.
// 1. Not very readable, even with the help of IDE. Funcion name rarely indicates
//    the type of parameter the function takes.
// 2. Function could be overloaded with differenct parameter types.

void draw_rect(Triangle t);
















/*
 * 2. Uniform Initialization
 */

// C++ 03
class Dog {     // Aggregate class or struct
   public:
      int age;
      string name;
};
Dog d1 = {5, "Henry"};   // Aggregate Initialization

// C++ 11 extended the scope of curly brace initialization
class Dog {
   public:
      Dog(int age, string name) {...};
};
Dog d1 = {5, "Henry"}; 


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

   Dog(const initializer_list<int>& vec) { // 1st choice
      age = *(vec.begin());      
   }
};






/*
 * 3. auto type
 */
std::vector<int> vec = {2, 3, 4, 5};

// C++ 03
for (std::vector<int>::iterator it = vec.begin(); it!=vec.end(); ++ it)
    m_vec.push_back(*it);


// C++ 11: use auto type
for (auto it = vec.begin(); it!=vec.end(); ++ it)
    m_vec.push_back(*it);

auto a = 6;    // a is a integer
auto b = 9.6;  // b is a double
auto c = a;    // c is an integer
auto const x = a;   // int const x = a
auto& y = a;        // int& y = a

// It's static type, no run-time cost, fat-free.
// It also makes code easier to maintain.

// 1. Don't use auto when type conversion is needed
// 2. IDE becomes more important








/*
 * 4. foreach
 */
// C++ 03:
   for (vector<int>::iterator itr = v.begin(); itr!=v.end(); ++ itr)
      cout << (*itr);


// C++ 11:
   for (auto i: v) { // works on any class that has begin() and end()
      cout << i ;    // readonly access
   }

   for (auto& i: v) {
      i++;                 // changes the values in v
   }                       // and also avoids copy construction

   auto x = begin(v);  // Same as: int x = v.begin();

   int arr[4] = {3, 2, 4, 5};
   auto y = begin(arr); // y == 3
   auto z = end(arr);   // z == 5
   // How this worked? Because begin() and end() are defined for array.
   // Adapt your code to third party library by defining begin() and end()
   // for their containers.






/*
 * 5. nullptr
 *
 * To replace NULL in C++ 03
 */

void foo(int i) { cout << "foo_int" << endl; }
void foo(char* pc) { cout << "foo_char*" << endl; }

int main() {
   foo(NULL);    // Ambiguity

   // C++ 11
   foo(nullptr); // call foo(char*)
}











/*
 * 6. enum class
 */

   // C++ 03
   enum apple {green_a, red_a};
   enum orange {big_o, small_o};
   apple a = green_a;
   orange o = big_o;

   if (a == o) 
      cout << "green apple and big orange are the same\n";
   else
      cout << "green apple and big orange are not the same\n";


   // C++ 11
   enum class apple {green, red};
   enum class orange {big, small};
   apple a = apple::green;
   orange o = orange::big;

   if (a == o) 
      cout << "green apple and big orange are the same\n";
   else
      cout << "green apple and big orange are not the same\n";

   // Compile fails because we haven't define ==(apple, orange)









/*
 * 7. static_assert
 */

// run-time assert
   assert( myPointer != NULL );

// Compile time assert (C++ 11)
   static_assert( sizeof(int) == 4 );








/*
 * 8. Delegating Constructor 
 */

class Dog {
   public:
   Dog() { ... }
   Dog(int a) { Dog(); doOtherThings(a); }
};


// C++ 03:
class Dog {
   init() { ... };
   public:
   Dog() { init(); }
   Dog(int a) { init(); doOtherThings(); }
};
/* Cons:
 * 1. Cumbersome code.
 * 2. init() could be invoked by other functions.
 */

// C++ 11:
class Dog {
   int age = 9;
   public:
   Dog() { ... }
   Dog(int a) : Dog() { doOtherThings(); }
};
// Limitation: Dog() has to be called first.









/*
 * 9. override (for virtual function)
 *
 * To avoid inadvertently create new function in derived classes.
 */
// C++ 03
class Dog {
   virtual void A(int);
   virtual void B() const;
}

class Yellowdog : public Dog {
   virtual void A(float);  // Created a new function
   virtual void B(); // Created a new function 
}


// C++ 11
class Dog {
   virtual void A(int);
   virtual void B() const;
   void C();
}

class Yellowdog : public Dog {
   virtual void A(float) override;  // Error: no function to override
   virtual void B() override;       // Error: no function to override
   void C() override;               // Error: not a virtual function
}









/*
 * 10. final (for virtual function and for class)
 */

class Dog final {    // no class can be derived from Dog
   ...
};
   
class Dog {
   virtual void bark() final;  // No class can override bark() 
};










/*
 * 11. Compiler Generated Default Constructor
 */
class Dog {
   Dog(int age) {}
};

Dog d1;  // Error: compiler will not generate the default constructor


// C++ 11:
class Dog {
   Dog(int age);
   Dog() = default;    // Force compiler to generate the default constructor
};









/*
 * 12. delete
 */

class Dog {
   Dog(int age) {}
}

Dog a(2);
Dog b(3.0); // 3.0 is converted from double to int
a = b;     // Compiler generated assignment operator


// C++ 11:
class Dog {
   Dog(int age) {}
   Dog(double ) = delete;
   Dog& operator=(const Dog&) = delete;
}








/*
 * 13. constexpr
 */
int arr[6];    //OK
int A() { return 3; }
int arr[A()+3];   // Compile Error 

// C++ 11
constexpr int A() { return 3; }  // Forces the computation to happen 
                                 // at compile time.
int arr[A()+3];   // Create an array of size 6

// Write faster program with constexpr
constexpr int cubed(int x) { return x * x * x; }

int y = cubed(1789);  // computed at compile time

//Function cubed() is:
//1. Super fast. It will not consume run-time cycles
//2. Super small. It will not occupy space in binary.







/*
 * 14. New String Literals
 */

  // C++ 03:
  char*     a = "string";  

  // C++ 11:
  char*     a = u8"string";  // to define an UTF-8 string. 
  char16_t* b = u"string";   // to define an UTF-16 string. 
  char32_t* c = U"string";   // to define an UTF-32 string. 
  char*     d = R"string \\"    // to define raw string. 






/*
 * 15. lambda function
 */

cout << [](int x, int y){return x+y}(3,4) << endl;  // Output: 7
auto f = [](int x, int y) { return x+y; };
cout << f(3,4) << endl;   // Output: 7


template<typename func>
void filter(func f, vector<int> arr) {
   for (auto i: arr) {
      if (f(i))
         cout << i << " ";
   }
}

int main() {
   vector<int> v = {1, 2, 3, 4, 5, 6 };

   filter([](int x) {return (x>3);},  v);    // Output: 4 5 6
   ...
   filter([](int x) {return (x>2 && x<5);},  v); // Output: 3 4


   int y = 4;  
   filter([&](int x) {return (x>y);},  v);    // Output: 5 6
   //Note: [&] tells compiler that we want variable capture
}

// Lambda function works almost like a language extention
template
for_nth_item





/*
 * 17. User defined Literals
 */

// C++ went a long way to make user defined types (classes) to behave same as buildin types.
// User defined literals pushes this effort even further

//Old C++:
long double height = 3.4;

// Remember in high school physics class?
height = 3.4cm;
ratio = 3.4cm / 2.1mm; 

//Why we don't do that anymore?
// 1. No language support
// 2. Run time cost associated with the unit translation



// C++ 11:
long double operator"" _cm(long double x) { return x * 10; }
long double operator"" _m(long double x) { return x * 1000; }
long double operator"" _mm(long double x) { return x; }

int main() {
   long double height = 3.4_cm;
   cout << height  << endl;              // 34
   cout << (height + 13.0_m)  << endl;   // 13034
   cout << (130.0_mm / 13.0_m)  << endl; // 0.01
}

//Note: add constexpr to make the translation happen in compile time.


// Restriction: it can only work with following paramters:
   char const*
   unsigned long long
   long double
   char const*, std::size_t
   wchar_t const*, std::size_t
   char16_t const*, std::size_t
   char32_t const*, std::size_t
// Note: return value can be of any types.


// Example:
int operator"" _hex(char const* str, size_t l) { 
   // Convert hexdecimal formated str to integer ret
   return ret;
}

int operator"" _oct(char const* str, size_t l) { 
   // Convert octal formated str to integer ret
   return ret;
}

int main() {
   cout << "FF"_hex << endl;  // 255
   cout << "40"_oct << endl;  // 32
}





/*
 * Variadic Template
 *
 * A template that can take any number of template arguments of any type.
 * Both class and function templates can be variadic.
 */
template<typename... arg>
class BoTemplate;

BoTemplate<float> t1;
BoTemplate<int, long, double, float> t2;
BoTemplate<int, std::vector<double>> t3;

BoTemplate<> t4;


// Combination of variadic and non-variadic argument
template<typename T, typename... arg>
class BoTemplate;

BoTemplate<> t4;  // Error
BoTemplate<int, long, double, float> t2;  // OK


// Define a default template argument
template<typename T = int, typename... arg>
class BoTemplate;




/*
 * Template Alias
 */
  template<class T> class Dog { /* ... */ };
  template<class T>
    using DogVec = std::vector<T, Dog<T>>;

  DogVec<int> v;  // Same as: std::vector<int, Dog<int>>







/*
 * decltype
 *
 * It is equivalent of GNU typeof
 */
  const int& foo();      // Declare a function foo()
  decltype(foo())  x1;  //  type is const int&

  struct S { double x; };
  decltype(S::x)   x2;  //  x2 is double

  auto s = make_shared<S>();
  decltype(s->x)   x3;  //  x3 is double

  int i;
  decltype(i)      x4;  //  x4 is int  

  float f;              
  decltype(i + f)  x5;   // x5 is float

  // decltype turns out to be very useful for template generic programming
  template<type X, type Y>
  void foo(X x, Y y) {
     ...
     decltype(x+y) z;
     ...
  }

  // How about return type needs to use decltype?
  template<type X, type Y>
  decltype(x+y) goo(X x, Y y) {      // Error: x & y are undefined 
     return  x + y;
  }

  // Combining auto and decltype to implement templates with trailing return type
  template<type X, type Y>
  auto goo(X x, Y y) -> decltype(x+y) {
     return  x + y;
  }





/*
 * Thread Memory Model
 *
 * Why people use thread?
 * 1. Process multiple event stream
 * 2. Take advantage of multiple cores.
 */

24:41




/*                 THE END
 *
 * Notes are downloadable from: boqian.weebly.com
 */
