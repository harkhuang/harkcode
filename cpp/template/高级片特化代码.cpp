
#include <iostream>
#include <type_traits>

using namespace std;

/******************************************************************
CALLBACK
******************************************************************/

template<typename T>
using ObjectOf =typename std::remove_pointer<typename std::remove_reference<T>::type>::type;

template<typename T, T f>
struct CallbackWrapper
{
    static void Get()
    {
    }
};

template<typename T, typename ...TArgs, void(T::*f)(TArgs...)>
struct CallbackWrapper<void(T::*)(TArgs...), f>
{
    static void Invoke(TArgs ...args, void* argument)
    {
        (reinterpret_cast<T*>(argument)->*f)(args...);
    }

    static void(*Get())()
    {
        return reinterpret_cast<void(*)()>(&Invoke);
    }
};

#define CALLBACK(OBJECT, NAME)\
	CallbackWrapper<\
		decltype(&ObjectOf<decltype(OBJECT)>::NAME),\
			 &ObjectOf<decltype(OBJECT)>::NAME\
		>::Get(),\
	static_cast<void*>(OBJECT)\

/******************************************************************
CLIENT
******************************************************************/

void Fuck(void(*shit)(), void* argument)
{
    auto bitch = reinterpret_cast<void(*)(int, double, const char*, void*)>(shit);
    bitch(1, 1.2, "Fuck GTK+", argument);
}

struct Callback
{
    int context;

    void Invoke(int a, double b, const char* c)
    {
        cout << context << "," << a << "," << b << "," << c << endl;
    }
};

int tttt()
{
    Callback callback{ 200 };
    Fuck(CALLBACK(&callback, Invoke));
    return 0;
}