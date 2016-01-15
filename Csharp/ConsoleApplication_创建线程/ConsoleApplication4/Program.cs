using System;
using System.Threading;

public class ThreadWork
{
    public static void DoWork()
    {
        Console.WriteLine("Working thread...");
        Console.ReadKey(true);
    }
}

class ThreadStateTest
{
    public static void Main()
    {
        Console.WriteLine("In main. Attempting to restart myThread.");
        Thread.Sleep(3000);
        
        ThreadStart myThreadDelegate = new ThreadStart(ThreadWork.DoWork);
        Thread myThread = new Thread(myThreadDelegate); 
        myThread.Start(); 
        Console.ReadKey(true);
//         try
//         {
//             myThread.Start();
//            
//         }
//         catch (ThreadStateException e)
//         {
//             Console.WriteLine("Caught: {0}", e.Message);
//         }
    }
}