#include <iostream>
#include <vector>
#include <initializer_list>
 

// 1 任何容器都不会依赖形式的表达式来构造任何其他容器{value1, value2, ...., valueN}。

// 2  这样，任何容器都不会依赖形式的表达式来构造任何其他容器{value1, value2, ...., valueN}。

// 2 比vector更加轻便

//  3 就地构造vector  为参数  减少了复制和拷贝的代价 更快,更方便的做参数传递  不适用构造函数就能直接生成传递所需参数



 /**
  * 
  * constructed with a 5-element list
    The vector size is now 8 ints:
    1 2 3 4 5 6 7 8
    Range-for over brace-init-list: 
    -1 -2 -3 
    The list bound to auto has size() = 3
  * */
template <class T>
struct S {
    std::vector<T> v;
    S(std::initializer_list<T> l) : v(l) {
         std::cout << "constructed with a " << l.size() << "-element list\n";
    }
    void append(std::initializer_list<T> l) {
        v.insert(v.end(), l.begin(), l.end());
    }
    std::pair<const T*, std::size_t> c_arr() const {
        return {&v[0], v.size()};  // copy list-initialization in return statement
                                   // this is NOT a use of std::initializer_list
    }
};
 
template <typename T>
void templated_fn(T) {}
 
int main()
{
    S<int> s = {1, 2, 3, 4, 5}; // copy list-initialization
    s.append({6, 7, 8});      // list-initialization in function call
 
    std::cout << "The vector size is now " << s.c_arr().second << " ints:\n";
 
    for (auto n : s.v)
        std::cout << n << ' ';
    std::cout << '\n';
 
    std::cout << "Range-for over brace-init-list: \n";
 
    for (int x : {-1, -2, -3}) // the rule for auto makes this ranged-for work
        std::cout << x << ' ';
    std::cout << '\n';
 
    auto al = {10, 11, 12};   // special rule for auto
 
    std::cout << "The list bound to auto has size() = " << al.size() << '\n';
 
//    templated_fn({1, 2, 3}); // compiler error! "{1, 2, 3}" is not an expression,
                             // it has no type, and so T cannot be deduced
    templated_fn<std::initializer_list<int>>({1, 2, 3}); // OK
    templated_fn<std::vector<int>>({1, 2, 3});           // also OK
}