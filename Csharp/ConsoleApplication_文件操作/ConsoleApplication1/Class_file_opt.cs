using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ConsoleApplication1
{
    class file_opt
    {
        string log_path = "";
        public void write_log(string log)
        {
            // 时间格式  15/9/24 14:44:21
            string log_final = DateTime.Now.ToString() + "==>" + log;
            System.IO.File.WriteAllText(log_path, log);
        }
        public string getcurpath()
        {
            string path = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase.ToString();           
            return path;
        }
 
         public void copyfile(string path_src,string path_dest)
         {
             // 获取当前路径
             string path = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase.ToString();
             System.IO.File.Copy(path_src , path_dest  , true);            
        }

         //读取文件内容
         public void read(string path)
         {            
             path = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase.ToString();
             path = path + "//source.txt";
             string[] text = System.IO.File.ReadAllLines(path);
             using (System.IO.StreamWriter file =
              new System.IO.StreamWriter(path, true))
             {
                 foreach (string text_line in text)
                     file.WriteLine(text_line);
             }
             //test code             
             //foreach (string text_line in text)
             //Console.WriteLine(text_line);
         
         }

         public void write(string path_src,string path_dest)
         {
             try
             {
                 string path_current;
                 path_current = System.AppDomain.CurrentDomain.SetupInformation.ApplicationBase.ToString();
                 path_src = path_current + "//source.txt";
                 path_dest = path_current + "//destination.txt";
                 string[] text = System.IO.File.ReadAllLines(path_src);
                 using (System.IO.StreamWriter file =
                    new System.IO.StreamWriter(path_dest, true))
                 {
                     foreach (string text_line in text)
                         file.WriteLine(text_line);

                 }
                 Console.WriteLine("write ok~~~~\n");
             }
             catch (Exception ex)
             {
                 Console.Write("清空日志文件失败：" + ex.Message);
             }
           
         }
         public void write_line(string path_dest, string buffer)
         {
             try
             {
                 //string path_current;
                 //string[] text = System.IO.File.ReadAllLines(path_dest);
                 using (System.IO.StreamWriter file =
                    new System.IO.StreamWriter(path_dest, true))
                 {
                     file.WriteLine(buffer);
                 }
                 Console.WriteLine("write ok~~~~\n");
             }
             catch (Exception ex)
             {
                 write_log("write line failed：" + ex.Message);
             }

         }
         // 清空文件
         public void emptyfile(string path)
         {
             FileStream fs = null;
             try
             {
                 fs = new FileStream(path, FileMode.Truncate, FileAccess.ReadWrite);

             }
             catch (Exception ex)
             {
                string log  = DateTime.Now.ToString() + ex;
                write_log(log);
             }
             finally
             {
                 fs.Close();
             }
         }


         public void getfile_create_time(string path)
         {
             FileInfo fi = new FileInfo(path);
             Console.Write("创建时间：" + fi.CreationTime.ToString() + "写入文件的时间" + fi.LastWriteTime + "访问的时间" + fi.LastAccessTime);
         }
         public void ms_wirte()
         {
            // These examples assume a "C:\Users\Public\TestFolder" folder on your machine.
            // You can modify the path if necessary.


            // Example #1: Write an array of strings to a file.
            // Create a string array that consists of three lines.
            string[] lines = { "First line", "Second line", "Third line" };
            // WriteAllLines creates a file, writes a collection of strings to the file,
            // and then closes the file.  You do NOT need to call Flush() or Close().
            System.IO.File.WriteAllLines(@"C:\Users\Public\TestFolder\WriteLines.txt", lines);


            // Example #2: Write one string to a text file.
            string text = "A class is the most powerful data type in C#. Like a structure, " +
                            "a class defines the data and behavior of the data type. ";
            // WriteAllText creates a file, writes the specified string to the file,
            // and then closes the file.    You do NOT need to call Flush() or Close().
            System.IO.File.WriteAllText(@"C:\Users\Public\TestFolder\WriteText.txt", text);

            // Example #3: Write only some strings in an array to a file.
            // The using statement automatically flushes AND CLOSES the stream and calls 
            // IDisposable.Dispose on the stream object.
            // NOTE: do not use FileStream for text files because it writes bytes, but StreamWriter
            // encodes the output as text.
            using (System.IO.StreamWriter file = 
                new System.IO.StreamWriter(@"C:\Users\Public\TestFolder\WriteLines2.txt"))
            {
                foreach (string line in lines)
                {
                    // If the line doesn't contain the word 'Second', write the line to the file.
                    if (!line.Contains("Second"))
                    {
                        file.WriteLine(line);
                    }
                }
            }

            // Example #4: Append new text to an existing file.
            // The using statement automatically flushes AND CLOSES the stream and calls 
            // IDisposable.Dispose on the stream object.
            using (System.IO.StreamWriter file = 
                new System.IO.StreamWriter(@"C:\Users\Public\TestFolder\WriteLines2.txt", true))
            {
                file.WriteLine("Fourth line");
            }
         }
          
       
//             //替换原有文件
//             System.IO.File.Copy(path + "images//skin//bg_2.jpg", path + "images//dnav_bg.jpg",true);
//             //这几个参数的意思分别为:
//             path + "images//skin//bg_2.jpg",：源目标文件的路径
//             path + "images//dnav_bg.jpg",:目的文件的路径
//             true：表示如果存在目标文件就替换之。

    }
}
