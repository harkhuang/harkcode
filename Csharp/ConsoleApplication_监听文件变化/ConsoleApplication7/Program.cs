using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Security.Permissions;




namespace ConsoleApplication7
{
    class Program
    {
        static void Main(string[] args)
        {
            Run_File_Syn();
            Console.WriteLine("aaaaa");
            Console.ReadLine();

        }

        public static void Run_File_Syn()
        {
            FileSystemWatcher watcher = new FileSystemWatcher();

            watcher.Path = AppDomain.CurrentDomain.BaseDirectory;

            /* 设置为监视 LastWrite 和 LastAccess 时间方面的更改，以及目录中文本文件的创建、删除或重命名。 */
            watcher.NotifyFilter = NotifyFilters.LastAccess | NotifyFilters.LastWrite
               | NotifyFilters.FileName | NotifyFilters.DirectoryName;
            // 只监控.dll文件  
            watcher.Filter = "*.*";

            // 添加事件处理器。  
            watcher.Changed += new FileSystemEventHandler(OnChanged);
            watcher.Created += new FileSystemEventHandler(OnChanged);
            watcher.Deleted += new FileSystemEventHandler(OnChanged);
            watcher.Renamed += new RenamedEventHandler(OnChanged);

            // 开始监控。  
            watcher.EnableRaisingEvents = true;
        }
        public static void OnChanged(object source, FileSystemEventArgs e)
        {
            Console.WriteLine("有文件被改动过");
        }
    }
}
