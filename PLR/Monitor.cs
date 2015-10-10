//# =========================== #//# ========================= #//
//#                             #//#                           #//
//#  PsyX-SoulBridge            #//#   Yuuki Wesp (C) 2015     #//
//#      License Type="MIT"     #//#     <ls-micro@ya.ru>      #//
//#                             #//#                           #//
//# =========================== #//# ========================= #//
using Rc.Framework;

namespace Psy._Soul.Core.PLR
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
        /// Enable write member & line code
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
            if (EnabledTrace)   temp1 = $"[{member}:{line}]>";
            else                temp1 = string.Empty;
            if (EnabledTrace)   Header = temp1;
            if (Header == "")   Terminal.WriteLine($"{t}");
            else                Terminal.WriteLine(t, Header);
        }
    }
}
