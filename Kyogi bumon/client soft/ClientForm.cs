using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Text;
using System.Windows.Forms;
using System.Net;
using System.IO;
using System.IO.Compression;

namespace ProCon2011PlayerClient
{
    public partial class ClientForm : Form
    {
        int temin;

        private string ServerURL
        {
            get { return textBoxServerURL.Text; }
        }

        private string PlayerID
        {
            get { return textBoxPlayerID.Text; }
        }

        public ClientForm()
        {
            InitializeComponent();
        }

        public int ProblemNumber
        {
            get
            {
                return (int)numericUpDownGetProblemNumber.Value;
            }
        }

        private void buttonGetProblemData_Click(object sender, EventArgs e)
        {
            //saveFileDialogProblem.FileName = "problem" + ProblemNumber + ".txt";
            //if (saveFileDialogProblem.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            //{
                //var filePath = "C:\\kyogi\\0.txt";      //= saveFileDialogProblem.FileName;

            
            string problem = WebAccessor.DownloadProblem(ServerURL, PlayerID, ProblemNumber);
            if (problem.StartsWith("ERROR"))
                textBoxLog.AppendText("Download Error\n");
            else
            {
                string fname = textBoxPublic.Text + "\\problem.txt";
                WriteFile(problem, fname);
                WriteFile(problem, "C:\\kyogi\\0.txt");
                WriteFile(problem, "C:\\kyogi\\stock\\" + numericUpDownGetProblemNumber.Value + ".txt");
                textBoxLog.AppendText("Download Succeed (length=" + problem.Length + ")\n");
                //numericUpDownGetProblemNumber.Value += 1;
                temin = 0;
            }//}
        }

        private void WriteFile(string text, string path)
        {
            using (var sw = new StreamWriter(path))
            {
                sw.Write(text);
            }
        }

      

        private void buttonCheckConnection_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrEmpty(ServerURL) ||
                string.IsNullOrEmpty(PlayerID))
            {
                MessageBox.Show("There are some blank fields.");
                return;
            }

            if (ServerURL.EndsWith("/"))
            {
                MessageBox.Show("Server URL must not end with '/'.");
                return;
            }

            string ret;

            try
            {
                ret = WebAccessor.CheckParameters(ServerURL, PlayerID);
            }
            catch (WebException)
            {
                ret = "Server is not found.";
            }
            if (ret == "OK")
            {
                groupBox2.Enabled = true;
                groupBox3.Enabled = true;


            }

            label6.Text = ret;

 
            //public folderへのアクセスチェック
            try
            {
                WriteFile("test",textBoxPublic .Text + "\\network_test.txt");
                textBoxLog.AppendText("publicフォルダ OK\n");
            }
            catch
            {
                textBoxLog.AppendText("ERROR  publicフォルダにアクセスできない\n");
                textBoxLog.AppendText(textBoxPublic.Text + "\\network_test.txt\n");
            }

        }

        private void buttonSubmit_Click(object sender, EventArgs e)
        {
            string fname = textBoxPublic.Text + "\\answer1.txt";
           
            bool flag = false;
            try
            {
                using (var sr = new StreamReader(fname))
                {
                    string s = sr.ReadLine();
                    int te = int.Parse(s);
                    //if (te <= temin)
                    //{
                    //    flag = false;
                    //    if( te !=0 )
                    textBoxLog.AppendText("Answer tesu=" + te + "\n"); // + " (Not to send)\n");
                    //}
                    //else
                    //{
                    //    flag = true;
                    //    temin = te;
                    //    textBoxLog.AppendText("Answer tesu=" + te + " (TO SEND)\n");
                    //}
                    if (numericUpDownGetProblemNumber.Value == 0)
                        label10.Text = te + "";
                    else
                        label11.Text = te + "";
                }
            }
            catch
            {
                textBoxLog.AppendText("ERROR  answerファイルが見つからない\n");
            }

            //if (flag == false)
            //    return;

            string answer;
            using (var sr = new StreamReader(fname))
            {
                answer = sr.ReadToEnd();
            }

            string ret;
            try
            {
                ret = WebAccessor.SubmitAnswer(ServerURL, PlayerID, ProblemNumber, answer);
                textBoxLog.AppendText("Answer Submit Succeed\n");
            }
            catch (Exception ex)
            {
                ret = "Connection error:" + ex.Message;
            }
            textBoxLog.AppendText(ret);
            //WriteFile("0", fname);
        }

        private void ClientForm_Load(object sender, EventArgs e)
        {
            temin = 0;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string fname = textBoxPublic.Text + "\\answer2.txt";
            if (string.IsNullOrEmpty(fname))
            {
                MessageBox.Show("Answer file is not selected.");
                return;
            }

            bool flag = false;
            using (var sr = new StreamReader(fname))
            {
                string s = sr.ReadLine();
                int te = int.Parse(s);
                //if (te <= temin)
                //{
                //    flag = false;
                //    if( te !=0 )
                textBoxLog.AppendText("Answer tesu=" + te + "\n"); // + " (Not to send)\n");
                //}
                //else
                //{
                //    flag = true;
                //    temin = te;
                //    textBoxLog.AppendText("Answer tesu=" + te + " (TO SEND)\n");
                //}
                if (numericUpDownGetProblemNumber.Value == 0)
                    label10.Text = te + "";
                else
                    label11.Text = te + "";
            }

            //if (flag == false)
            //    return;

            string answer;
            using (var sr = new StreamReader(fname))
            {
                answer = sr.ReadToEnd();
            }

            string ret;
            try
            {
                ret = WebAccessor.SubmitAnswer(ServerURL, PlayerID, ProblemNumber, answer);
                textBoxLog.AppendText("Answer Submit Succeed\n");
            }
            catch (Exception ex)
            {
                ret = "Connection error:" + ex.Message;
            }
            textBoxLog.AppendText(ret);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            string fname = textBoxPublic.Text + "\\answer1.txt";

            bool flag = false;
            try
            {
                using (var sr = new StreamReader(fname))
                {
                    string s = sr.ReadLine();
                    int te = int.Parse(s);
                    //if (te <= temin)
                    //{
                    //    flag = false;
                    //    if( te !=0 )
                    textBoxLog.AppendText("Answer tesu=" + te + "\n"); // + " (Not to send)\n");
                    //}
                    //else
                    //{
                    //    flag = true;
                    //    temin = te;
                    //    textBoxLog.AppendText("Answer tesu=" + te + " (TO SEND)\n");
                    //}
                }
            }
            catch
            {
                textBoxLog.AppendText("ERROR  answerファイルが見つからない\n");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string fname = textBoxPublic.Text + "\\answer2.txt";

            bool flag = false;
            try
            {
                using (var sr = new StreamReader(fname))
                {
                    string s = sr.ReadLine();
                    int te = int.Parse(s);
                    //if (te <= temin)
                    //{
                    //    flag = false;
                    //    if( te !=0 )
                    textBoxLog.AppendText("Answer tesu=" + te + "\n"); // + " (Not to send)\n");
                    //}
                    //else
                    //{
                    //    flag = true;
                    //    temin = te;
                    //    textBoxLog.AppendText("Answer tesu=" + te + " (TO SEND)\n");
                    //}
                }
            }
            catch
            {
                textBoxLog.AppendText("ERROR  answerファイルが見つからない\n");
            }
        }
    }
}
