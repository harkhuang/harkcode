using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
//using System.Messaging;
using System.Messaging.Design;
using System.Windows.Forms;
using System.Drawing.Image;
//using system.runtime.interopservice;


namespace ConsoleApplication1
{
    class Class_copybord
    {
        #region Definitions
        //Constants for API Calls...
        private const int WM_DRAWCLIPBOARD = 0x308;
        private const int WM_CHANGECBCHAIN = 0x30D;

        //Handle for next clipboard viewer...
        private IntPtr mNextClipBoardViewerHWnd;

        //API declarations...
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        static public extern IntPtr SetClipboardViewer(IntPtr hWndNewViewer);
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        static public extern bool ChangeClipboardChain(IntPtr HWnd, IntPtr HWndNext);
        [DllImport("user32.dll", CharSet = CharSet.Auto)]
        public static extern int SendMessage(IntPtr hWnd, int msg, int wParam, int lParam);
        #endregion


        #region Message Process


        //Override WndProc to get messages...
        

        //阻塞
        protected override void WndProc(ref Message m)
        {
            switch (m.Msg)
            {
                    case WM_DRAWCLIPBOARD:
                    {
                        //The clipboard has changed...
                        //##########################################################################
                        // Process Clipboard Here :)........................
                        //##########################################################################
                        SendMessage(mNextClipBoardViewerHWnd, m.Msg, m.WParam.ToInt32(), m.LParam.ToInt32());

                        //显示剪贴板中的文本信息
                        if (Clipboard.ContainsText())
                        {
                            string text;
                            text = Clipboard.GetText();
                        }
                        //显示剪贴板中的图片信息
                        if (Clipboard.ContainsImage())
                        {
                            if (false)
                            {
                                System.Drawing.Image returnImage = null;
                                returnImage = Clipboard.GetImage();

                            }
                            if (true)
                            {
                                System.Drawing.Image returnImage = null;
                                System.Drawing.Image replacementImage = null;
                                if (Clipboard.ContainsImage())
                                {
                                    returnImage = Clipboard.GetImage();
                                    Clipboard.SetImage(replacementImage);

                                }

                            }


                            break;
                        }
                    }
                    case WM_CHANGECBCHAIN:
                    {
                        //Another clipboard viewer has removed itself...
                        if (m.WParam == (IntPtr)mNextClipBoardViewerHWnd)
                        {
                            mNextClipBoardViewerHWnd = m.LParam;
                        }
                        else
                        {
                            SendMessage(mNextClipBoardViewerHWnd, m.Msg, m.WParam.ToInt32(), m.LParam.ToInt32());
                        }
                        break;
                    }
            }
            break;
            base.WndProc(ref m);
        }
        #endregion
        
        
        private void Form1_Load(object sender, System.EventArgs e)
        {
            // Add your form load event handling code here.
        }

        /*
        static void pro_syn()
        {
            Console.WriteLine("===== 同步调用 SyncInvokeTest =====");
            AddHandler handler = new AddHandler(加法类.Add);
            int result = handler.Invoke(1, 2);
            Console.WriteLine("继续做别的事情。。。");
            Console.WriteLine(result);
            Console.ReadKey();
        } 
         * */
    }



}
