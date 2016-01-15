using System.IO;
using System;


namespace ConsoleApplication1
{
    class Program
    {
        static void Main(string[] args)
        {
            //获取当前路径
            string path_current = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase.ToString();
            string path_src = path_current + "//source_test.txt";
            string path_dest = path_current + "//dest_test.txt";
            file_opt file = new file_opt();
            //file.getcurpath(); 
            //file.copyfile(); 
            //file.read(path_src);
            //file.write(path_src, path_src);
            //file.emptyfile(path_dest);
            FileInfo fi = new FileInfo(path_src);
            Console.Write("创建时间：" + fi.CreationTime.ToString() + "写入文件的时间" + fi.LastWriteTime + "访问的时间" + fi.LastAccessTime+ "全路径"+ fi.FullName );
            Console.ReadLine();
        }
    }
}
