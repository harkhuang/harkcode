#include <boost/asio.hpp> 
#include <iostream>


int main( int argc, char * argv[] )
{
	boost::asio::io_service io_service;
	boost::shared_ptr< boost::asio::io_service::work > work(
		new boost::asio::io_service::work( io_service )
	);

	work.reset();  // do nothing ?

	io_service.run();

	std::cout << "Do you reckon this line displays?" << std::endl;

	return 0;	
}