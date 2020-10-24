#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <functional>
 
int main()
{
    std::list<int> l(10);
 
    std::iota(l.begin(), l.end(), -4);
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
 
    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
 
    std::cout << "Contents of the list: ";
    for (int n : l){ 
        std::cout << n << ' ';
    }



    
 
    std::cout << "\nContents of the list, as seen through a shuffled vector: ";
    for (int i : v){
        std::cout << i << ' ';
    }
 
    // 通过引用方式访问  并且对其值进行修改.
    // 引用方式访问 并且修改
    // 使得一个对象具有两种数据结构操作方式 🐂🍺
    std::cout << "\n\nDoubling the values in the initial list...\n\n";
    for (int& i : l) {
        i *= 2;
    }
 
    std::cout << "Contents of the list, as seen through a shuffled vector: ";
    for (int i : v){
       std::cout << i << ' ';


    }
}