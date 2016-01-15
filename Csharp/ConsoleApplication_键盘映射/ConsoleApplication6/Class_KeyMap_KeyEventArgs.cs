using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication6
{
    internal class KeyEventArgs : EventArgs
    {
        private char keyChar;
        public KeyEventArgs(char keyChar)
            : base()
        {
            this.keyChar = keyChar;
        }

        public char KeyChar
        {
            get
            {
                return keyChar;
            }
        }
    }
}
