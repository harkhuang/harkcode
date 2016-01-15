using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

class Program
{
    static void Main(string[] args)
    {
        /* 
        //获取文件版本信息
        while (true)
        {
            Console.Write("请输入指定的文件路径(请拖拽文件到此处)：");
            string path = Console.ReadLine();
            PrintFileVersionInfo(path);
        }
        */
    }

    /// <summary>
    /// 打印指定文件的详细信息
    /// </summary>
    /// <param name="path">指定文件的路径</param>
    static void PrintFileVersionInfo(string path)
    {
        System.IO.FileInfo fileInfo = null;
        try
        {
            fileInfo = new System.IO.FileInfo(path);
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
            // 其他处理异常的代码
        }
        // 如果文件存在
        if (fileInfo != null && fileInfo.Exists)
        {
            System.Diagnostics.FileVersionInfo info = System.Diagnostics.FileVersionInfo.GetVersionInfo(path);
            Console.WriteLine("文件名称=" + info.FileName);
            Console.WriteLine("产品名称=" + info.ProductName);
            Console.WriteLine("公司名称=" + info.CompanyName);
            Console.WriteLine("文件版本=" + info.FileVersion);
            Console.WriteLine("产品版本=" + info.ProductVersion);
            // 通常版本号显示为「主版本号.次版本号.生成号.专用部件号」
            Console.WriteLine("系统显示文件版本：" + info.ProductMajorPart + '.' + info.ProductMinorPart + '.' + info.ProductBuildPart + '.' + info.ProductPrivatePart);
            Console.WriteLine("文件说明=" + info.FileDescription);
            Console.WriteLine("文件语言=" + info.Language);
            Console.WriteLine("原始文件名称=" + info.OriginalFilename);
            Console.WriteLine("文件版权=" + info.LegalCopyright);

            Console.WriteLine("文件大小=" + System.Math.Ceiling(fileInfo.Length / 1024.0) + " KB");
        }
        else
        {
            Console.WriteLine("指定的文件路径不正确!");
        }
        // 末尾空一行
        Console.WriteLine();
    }
}