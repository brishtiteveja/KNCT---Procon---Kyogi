using System;
using System.Collections.Generic;
using System.Text;
using System.Net;

namespace ProCon2011PlayerClient
{
    public static class WebAccessor
    {
        public static string DownloadProblem(string serverURL, string playerID, int problemNumber)
        {
            var wc = new WebClient();
            wc.QueryString.Add("ProblemNumber", problemNumber.ToString());

            return wc.DownloadString(serverURL + "/GetProblem");
        }

        public static string CheckParameters(string serverURL, string playerID)
        {
            var wc = new WebClient();
            wc.QueryString.Add("PlayerID", playerID);

            return wc.DownloadString(serverURL + "/CheckParameters");
        }

        public static string SubmitAnswer(string serverURL, string playerID, int problemNumber, string answer)
        {
            var wc = new WebClient();
            wc.QueryString.Add("PlayerID", playerID);
            wc.QueryString.Add("ProblemNumber", problemNumber.ToString());

            return wc.UploadString(serverURL + "/SubmitAnswer", answer);
        }
    }
}
