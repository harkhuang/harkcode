

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
 *  User defined Literals
 */

/* 
 * Literals are constants.
 *
 * C++ has 4 kinds of literals:
 * 	integer         ---  45
 * 	floating point  ---  4.5 
 * 	character       ---  'z' 
 * 	string          ---  "Dog"
 */

  45;  // int literal
  45u;  // unsigned int  (suffix specifies type)
  45l;  // long








//C++ 99:
long double height = 3.4;  // Metres? Centimeters? Inches?




// Ideally, always attach units to the values: 
height = 3.4cm;
ratio = 3.4cm / 2.1mm; //  ratio = 3.4 * 10 / 2.1 





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


// Restriction: it can only work with following parameters:
   char const*
   unsigned long long
   long double
   char const*, std::size_t
   wchar_t const*, std::size_t
   char16_t const*, std::size_t
   char32_t const*, std::size_t
// Note: return value can be of any types.







// Example:
constexpr int operator"" _hex(char const* str, size_t l) { 
   // Convert hexdecimal formated str to integer ret
   return ret;
}

constexpr int operator"" _oct(char const* str, size_t l) { 
   // Convert octal formated str to integer ret
   return ret;
}

int main() {
   cout << "FF"_hex << endl;  // 255
   cout << "40"_oct << endl;  // 32
   cout << "FF"_oct << endl;  // checking happens at compile time
}


// C++ went a long way to make user defined types (classes) to behave same as build-in types.
// User defined literals pushes this effort even further
