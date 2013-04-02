using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ConvertImageLibrary;

namespace KyogiAnimation2
{
    public partial class PictureForm : Form
    {
        byte[,] data;

        public PictureForm(byte[,] data, string title)
        {
            InitializeComponent();
            this.Text = title;
            this.data = data;
            RefreshPicture();
        }

        private void refreshButton_Click(object sender, EventArgs e)
        {
            RefreshPicture();
        }

        private void zoomCheckBox_CheckedChanged(object sender, EventArgs e)
        {
            RefreshPicture();
        }

        private void RefreshPicture()
        {
            System.Threading.ThreadPool.QueueUserWorkItem(o =>
            {
                var picture = ConvertImage.BytesToImage(data, pictureBox.Width);
                this.Invoke(new Action(() =>
                {
                    if (pictureBox.Width > picture.Width &&
                        pictureBox.Height > picture.Height && !zoomCheckBox.Checked)
                    {
                        pictureBox.SizeMode = PictureBoxSizeMode.Normal;
                    }
                    else
                    {
                        pictureBox.SizeMode = PictureBoxSizeMode.Zoom;
                    }
                    pictureBox.Image = picture;
                }));
            });
        }
    }
}
