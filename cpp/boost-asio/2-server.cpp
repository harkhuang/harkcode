#include <boost/asio.hpp> 
#include <iostream>


void handler(const boost::system::error_code &ec) 
{ 
  std::cout << "5 s." << std::endl; 
} 

int main( int argc, char * argv[] )
{
	boost::asio::io_service io_service;
	boost::asio::deadline_timer timer(io_service, boost::posix_time::seconds(5)); 
    timer.async_wait(handler); 
	io_service.run();


	std::cout << "Do you reckon this line displays?" << std::endl;

	return 0;
}
