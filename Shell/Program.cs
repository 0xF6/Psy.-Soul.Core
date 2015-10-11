using PsySoul.Core;
using PsySoul.Core.PLR;
using Rc.Framework;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Shell
{
    class Program
    {
        static void Main()
        {
            Monitor.EnabledTrace = false;
            Monitor.Header = "+g4\0PLR+g0\0";
            $"Test".WriteLine();
        }
    }
}