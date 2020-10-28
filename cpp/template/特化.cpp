


template <typename T>
void foo(T a)
{
    std::cout <<"xxxx" << a << std::endl;
}

template <typename T, typename ...Args>
void foo(T head, Args ...args)
{
    std::cout << head << std::endl;
    foo(args...);
}



template<class T>
class Singleton {
public:
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton& s) = delete;

    Singleton(Singleton&& s) = delete;
    Singleton& operator=(Singleton&& s) = delete;

    static T* Instance()
    {
        static T _inst;
        return &_inst;
    }

protected:
    Singleton() = default;
};


class mydanli
{
    friend class Singleton<mydanli>;  //声明Test的友元为单例类模板
public:
    void Setmstr(string t)
    {
        mstr = t;
    }

    void print()
    {
        cout << "mstr = " << mstr << endl;
        cout << "this = " << this << endl;
    }

private:
    string mstr;

    mydanli() : mstr("abc")
    {
    }

    mydanli& operator = (const mydanli& t);
    mydanli(const mydanli&);

 };








template<int...>
struct IndexSeq {};

//继承方式，开始展开参数包
template<int N, int... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

// 模板特化，终止展开参数包的条件
template<int... Indexes>
struct MakeIndexes<0, Indexes...>
{
    typedef IndexSeq<Indexes...> type;
};

int lst_main()
{
    using T = MakeIndexes<3>::type;
    cout << typeid(T).name() << endl;
    return 0;
}


struct A
{
    A(int) { }


    int a1;
    int a2;
};

struct B
{
    B(int, double) {}
    int b1;
    char b2;
};





/// 这个类模版可以 构造任何个数的类成员函数
template<typename T,typename... Args>
T* Instance(Args&&... args)
{
    return new T(std::forward<Args>(args)...);
}


void test_fanxing_moban()
{

    // 对于1个参数的类可以构造
    A* pa = Instance<A>(1);


    /// 对于多个参数的模版也可以构造
    B* pb = Instance<B>(1, 2);

    getchar();
}