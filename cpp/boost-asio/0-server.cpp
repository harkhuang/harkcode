#include <boost/asio.hpp> 
#include <iostream> 

int test_0(   )
{
	boost::asio::io_service io_service;
	boost::asio::io_service::work work( io_service );

	io_service.run();

    // 这段代码并不能看到
	std::cout << "Do you reckon this line displays?" << std::endl;

	return 0;
}
int test_1(  )
{
	boost::asio::io_service io_service;

	for( int x = 0; x < 42; ++x )
	{
		io_service.poll();
		std::cout << "Counter: " << x << std::endl;
	}

	return 0;
}


int main()
{
    test_0();

    test_1();
    
    return 0;
}