// c11 使用局部静态变量实现线程安全的单例模式
/// 局部静态变量可以延迟对象的构造，等到第一次调用时才进行构造。
// C++11中静态变量的初始化时线程安全的。通过调试，在进行局部静态变量初始化的时候，确实会执行以下代码来保证线程安全。
#include <iostream>

class Singleton {
public:
  static Singleton& GetInstance() {
    static Singleton intance;
    return intance;
  }

  ~Singleton() = default;

private:
  Singleton() = default;

  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;
};

int main() {
  Singleton& s1 = Singleton::GetInstance();
  std::cout << &s1 << std::endl;

  Singleton& s2 = Singleton::GetInstance();
  std::cout << &s2 << std::endl;

  return 0;
}