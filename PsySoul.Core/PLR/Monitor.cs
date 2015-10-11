//# =========================== #//# ========================= #//
//#                             #//#                           #//
//#  PsyX-SoulBridge            #//#   Yuuki Wesp (C) 2015     #//
//#      License Type="MIT"     #//#     <ls-micro@ya.ru>      #//
//#                             #//#                           #//
//# =========================== #//# ========================= #//
using Rc.Framework;

namespace PsySoul.Core.PLR
{
    /// <summary>
    /// Монитор Ядра
    /// </summary>
    public static class Monitor
    {
        /// <summary>
        /// Header Console Message
        /// </summary>
        public static string Header = "";
        /// <summary>
        /// Enable write member or line code
        /// </summary>
        public static bool EnabledTrace = false;
        /// <summary>
        /// WriteLine in Terminal
        /// </summary>
        /// <param name="t">string</param>
        /// <param name="member">member code</param>
        /// <param name="line">line code</param>
        public static void WriteLine(this string t, [System.Runtime.CompilerServices.CallerMemberName] string member = "", [System.Runtime.CompilerServices.CallerLineNumber] int line = 0)
        {
            string temp1;
            if (EnabledTrace)
                temp1 = $"+g4\0{member}+g0\0:+g4\0{line}+g0\0";
            else
                temp1 = string.Empty;

            if (EnabledTrace)
                Header = temp1;

            if (Header == "")
                Terminal.WriteLine($"{t}");
            else
                Terminal.WriteLine(t, Header);
        }
    }
}
