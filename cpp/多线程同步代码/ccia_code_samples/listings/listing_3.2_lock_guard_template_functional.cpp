#include <mutex>

// 防恶意修改数据方式

class some_data
{
    int a;
    std::string b;
public:
    void do_something()
    {}
};

class data_wrapper
{
private:
    some_data data;
    std::mutex m;
public:
    // 泛化数据
    template<typename Function>
    void process_data(Function func)
    {
        std::lock_guard<std::mutex> l(m);
        func(data);
    }
};

some_data* unprotected;

// mock malicious modify date
// 模拟恶意修改数据
void malicious_function(some_data& protected_data)
{
    unprotected=&protected_data;
}

data_wrapper x;

void foo()
{
    // 使用恶意的修改方法  安全的保护数据 不被恶意修改 即便使用恶意的代码
    x.process_data(malicious_function);
    unprotected->do_something();
}

int main()
{
    foo();
}
