using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.IO;
using ConvertImageLibrary;

namespace KyogiAnimation2
{
    public partial class DiscordForm : Form
    {
        MainForm main;

        public DiscordForm(MainForm main)
        {
            InitializeComponent();
            this.main = main;
            discordPictureBox.Image = main.DiscordImage;
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            RefreshDiscord();
        }

        private void discordZoomCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            RefreshDiscord();
        }

        public void RefreshDiscord()
        {
            System.Threading.ThreadPool.QueueUserWorkItem(o =>
            {
                try
                {
                    using (var reader = new StreamReader(main.AnswerFilePath))
                    {
                        string repairCount = reader.ReadLine();
                        string discordCount = reader.ReadLine();
                        var discord = ConvertImage.GetDiscord(reader, discordPictureBox.Width);
                        this.Invoke(new Action(() =>
                        {
                            main.ShowCount(repairCount, discordCount);
                            if (discordPictureBox.Width > discord.Width &&
                                discordPictureBox.Height > discord.Height && !discordZoomCheckBox.Checked)
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
    }
}
