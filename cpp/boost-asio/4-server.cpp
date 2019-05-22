#include <boost/asio.hpp> 
#include <iostream>


int main( int argc, char * argv[] )
{
	boost::asio::io_service io_service;
	//boost::asio::io_service::work work( io_service );

	for( int x = 0; x < 42; ++x )
	{
		io_service.poll();
		std::cout << "Counter: " << x << std::endl;
	}

	return 0;
}