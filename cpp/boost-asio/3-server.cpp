#include <boost/asio.hpp> 
#include <iostream>




// no block
void test1(){
	boost::asio::io_service io_service;	

		boost::asio::io_service::work work( io_service );
	//for(int i=0;i<5;++i){
		io_service.run();
	//}
	std::cout << "Do you reckon this line displays?" << std::endl;
}
// no block
void test2(){
	boost::asio::io_service io_service;
	boost::asio::io_service::work work( io_service );
	for(int i=0;i<5;++i){
		io_service.run();
	}
	std::cout << "Do you reckon this line displays?" << std::endl;
}
int main( int argc, char * argv[] )
{
	test1();
	return 0;
}