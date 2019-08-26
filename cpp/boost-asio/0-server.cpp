#include <boost/asio.hpp> 
#include <iostream>
#include <boost/bind.hpp>
#include <memory>
#include <thread>
#include <unistd.h>



int test_0(   )
{
	boost::asio::io_service io_service;
	boost::asio::io_service::work work( io_service );

	io_service.run();

    // 这段代码并不能看到
	// 后台发生了什么?  不可预料 不可期待?
	std::cout << "Do you reckon this line displays?" << std::endl;

	return 0;
}

int test_1(   )
{
	boost::asio::io_service io_service;

	for( int x = 0; x < 3; ++x )
	{
		io_service.poll();
		std::cout << "Counter: " << x << std::endl;
	}

	return 0;
}


int test_2(  )
{
	boost::asio::io_service io_service;

	// 创建工作集?  但是工作集 没有内容? 
	// 此处 会阻塞吗?   答:不会
	boost::asio::io_service::work work( io_service );
	for( int x = 0; x < 3; ++x )
	{
		io_service.poll();
		std::cout << "Counter: " << x << std::endl;
	}

	return 0;
}


int test_3(   )
{
	boost::asio::io_service io_service;



	// 工作集  创建在堆中   , 后面有被使用, 但是 什么都没做  
	// 为什么会显示打印呢????
	boost::shared_ptr< boost::asio::io_service::work > work(
		new boost::asio::io_service::work( io_service )
	);

	work.reset();

	io_service.run();

	std::cout << "Do you reckon this line displays?" << std::endl;

	return 0;	
}






boost::asio::io_service io_service;



// 此工作线程中 执行了一大堆io作用
void WorkerThread()
{
	std::cout << "Thread Start\n";
	io_service.run();
	std::cout << "Thread Finish\n";
}



int test_4( )
{
	boost::shared_ptr< boost::asio::io_service::work > work(
		new boost::asio::io_service::work( io_service )
	);

	std::cout << "Press [return] to exit." << std::endl;

	//std::thread   thread;

//	for( int x = 0; x < 4; ++x )
//	{
        std::thread thread( &WorkerThread ,nullptr );
//	}

	std::cin.get();

	io_service.stop();


    thread.join();

	return 0;
}




int main()
{
    /// 阻塞 run
	//test_0();

	// 非阻塞poll
    //test_1();
    
	// 阻塞没poll
	//test_2();
    
	// 不会阻塞run
	// test_3();


	// 预期和结果是???
	test_4();
	return 0;
}