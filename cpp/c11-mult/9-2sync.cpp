#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
 
using namespace std::chrono;
 

 // 同  9-1  但是这个例子中消耗的时间仅仅是5秒钟   
 // 想一下这里主要的消耗在哪里  如果仅仅是磁盘 那么多线程能够提高我们的效率  但是如果消耗在cpu 那么多线程其实显得没有什么卵用
std::string fetchDataFromDB(std::string recvdData)
{
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(seconds(5));
 
	//Do stuff like creating DB Connection and fetching Data
	return "DB_" + recvdData;
}
 
std::string fetchDataFromFile(std::string recvdData)
{
	// Make sure that function takes 5 seconds to complete
	std::this_thread::sleep_for(seconds(5));
 
	//Do stuff like fetching Data File
	return "File_" + recvdData;
}
 
int main()
{
	// Get Start Time
	system_clock::time_point start = system_clock::now();
 
	std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
 
	//Fetch Data from File
	std::string fileData = fetchDataFromFile("Data");
 
	//Fetch Data from DB
	// Will block till data is available in future<std::string> object.
	std::string dbData = resultFromDB.get();
 
	// Get End Time
	auto end = system_clock::now();
 
	auto diff = duration_cast < std::chrono::seconds > (end - start).count();
	std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
 
	//Combine The Data
	std::string data = dbData + " :: " + fileData;
 
	//Printing the combined Data
	std::cout << "Data = " << data << std::endl;
 
	return 0;
}