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

int test_3(  )
{
	boost::asio::io_service io_service;
	boost::shared_ptr< boost::asio::io_service::work > work(
		new boost::asio::io_service::work( io_service )
	);

	work.reset();

	io_service.run();

	std::cout << "Do you reckon this line displays?" << std::endl;

	return 0;	
}



boost::asio::io_service io_service;

void WorkerThread()
{
	std::cout << "Thread Start\n";
	io_service.run();
	std::cout << "Thread Finish\n";
}

int test_4()
{
	boost::shared_ptr< boost::asio::io_service::work > work(
		new boost::asio::io_service::work( io_service )
	);

	std::cout << "Press [return] to exit." << std::endl;

	boost::thread_group worker_threads;
	for( int x = 0; x < 4; ++x )
	{
		worker_threads.create_thread( WorkerThread );
	}

	std::cin.get();

	io_service.stop();

	worker_threads.join_all();

	return 0;
}

 

int main()
{
    test_0();

    test_1();
    
    return 0;
}