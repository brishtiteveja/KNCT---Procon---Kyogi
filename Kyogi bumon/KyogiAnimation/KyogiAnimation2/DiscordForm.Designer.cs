namespace KyogiAnimation2
{
    partial class DiscordForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.discordZoomCheckBox = new System.Windows.Forms.CheckBox();
            this.refreshButton = new System.Windows.Forms.Button();
            this.discordPictureBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.discordPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // discordZoomCheckBox
            // 
            this.discordZoomCheckBox.AutoSize = true;
            this.discordZoomCheckBox.Checked = true;
            this.discordZoomCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.discordZoomCheckBox.Location = new System.Drawing.Point(99, 15);
            this.discordZoomCheckBox.Name = "discordZoomCheckBox";
            this.discordZoomCheckBox.Size = new System.Drawing.Size(61, 28);
            this.discordZoomCheckBox.TabIndex = 25;
            this.discordZoomCheckBox.Text = "拡大";
            this.discordZoomCheckBox.UseVisualStyleBackColor = true;
            this.discordZoomCheckBox.CheckedChanged += new System.EventHandler(this.discordZoomCheckBox_CheckedChanged);
            // 
            // refreshButton
            // 
            this.refreshButton.Location = new System.Drawing.Point(12, 12);
            this.refreshButton.Name = "refreshButton";
            this.refreshButton.Size = new System.Drawing.Size(81, 32);
            this.refreshButton.TabIndex = 24;
            this.refreshButton.Text = "更新";
            this.refreshButton.UseVisualStyleBackColor = true;
            this.refreshButton.Click += new System.EventHandler(this.refreshButton_Click);
            // 
            // discordPictureBox
            // 
            this.discordPictureBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.discordPictureBox.Location = new System.Drawing.Point(12, 49);
            this.discordPictureBox.Name = "discordPictureBox";
            this.discordPictureBox.Size = new System.Drawing.Size(420, 420);
            this.discordPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.discordPictureBox.TabIndex = 23;
            this.discordPictureBox.TabStop = false;
            // 
            // DiscordForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(444, 481);
            this.Controls.Add(this.discordZoomCheckBox);
            this.Controls.Add(this.refreshButton);
            this.Controls.Add(this.discordPictureBox);
            this.Font = new System.Drawing.Font("メイリオ", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.Margin = new System.Windows.Forms.Padding(5, 6, 5, 6);
            this.Name = "DiscordForm";
            this.Text = "discord";
            ((System.ComponentModel.ISupportInitialize)(this.discordPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.CheckBox discordZoomCheckBox;
        private System.Windows.Forms.Button refreshButton;
        private System.Windows.Forms.PictureBox discordPictureBox;

    }
}