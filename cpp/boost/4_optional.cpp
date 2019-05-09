#include <vector>
#include <deque>
#include <iostream>
#include <array>
#include <string>
#include "boost\optional.hpp"
#include "boost\variant.hpp"

using namespace std;

deque<char> queue;

//char get_async_data() {
//    if (!queue.empty())
//        return queue.back();
//    else
//        return '\0'; // this is a valid char
//}

boost::optional<char> get_async_data() {
    if (!queue.empty())
        return boost::optional<char>(queue.back());
    else
        return boost::optional<char>(); 
}

int main() {
    // What we need:
    boost::variant<nullptr_t, char> v;

    // Optional:
    boost::optional<char> op;  // op is uninitalized, no char is constructed
    //op.get();  // assertion failure
    op = 'A';

	 op = get_async_data(); 
    if (!op)  // same as: if (op != 0)
        cout << "op is not initialized" << endl;
    else  {
        cout << "op contains " << op.get() << endl; // get() requires op to be initialized, otherwise crash (assertion failure)
        cout << "op contains " << *op << endl; // same as get()
    }

    // Remove the if/else check
    op.reset();  // reset op to uninitialzed state
    cout << op.get_value_or('z') << endl;  // if op is unitialized, return 'z', else return *op

    // Alternatively
    char* p = op.get_ptr();  // return a pointer to contained value, or null if not initialized 

   // optional can store any kind of data
    struct A {string name; int value;};
    A a;
    boost::optional<A> opA;  // constructor of A is not called
    boost::optional<A> opA(a);
    cout << opA->name << " " << opA->value << endl;

    // Pointer
    boost::optional<A*> opAP(&a);
    cout << (*opAP)->name << " " << (*opAP)->value << endl;

    // Reference
    boost::optional<A&> opAR(a);
    opAR->name = "Bob";  // This changes a

    // Relational Operator
    boost::optional<int> oInt1(9);
    boost::optional<int> oInt2(1);
    if (oInt1 < oInt2)
        cout << "oInt1 is bigger" << endl;  // If both are initialized, compare *oInt1 and *oInt2
                                            // Otherwise, uninitialized optional is considered smallest
    
    // Important: optional is not modeled as pointer!!!
}

