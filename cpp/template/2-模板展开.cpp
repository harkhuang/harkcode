#include <iostream>
#include <string>


// 方法1

// 递归展开的最后一个
// void print() {}是为了终止递归。
void print() {}
// 编译器解析这行代码的时候 递归入栈 找到print() 为出口, 最后一个参数是空, 那么 开始从最后一个开始找到 第一个
/*
print(a,b,c) ->  print(a , print(b,c))-> print(a , print(b, print(c, print()))) 
实际解析出来的调用 
然后仅限压栈->输出得到 print() ->  print(c)  -> print(b) -> print(a)
*/
//

// 递归展开访问第一个参数  T表示泛型的第一个参数 仅此而已
// so 这是一个很好的方法
template <typename T, typename... Types> 
void print(T firstArg, Types... args) {
  std::cout << firstArg << '\n'; // print first argument
  print(args...);                // call print() for remaining arguments
}





using namespace std; 

// 方法2
template <typename T>
void printOne(T a)
{
    cout << a << endl;
}

template <typename... Args>
void printAll(Args... argsPack)
{
    int res[] = {(printOne(argsPack), 0)...};
}


// 方法3
template <typename...T>

void varCount(T...argPack)
{
   // 在此处展开
   cout << sizeof...(argPack) << endl;
}





// 简化后的 可变参数函数...
// https://en.cppreference.com/w/cpp/language/template_argument_deduction
// https://en.cppreference.com/w/cpp/language/parameter_pack
// 一个来自于cpp_refren的测试用例代码  
// https://github.com/zhangyachen/zhangyachen.github.io/issues/154
// https://github.com/zhangyachen/zhangyachen.github.io/issues
// 精致的细节
namespace test_advance {
#include <iostream>

  void tprintf(const char* format) // base function
  {
      std::cout << format;
  }

  template<typename T, typename... Targs>
  void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
  {
      for ( ; *format != '\0'; format++ ) {
          if ( *format == '%' ) {
            std::cout << value;
            tprintf(format+1, Fargs...); // recursive call
            return;
          }
          std::cout << *format;
      }
  }
  
  int case1()
  {
      // 完成字符串拼接  spdlog 中有用
      tprintf("% world% %\n","Hello",'!',123);
  }
    
  int case2()
  {
      // 完成字符串拼接  spdlog 中有用
      tprintf("% % % %\n","1",0.444,123,"第四个参数");
  }

};


namespace test
{
  template<typename T>
  T adder(T v) {
    return v;
  }

  template<typename T, typename... Args>
  T adder(T first, Args... args) {
    return first + adder(args...);
  }

  void case1(){
    long sum = adder(1, 2, 3, 8, 7);
    std::cout << sum << std::endl;
    std::string s1 = "x", s2 = "aa", s3 = "bb", s4 = "yy";
    std::string ssum = adder(s1, s2, s3, s4);
    std::cout << ssum << std::endl;
  }
};


int main() {
  test::case1();
  test_advance::case1();
  test_advance::case2();
}