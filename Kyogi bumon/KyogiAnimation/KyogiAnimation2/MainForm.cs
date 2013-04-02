using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using System.Threading;
using ConvertImageLibrary;

namespace KyogiAnimation2
{
    public partial class MainForm : Form
    {
        public string AnswerFilePath
        {
            get { return answerFileBox.Text; }
        }
        public Image DiscordImage
        {
            get { return discordPictureBox.Image; }
        }

        private ConvertImage ci;
        private DiscordForm discordForm;

        public MainForm()
        {
            InitializeComponent();
            this.MinimumSize = this.Size;
        }

        public void ShowCount(string repairCount, string discordCount)
        {
            repairCountBox.Text = repairCount;
            discordCountBox.Text = discordCount;
        }

        private void problemLoadButton_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                problemFileBox.Text = openFileDialog.FileName;
                try
                {
                    ci = new ConvertImage(problemFileBox.Text, beforePictureBox.Width, (int)numericUpDown.Value);


                    SetImageAndSizeMode(beforePictureBox, ci.BeforePicture.Image);
                    SetImageAndSizeMode(afterPictureBox, ci.AfterPicture.Image);

                    int discordCount;
                    SetImageAndSizeMode(discordPictureBox, ci.GetFirstDiscord(discordPictureBox.Width, out discordCount));
                    repairCountBox.Text = "0";
                    discordCountBox.Text = discordCount.ToString();
                    
                    ReloadStamps();
                    int i=0;
                    foreach (PictureBox s in stampPanel.Controls)
                    {
                        s.Width = MaxSize(ci.StampsH[i], ci.StampsW[i]) * 3;
                        s.Height = MaxSize(ci.StampsH[i], ci.StampsW[i]) * 3;
                        i++;
                    }
                }
                catch
                {
                    MessageBox.Show("正しいフォーマットのファイルを指定してください");
                }
                reloadButton.Enabled = true;
            }
        }

        private void SetImageAndSizeMode(PictureBox pb,Image img)
        {
            if (pb.Width > img.Width && pb.Height > img.Height)
            {
                pb.SizeMode = PictureBoxSizeMode.Normal;
            }
            else
            {
                pb.SizeMode = PictureBoxSizeMode.Zoom;
            }
            pb.Image = img;
        }

        private int MaxSize(int w, int h)
        {
            int x;
            if( w < h ) x=h;
            else x=w;

            return x;
        }

        private void ReloadStamps()
        {

           
            var stamps = ci.Stamps
                            .Select(data => data.Image)
                            .Select(i =>
                             new PictureBox()
                             {
                                 Image = i,
                                 Size = new System.Drawing.Size(ci.StampSideLength, ci.StampSideLength),
                                 SizeMode = ci.StampSideLength > i.Width && ci.StampSideLength > i.Height && !stampZoomCheckBox.Checked
                                             ? PictureBoxSizeMode.Normal : PictureBoxSizeMode.Zoom
                             });
            stampPanel.Controls.Clear();
            stampPanel.Controls.AddRange(stamps.ToArray());
            foreach (PictureBox s in stampPanel.Controls)
            {
                s.DoubleClick += Stamp_DoubleClick;
                s.MouseEnter += Stamp_MouseEnter;
            }
        }

        private void answerAssignmentButton_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                answerFileBox.Text = openFileDialog.FileName;
                refreshButton.Enabled = true;
                discordZoomCheckBox.Enabled = true;
            }
        }

        private void RefreshDiscord()
        {
            ThreadPool.QueueUserWorkItem(o =>
            {

                try
                {
                    using (var reader = new StreamReader(answerFileBox.Text))
                    {
                        string repairCount = reader.ReadLine();
                        string discordCount = reader.ReadLine();
                        var discord = ConvertImage.GetDiscord(reader, discordPictureBox.Width);
                        this.Invoke(new Action(() =>
                        {
                            repairCountBox.Text = repairCount;
                            discordCountBox.Text = discordCount;
                            if (discordPictureBox.Width > discord.Width && discordPictureBox.Height > discord.Height
                                && !discordZoomCheckBox.Checked)
                            {
                                discordPictureBox.SizeMode = PictureBoxSizeMode.Normal;
                            }
                            else
                            {
                                discordPictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                            }
                            discordPictureBox.Image = discord;
                        }));
                    }
                }
                catch (IOException)
                {
                }
                catch
                {
                    MessageBox.Show("解答ファイルのフォーマットが不正です。");
                }
            });
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            RefreshDiscord();
        }

        private void discordZoomCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (discordPictureBox.Image != null)
            {
                RefreshDiscord();
            }
        }

        private void reloadButton_Click(object sender, EventArgs e)
        {
            ci.StampSideLength = (int)numericUpDown.Value;
            ReloadStamps();
        }

        private void discordPictureBox_DoubleClick(object sender, EventArgs e)
        {
            if (refreshButton.Enabled)
            {
                discordForm = new DiscordForm(this);
                discordForm.FormClosing += discordForm_FormClosing;
                discordForm.Show();
                refreshButton.Enabled = false;
                discordZoomCheckBox.Enabled = false; ;
            }
        }

        private void discordForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            refreshButton.Enabled = true;
            discordZoomCheckBox.Enabled = true;
        }

        private void beforePictureBox_DoubleClick(object sender, EventArgs e)
        {
            if (beforePictureBox.Image != null)
            {
                new PictureForm(ci.BeforePicture.Bytes, "初期画像").Show();
            }
        }

        private void afterPictureBox_DoubleClick(object sender, EventArgs e)
        {
            if (afterPictureBox.Image != null)
            {
                new PictureForm(ci.AfterPicture.Bytes, "最終画像").Show();
            }
        }

        private void Stamp_DoubleClick(object sender, EventArgs e)
        {
            int index = stampPanel.Controls.IndexOf(sender as PictureBox);
            new PictureForm(ci.Stamps[index].Bytes, string.Format("スタンプ{0}", index)).Show();
        }

        private void Stamp_MouseEnter(object sender, EventArgs e)
        {
            int index = stampPanel.Controls.IndexOf(sender as PictureBox);
            label4.Text = "No." + index + "  W=" + ci.StampsW[index] + "  H=" + ci.StampsH[index];
            label9.Text = "  W=" + ci.AfterW + "  H=" + ci.AfterH; 
        }

        private void autoCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            if (autoCheckBox.Checked && refreshButton.Enabled)
            {
                timer.Start();
            }
            else
            {
                timer.Stop();
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (refreshButton.Enabled)
            {
                RefreshDiscord();
            }
            else
            {
                discordForm.RefreshDiscord();
            }
        }

        private void interval_ValueChanged(object sender, EventArgs e)
        {
            timer.Interval = (int)interval.Value;
        }



        //探索打ち切り
        private void quitButton_Click(object sender, EventArgs e)
        {
            using (var writer = new StreamWriter("C:\\kyogi\\cmd_quit.txt"))
            {
                writer.WriteLine("1");
             
            }
        }

 


     
    }


   
}
