#include <exception>
#include <stack>
#include <mutex>
#include <memory>

// 集成std::exception
struct empty_stack: std::exception
{
    // 重写what方法
    const char* what() const throw()
    {
        return "empty stack";
    }
    
};

// 使用guard保证线程安全
template<typename T>  // 使用模板保证泛化可用性
class threadsafe_stack
{
private:
    // 定义泛化的数据类型 使用stack 进行封装 std::stock是标准的数据类型
    std::stack<T> data;
    // mutable 是相对const 而言的变量  表示随时可以变化的
    mutable std::mutex m;
public:
    threadsafe_stack(){}
    
    // 拷贝构造需要加锁
    threadsafe_stack(const threadsafe_stack& other)
    {
        std::lock_guard<std::mutex> lock(other.m);
        data=other.data;
    }

    // 删除外部的直接赋值操作 在没锁的情况向这样的操作是危险的
    threadsafe_stack& operator=(const threadsafe_stack&) = delete;

    void push(T new_value)
    {
        std::lock_guard<std::mutex> lock(m);
        data.push(new_value);
    }

    // pop 出栈是stack的重要方法  返回数据 后我们对数据供我们访问
    std::shared_ptr<T> pop()
    {
        std::lock_guard<std::mutex> lock(m);
        
        // 数据非空判断
        if(data.empty()) throw empty_stack();

        // 利用指针的拷贝构造将数据返回
        // 出让栈顶数据 用于使用
        std::shared_ptr<T> const res(std::make_shared<T>(data.top()));
        data.pop();
        return res;
    }

    
    void pop(T& value)
    {
        std::lock_guard<std::mutex> lock(m);
        if(data.empty()) throw empty_stack();
        // 出让栈顶数据 进行拷贝
        value=data.top();
        data.pop();
    }

    // 判断数据是否为空
    bool empty() const
    {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

int main()
{
    threadsafe_stack<int> si;
    si.push(5);
    si.pop();
    if(!si.empty())
    {
        int x;
        si.pop(x);
    }
    
}
