

class StdThreadRaiiWrapper
{
    typedef void (std::thread::*RAIIAction)();
public:
    StdThreadRaiiWrapper(std::thread&& t, RAIIAction a);
    ~StdThreadRaiiWrapper();
    std::thread& GetThread();

private:
    std::thread m_thread;
    RAIIAction m_actionUponDestruction;
};


StdThreadRaiiWrapper::StdThreadRaiiWrapper(thread&& t, RAIIAction a)
    : m_thread(move(t))
    , m_actionUponDestruction(a)
{

}

StdThreadRaiiWrapper::~StdThreadRaiiWrapper()
{
    if (m_thread.joinable())
    {
        (m_thread.*m_actionUponDestruction)();
    }
}

std::thread& StdThreadRaiiWrapper::GetThread()
{
    return m_thread;
}
