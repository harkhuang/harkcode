#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void print( int elem)
{
        cout << elem <<  ' ';
}


int main()
{
        vector<int> vec;
        for (int i = 0; i != 10; ++i)
                vec.push_back(i);

        for_each(vec.begin(), vec.end(), print);
        //请允许我卖弄一点点小特性
        cout << endl;

        return 0;

}