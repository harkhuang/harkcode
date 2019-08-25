
#include <cstdlib>
#include <deque>
#include <iostream>
#include <thread>
#include <boost/asio.hpp>
#include "chat_message.hpp"

using boost::asio::ip::tcp;

typedef std::deque<chat_message> chat_message_queue;

class CMSSocket
{
public:
    CMSSocket(boost::asio::io_service& io_service,tcp::resolver::iterator endpoint_iterator) : io_service_(io_service),socket_(io_service)
    {
        do_connect(endpoint_iterator);
    }

    // write event call back
    void write(const chat_message& msg)
    {
        io_context_.post(
            [this, msg]()
        {
            bool write_in_progress = !write_msgs_.empty();
            write_msgs_.push_back(msg);
            if (!write_in_progress)
            {
                do_write();
            }
          
        });
    }





    // close event
    void close()
    {
        io_context_.post([this]() { socket_.close(); });
    }

private:

    // read event
    void do_connect(tcp::resolver::iterator endpoint_iterator)
    {
        std::cout << "do connect " << std::endl;
        boost::asio::async_connect(socket_, endpoint_iterator,
            [this](boost::system::error_code ec, tcp::resolver::iterator)
        {
            std::cout << "do connect call back" << std::endl;
            if (!ec)
            { 
                for (;;)
                {
                    do_read_header();
                }
            }
        });
    }


    void do_dispath()
    {
        do_read_header();
        if(1)
        {

        }
    }
    // event chains
    void do_read_header()
    {
        std::cout << "do read head" << std::endl;
        boost::asio::async_read(socket_,
            boost::asio::buffer(read_msg_.data(), chat_message::header_length),
            [this](boost::system::error_code ec, std::size_t /*length*/)
        {
            std::cout << "do read head call back" << std::endl;
            if (!ec && read_msg_.decode_header())
            {
                do_read_body();
            }
            else
            {
                std::cout << "read error" << std::endl;
                socket_.close();
            }
        });
    }

    // 
    void do_read_body()
    {
        boost::asio::async_read(socket_,
            boost::asio::buffer(read_msg_.body(), read_msg_.body_length()),
            [this](boost::system::error_code ec, std::size_t /*length*/)
        {
            if (!ec)
            {
               
                std::cout.write(read_msg_.body(), read_msg_.body_length());
                std::cout << "\n";
                do_read_header();
            }
            else
            {
                socket_.close();
            }
        });
    }

    // write event chains
    void do_write()
    {
        boost::asio::async_write(socket_,
            boost::asio::buffer(write_msgs_.front().data(),
                write_msgs_.front().length()),
            [this](boost::system::error_code ec, std::size_t /*length*/)
        {
            std::cout << "999" << std::endl;
            if (!ec)
            {
                write_msgs_.pop_front();
                if (!write_msgs_.empty())
                {
                    do_write();
                }
            }
            else
            {
                socket_.close();
            }
        });
    }

    private:
       

private:
    boost::asio::io_context & io_context_;
    tcp::socket socket_;
    chat_message read_msg_;
    chat_message_queue write_msgs_;
};
