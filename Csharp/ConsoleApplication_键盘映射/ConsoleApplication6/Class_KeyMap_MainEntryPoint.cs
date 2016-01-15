using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication6
{
    public class MainEntryPoint
    {
        public static void Start()
        {
            // 实例化一个事件发送器
            KeyInputMonitor monitor = new KeyInputMonitor();
            // 实例化一个事件接收器
            EventReceiver eventReceiver = new EventReceiver(monitor);
            // 运行
            monitor.Run();
        }
    }
}
