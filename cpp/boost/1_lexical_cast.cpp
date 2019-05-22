#include "boost\lexical_cast.hpp"
#include <vector>
#include <iostream>
#include <array>

using namespace std;
using boost::lexical_cast;
using boost::bad_lexical_cast;

int main()
{
/*  Convert from string
atof     Convert string to double (function )
atoi     Convert string to integer (function )
atol     Convert string to long integer (function )
atoll    Convert string to long long integer (function )
strtod   Convert string to double (function )
strtof   Convert string to float (function )
strtol   Convert string to long integer (function )
strtold  Convert string to long double (function )
strtoll  Convert string to long long integer (function )
strtoul  Convert string to unsigned long integer (function )
strtoull Convert string to unsigned long long integer (function )
sscanf()
   
   Convert to string
stringstream strm;
strm << int_val;
string s = strm.str();
sprintf()
itoa  // non-standard
*/

    try
    {
        int s = 345;
        string str = lexical_cast<string>(s);
        str = "Message: " + lexical_cast<string>('A') + "==" + lexical_cast<string>(34.5);
        cout << str << endl;
        array<char, 64> msg = lexical_cast< array<char, 64> >(23456);

        s = lexical_cast<int>("5678");
        //s = lexical_cast<int>("56.78"); // bad_lexical_cast
        //s = lexical_cast<int>("3456yut");  // bad_lexical_cast 
        s = lexical_cast<int>("3456yut", 4); 
        cout << s << endl;
    }
    catch(bad_lexical_cast & e)
    {
        cout << "Exception caught:" << e.what() << endl; 
    }
    
}

