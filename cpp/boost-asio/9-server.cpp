#include <iostream>
#include <boost/thread.hpp>
#include <boost/asio.hpp> 


int result = 0;
boost::mutex result_mutex;

boost::thread_group g;

void threaded_function(int i)
{
    for(; i < 100000; ++i) {}
    {
        boost::mutex::scoped_lock lock(result_mutex);
        result += i;
		std::cout<<result<<std::endl;
    }
}
void threaded_function1(int i)
{
    for(; i < 100000; ++i) {}
    {
        boost::mutex::scoped_lock lock(result_mutex);
        result += 1;
		std::cout<<result<<std::endl;
    }
}

void threaded_function2(int i)
{
    for(; i < 100000; ++i) {}
    {
        boost::mutex::scoped_lock lock(result_mutex);
        result += 2;
		std::cout<<result<<std::endl;
    }
}
void threaded_function3(int i)
{
    for(; i < 100000; ++i) {}
    {
        boost::mutex::scoped_lock lock(result_mutex);
        result += 3;
		std::cout<<result<<std::endl;
    }
}

// g++ -std=c++11 9-server.cpp -lboost_thread-mt -lpthread -lboost_system 
int main(int argc, char* argv[])
{
    using namespace std;
	// /boost::thread *t1 = new boost::thread(threaded_function, 10);
	
	//g.add_thread(t1);
 
    // launch three threads
    boost::thread *t1 = new boost::thread(threaded_function1, 10);
    boost::thread *t2 = new boost::thread(threaded_function2, 10);
    boost::thread *t3 = new boost::thread(threaded_function3, 10);

    g.add_thread(t1);
    g.add_thread(t2);
    g.add_thread(t3);

    // wait for them
    g.join_all();

    cout << result << endl;

    return 0;
}