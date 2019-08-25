//
// chat_message.hpp
// ~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2012 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef CHAT_MESSAGE_HPP
#define CHAT_MESSAGE_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
 
class chat_message
{
    struct st_pack_head  {
        int id;
        char key;
    };
public:
    enum { header_length = 31 };
    enum { max_body_length = 1024 * 8 };

    chat_message()
        : body_length_(0)
    {
    }

    const char* data() const
    {
        return data_;
    }

    char* data()
    {
        return data_;
    }

    size_t length() const
    {
        return header_length + body_length_;
    }

    const char* body() const
    {
        return data_ + header_length;
    }

    char* body()
    {
        return data_ + header_length;
    }

    size_t body_length() const
    {
        return body_length_;
    }

    void body_length(size_t new_length)
    {
        body_length_ = new_length;
        if (body_length_ > max_body_length)
            body_length_ = max_body_length;
    }

    bool decode_header()
    {
        memcpy(&head_, data_, header_length);
        // 获取包体的长度
        body_length_ = head_.nDataLength;

        if (body_length_ > max_body_length)
        {
            body_length_ = 0;
            return false;
        }
        return true;
    }
   
    void encode_header()
    {
        memset((void *)&head_, 0, sizeof(st_pack_head));
        head_.nFlag = 'M';
        head_.nRequestNo = EM_CMS_REQ_API_ID_LOGIN;
        head_.nDataLength = (uint32_t)body_length_;
        head_.nUserData = 999;
        head_.nCheckSum = get_byte_sum((unsigned char *)&head_);
        memcpy(data_, &head_, header_length);
    }

    void encode_login_header()
    {
        memset((void *)&head_, 0, sizeof(st_pack_head));
        head_.nFlag = 'M';
        head_.nRequestNo = EM_CMS_REQ_API_ID_LOGIN;
        head_.nDataLength = (uint32_t)body_length_;
        head_.nUserData = 999;
        head_.nCheckSum = get_byte_sum((unsigned char *)&head_);
        memcpy(data_, &head_, header_length);
    }

    void encode_order_header()
    {
        // TODO:
    }

    void encode_query_header()
    {
        // TODO:
    }

    void encode_cancel_header()
    {
        // TODO:
    }

    unsigned char get_byte_sum(const unsigned char *p_sz_head)
    {
        unsigned char uc_sum = 0;
        for (int i = 0; i < sizeof(st_pack_head) - 1; i++)
            uc_sum += p_sz_head[i];
        return uc_sum;
    }

    void get_head(st_pack_head &head)
    {
        head = head_;
    }
private:
    char data_[header_length + max_body_length];
    size_t body_length_;
private:
    st_pack_head head_;
};

#endif // CHAT_MESSAGE_HPP