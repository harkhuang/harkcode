using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication6
{
    internal class EventReceiver
    {
        public EventReceiver(KeyInputMonitor monitor)
        {
            // 产生一个委托实例并添加到KeyInputMonitor产生的事件列表中
            monitor.KeyDown += new KeyInputMonitor.KeyDownHandler(this.OnKeyDown);
        }
        private void OnKeyDown(object sender, KeyEventArgs e)
        {
            // 真正的事件处理函数
            Console.WriteLine("Capture key: {0}", e.KeyChar);
        }
    }
}
