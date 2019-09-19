#pragma once
#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <vector>
#include <queue>
#include <thread>
#include <atomic>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

namespace std
{
#define  MAX_THREAD_NUM 256

    //线程池,可以提交变参函数或拉姆达表达式的匿名函数执行,可以获取执行返回值
    //不支持类成员函数, 支持类静态成员函数或全局函数,Opteron()函数等
    class threadpool
    {
        using Task = std::function<void()>;
        // 线程池
        std::vector<std::thread> m_vec_threadhandler_pool;
        // 任务队列
        std::queue<Task> m_tasks_queue;
        // 同步
        std::mutex m_lock;
        // 条件阻塞
        std::condition_variable cv_task;
        // 是否关闭整个线程池  这里用了一个原子变量 线程安全 省时省力
        std::atomic<bool> m_stoped;
        // 空闲线程数量
        std::atomic<int>  m_idlThrNum;

    public:

        // 创建线程池
        inline threadpool(unsigned short size = 4) :m_stoped{ false }
        {
            m_idlThrNum = size < 1 ? 1 : size;
            for (size = 0; size < m_idlThrNum; ++size)
            {   
                //直接初始化怼入匿名函数   简单直接有效  清晰明了 代码简洁
                m_vec_threadhandler_pool.emplace_back(
                    [this]()
                { // 工作线程函数  没一个线程都是一个死循环工作
                    // 这里工所调用的函数优点讲究 就是不听循环的 具体调用的是谁还是要看怎么往里怼进去的函数了
                    while (!this->m_stoped) // 条件就是只要不停止线程池
                    {
                        // task 是任务池  每个工作线程去任务池中取任务
                        std::function<void()> task;


                        // 此处使用 锁头不同于其他锁
                        // 是条件变量调用的管用方式  先锁unique lock 然后阻塞调用wait函数 等待生产者 发送生产就绪的信号
                        std::unique_lock<std::mutex> lock{ this->m_lock };// unique_lock 相比 lock_guard 的好处是：可以随时 unlock() 和 lock() 缺点是慢于lock_guard
                        
                        // 条件变量等待信号
                        // 这里异步等待 如果匿名函数 返回失败会有影响吗?
                        this->cv_task.wait(lock,
                            [this]() {
                            // 异步获取线程池状态 
                            return this->m_stoped.load(std::memory_order_relaxed) || !this->m_tasks_queue.empty();
                        }
                        ); 
                        
                        // wait 直到有 task
                        if (this->m_stoped && this->m_tasks_queue.empty())
                            return;
                        // 取一个 task  
                        task = std::move(this->m_tasks_queue.front());
                    //      (this->m_tasks_queue.front())();  /// error  ??
                        this->m_tasks_queue.pop();

                        // 难道只是因为 task 的延迟会造成  idl个数变化?
                        m_idlThrNum--;  
                        task();
                        m_idlThrNum++;  //????????  仅仅是task 延迟会带来损耗  全局的变量  异步得到保护  不要把自己的类封装太大了  这样反而不利于使用
                    }
                }
                );
            }
        }


        inline ~threadpool()
        {
            m_stoped.store(true);
            cv_task.notify_all(); // 唤醒所有线程执行
            for (std::thread& thread : m_vec_threadhandler_pool) {
                //thread.detach(); // 让线程“自生自灭”
                if (thread.joinable())
                    thread.join(); // 等待任务结束， 前提：线程一定会执行完
            }
        }

    public:
        // 提交一个任务
        // 调用.get()获取返回值会等待任务执行完,获取返回值
        // 有两种方法可以实现调用类成员，
        // 一种是使用   bind： .commit(std::bind(&Dog::sayHello, &dog));
        // 一种是用 mem_fn： .commit(std::mem_fn(&Dog::sayHello), &dog)
        template<class F, class... Args>
        auto commit(F&& f, Args&&... args) ->std::future<decltype(f(args...))>
        {
            if (m_stoped.load())    // stop == true ??
                throw std::runtime_error("commit on ThreadPool is stopped.");

            using RetType = decltype(f(args...)); // typename std::result_of<F(Args...)>::type, 函数 f 的返回值类型
            auto task = std::make_shared<std::packaged_task<RetType()> >(
                std::bind(std::forward<F>(f), std::forward<Args>(args)...)
                );   
                
            // 获取异步状态    异步返回是模版期望的的类型
            std::future<RetType> future = task->get_future();
            {    // 添加任务到队列
                std::lock_guard<std::mutex> lock{ m_lock };//对当前块的语句加锁  lock_guard 是 mutex 的 stack 封装类，构造的时候 lock()，析构的时候 unlock()
               
                // 
                m_tasks_queue.emplace(
                    [task]()
                { // push(Task{...})
                    (*task)();
                }
                );
            }
            cv_task.notify_one(); // 唤醒一个线程执行

            return future;
        }

        //空闲线程数量
        int idlCount() { return m_idlThrNum; }

    };

}


int thread_pool_test();

#endif