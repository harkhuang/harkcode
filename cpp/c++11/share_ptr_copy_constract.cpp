

// shared_ptr::get example
#include <iostream>
#include <memory>

int test() {
    int* p = new int(10);
    std::shared_ptr<int> a(p);

    if (a.get() == p)
        std::cout << "a and p point to the same location\n";

    // three ways of accessing the same address:
    std::cout << a.get() << "  value:" << *a.get() <<"\n";
    std::cout << a << "  value:" << *a <<"\n";
    std::cout << p << "  value:" << *p <<"\n";
    std::cout << "ptr reference_wrapper time :" << a.use_count() << "\n";
    return 0;
}
