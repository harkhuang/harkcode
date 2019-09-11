#include <iostream>
#include <string>
#include <fstream>
#include <future>
using namespace std;


static void factorial(int N ,int &ref)
{
    int res = 1;
    for(int i= N; i>1;i--){
        res *= i;
    }

    cout<< "result is :"<< res <<endl;
    ref = res;
}






int main()
{
    int a = 0;
    future<int > fu = std::async(std::launch::deferred, factorial, 4, a);
    auto x = fu.get();
    
    return 0;
}