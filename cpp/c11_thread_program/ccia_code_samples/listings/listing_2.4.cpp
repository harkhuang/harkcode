#include <thread>
#include <string>

void open_document_and_display_gui(std::string const& filename)
{}

bool done_editing()
{
    return true;
}

enum command_type{
    open_new_document
};


struct user_command
{
    command_type type;

    user_command():
        type(open_new_document)
    {}
};

user_command get_user_input()
{
    return user_command();
}

std::string get_filename_from_user()
{
    return "foo.doc";
}

void process_user_input(user_command const& cmd)
{}


// 文档编辑器核心逻辑
void edit_document(std::string const& filename)
{
    // 简单抽象
    open_document_and_display_gui(filename);
    // 抽象过程
    while(!done_editing())
    {
        user_command cmd=get_user_input();
        // 通过多线程调用抽象自我调用
        if(cmd.type==open_new_document)
        {
            std::string const new_name=get_filename_from_user();
            std::thread t(edit_document,new_name);
            t.detach();// 作用是等待主动关闭或者说执行完成保持线程栈
        }
        else
        {
            process_user_input(cmd);
        }
    }
}

int main()
{
    edit_document("bar.doc");
}
