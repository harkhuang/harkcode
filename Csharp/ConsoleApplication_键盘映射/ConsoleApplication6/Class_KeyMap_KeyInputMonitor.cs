using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication6
{
    internal class KeyInputMonitor
    {
        // 创建一个委托，返回类型为void，两个参数
        public delegate void KeyDownHandler(object sender, KeyEventArgs e);
        // 将创建的委托和特定事件关联,在这里特定的事件为KeyDown
        public event KeyDownHandler KeyDown;

        public void Run()
        {
            bool finished = false;
            do
            {
                Console.WriteLine("Input a char");
                string response = Console.ReadLine();

                char responseChar = (response == "") ? ' ' : char.ToUpper(response[0]);
                switch (responseChar)
                {
                    case 'X':
                        finished = true;
                        break;
                    default:
                        // 得到按键信息的参数
                        KeyEventArgs keyEventArgs = new KeyEventArgs(responseChar);
                        // 触发事件
                        KeyDown(this, keyEventArgs);
                        break;
                }
            } while (!finished);
        }
    }
}
