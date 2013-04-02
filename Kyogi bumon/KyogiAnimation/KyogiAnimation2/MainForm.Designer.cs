namespace KyogiAnimation2
{
    partial class MainForm
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.beforePictureBox = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.afterPictureBox = new System.Windows.Forms.PictureBox();
            this.label3 = new System.Windows.Forms.Label();
            this.discordPictureBox = new System.Windows.Forms.PictureBox();
            this.problemLoadButton = new System.Windows.Forms.Button();
            this.problemFileBox = new System.Windows.Forms.TextBox();
            this.answerFileBox = new System.Windows.Forms.TextBox();
            this.answerAssignmentButton = new System.Windows.Forms.Button();
            this.stampPanel = new System.Windows.Forms.FlowLayoutPanel();
            this.label5 = new System.Windows.Forms.Label();
            this.repairCountBox = new System.Windows.Forms.TextBox();
            this.label6 = new System.Windows.Forms.Label();
            this.discordCountBox = new System.Windows.Forms.TextBox();
            this.refreshButton = new System.Windows.Forms.Button();
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.label7 = new System.Windows.Forms.Label();
            this.numericUpDown = new System.Windows.Forms.NumericUpDown();
            this.reloadButton = new System.Windows.Forms.Button();
            this.stampZoomCheckBox = new System.Windows.Forms.CheckBox();
            this.discordZoomCheckBox = new System.Windows.Forms.CheckBox();
            this.stampGroupBox = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.autoCheckBox = new System.Windows.Forms.CheckBox();
            this.timer = new System.Windows.Forms.Timer(this.components);
            this.interval = new System.Windows.Forms.NumericUpDown();
            this.quitButton = new System.Windows.Forms.Button();
            this.label9 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.beforePictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.afterPictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.discordPictureBox)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown)).BeginInit();
            this.stampGroupBox.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.interval)).BeginInit();
            this.SuspendLayout();
            // 
            // beforePictureBox
            // 
            this.beforePictureBox.Location = new System.Drawing.Point(20, 59);
            this.beforePictureBox.Margin = new System.Windows.Forms.Padding(5, 6, 5, 6);
            this.beforePictureBox.Name = "beforePictureBox";
            this.beforePictureBox.Size = new System.Drawing.Size(150, 150);
            this.beforePictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.beforePictureBox.TabIndex = 0;
            this.beforePictureBox.TabStop = false;
            this.beforePictureBox.DoubleClick += new System.EventHandler(this.beforePictureBox_DoubleClick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(16, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(74, 24);
            this.label1.TabIndex = 1;
            this.label1.Text = "初期画像";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(196, 9);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(74, 24);
            this.label2.TabIndex = 2;
            this.label2.Text = "最終画像";
            // 
            // afterPictureBox
            // 
            this.afterPictureBox.Location = new System.Drawing.Point(200, 59);
            this.afterPictureBox.Name = "afterPictureBox";
            this.afterPictureBox.Size = new System.Drawing.Size(150, 150);
            this.afterPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.afterPictureBox.TabIndex = 3;
            this.afterPictureBox.TabStop = false;
            this.afterPictureBox.DoubleClick += new System.EventHandler(this.afterPictureBox_DoubleClick);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(16, 206);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(67, 24);
            this.label3.TabIndex = 4;
            this.label3.Text = "discord";
            // 
            // discordPictureBox
            // 
            this.discordPictureBox.Location = new System.Drawing.Point(20, 270);
            this.discordPictureBox.Name = "discordPictureBox";
            this.discordPictureBox.Size = new System.Drawing.Size(330, 330);
            this.discordPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.discordPictureBox.TabIndex = 5;
            this.discordPictureBox.TabStop = false;
            this.discordPictureBox.DoubleClick += new System.EventHandler(this.discordPictureBox_DoubleClick);
            // 
            // problemLoadButton
            // 
            this.problemLoadButton.Location = new System.Drawing.Point(630, 12);
            this.problemLoadButton.Name = "problemLoadButton";
            this.problemLoadButton.Size = new System.Drawing.Size(152, 30);
            this.problemLoadButton.TabIndex = 6;
            this.problemLoadButton.Text = "問題読み込み";
            this.problemLoadButton.UseVisualStyleBackColor = true;
            this.problemLoadButton.Click += new System.EventHandler(this.problemLoadButton_Click);
            // 
            // problemFileBox
            // 
            this.problemFileBox.BackColor = System.Drawing.Color.White;
            this.problemFileBox.Location = new System.Drawing.Point(366, 12);
            this.problemFileBox.Name = "problemFileBox";
            this.problemFileBox.ReadOnly = true;
            this.problemFileBox.Size = new System.Drawing.Size(258, 31);
            this.problemFileBox.TabIndex = 7;
            // 
            // answerFileBox
            // 
            this.answerFileBox.BackColor = System.Drawing.Color.White;
            this.answerFileBox.Location = new System.Drawing.Point(366, 49);
            this.answerFileBox.Name = "answerFileBox";
            this.answerFileBox.ReadOnly = true;
            this.answerFileBox.Size = new System.Drawing.Size(258, 31);
            this.answerFileBox.TabIndex = 8;
            // 
            // answerAssignmentButton
            // 
            this.answerAssignmentButton.Location = new System.Drawing.Point(630, 49);
            this.answerAssignmentButton.Name = "answerAssignmentButton";
            this.answerAssignmentButton.Size = new System.Drawing.Size(152, 30);
            this.answerAssignmentButton.TabIndex = 9;
            this.answerAssignmentButton.Text = "解答ファイル指定";
            this.answerAssignmentButton.UseVisualStyleBackColor = true;
            this.answerAssignmentButton.Click += new System.EventHandler(this.answerAssignmentButton_Click);
            // 
            // stampPanel
            // 
            this.stampPanel.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.stampPanel.AutoScroll = true;
            this.stampPanel.BorderStyle = System.Windows.Forms.BorderStyle.Fixed3D;
            this.stampPanel.Location = new System.Drawing.Point(20, 62);
            this.stampPanel.Name = "stampPanel";
            this.stampPanel.Size = new System.Drawing.Size(616, 528);
            this.stampPanel.TabIndex = 11;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Font = new System.Drawing.Font("メイリオ", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.label5.Location = new System.Drawing.Point(360, 107);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(56, 31);
            this.label5.TabIndex = 12;
            this.label5.Text = "手数";
            // 
            // repairCountBox
            // 
            this.repairCountBox.BackColor = System.Drawing.Color.White;
            this.repairCountBox.Font = new System.Drawing.Font("メイリオ", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.repairCountBox.Location = new System.Drawing.Point(451, 104);
            this.repairCountBox.Name = "repairCountBox";
            this.repairCountBox.ReadOnly = true;
            this.repairCountBox.Size = new System.Drawing.Size(119, 39);
            this.repairCountBox.TabIndex = 13;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Font = new System.Drawing.Font("メイリオ", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.label6.Location = new System.Drawing.Point(360, 152);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(77, 31);
            this.label6.TabIndex = 14;
            this.label6.Text = "不一致";
            // 
            // discordCountBox
            // 
            this.discordCountBox.BackColor = System.Drawing.Color.White;
            this.discordCountBox.Font = new System.Drawing.Font("メイリオ", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.discordCountBox.Location = new System.Drawing.Point(451, 149);
            this.discordCountBox.Name = "discordCountBox";
            this.discordCountBox.ReadOnly = true;
            this.discordCountBox.Size = new System.Drawing.Size(119, 39);
            this.discordCountBox.TabIndex = 15;
            // 
            // refreshButton
            // 
            this.refreshButton.Enabled = false;
            this.refreshButton.Location = new System.Drawing.Point(20, 233);
            this.refreshButton.Name = "refreshButton";
            this.refreshButton.Size = new System.Drawing.Size(81, 32);
            this.refreshButton.TabIndex = 16;
            this.refreshButton.Text = "更新";
            this.refreshButton.UseVisualStyleBackColor = true;
            this.refreshButton.Click += new System.EventHandler(this.refreshButton_Click);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "*.txt";
            this.openFileDialog.Filter = "テキストファイル|*.txt|すべてのファイル|*.*";
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(16, 27);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(74, 24);
            this.label7.TabIndex = 17;
            this.label7.Text = "辺の長さ";
            // 
            // numericUpDown
            // 
            this.numericUpDown.Location = new System.Drawing.Point(96, 25);
            this.numericUpDown.Maximum = new decimal(new int[] {
            2048,
            0,
            0,
            0});
            this.numericUpDown.Minimum = new decimal(new int[] {
            10,
            0,
            0,
            0});
            this.numericUpDown.Name = "numericUpDown";
            this.numericUpDown.Size = new System.Drawing.Size(67, 31);
            this.numericUpDown.TabIndex = 18;
            this.numericUpDown.Value = new decimal(new int[] {
            100,
            0,
            0,
            0});
            // 
            // reloadButton
            // 
            this.reloadButton.Enabled = false;
            this.reloadButton.Location = new System.Drawing.Point(236, 22);
            this.reloadButton.Name = "reloadButton";
            this.reloadButton.Size = new System.Drawing.Size(75, 32);
            this.reloadButton.TabIndex = 19;
            this.reloadButton.Text = "再読込";
            this.reloadButton.UseVisualStyleBackColor = true;
            this.reloadButton.Click += new System.EventHandler(this.reloadButton_Click);
            // 
            // stampZoomCheckBox
            // 
            this.stampZoomCheckBox.AutoSize = true;
            this.stampZoomCheckBox.Location = new System.Drawing.Point(169, 26);
            this.stampZoomCheckBox.Name = "stampZoomCheckBox";
            this.stampZoomCheckBox.Size = new System.Drawing.Size(48, 16);
            this.stampZoomCheckBox.TabIndex = 20;
            this.stampZoomCheckBox.Text = "拡大";
            this.stampZoomCheckBox.UseVisualStyleBackColor = true;
            // 
            // discordZoomCheckBox
            // 
            this.discordZoomCheckBox.AutoSize = true;
            this.discordZoomCheckBox.Checked = true;
            this.discordZoomCheckBox.CheckState = System.Windows.Forms.CheckState.Checked;
            this.discordZoomCheckBox.Enabled = false;
            this.discordZoomCheckBox.Location = new System.Drawing.Point(89, 205);
            this.discordZoomCheckBox.Name = "discordZoomCheckBox";
            this.discordZoomCheckBox.Size = new System.Drawing.Size(61, 28);
            this.discordZoomCheckBox.TabIndex = 21;
            this.discordZoomCheckBox.Text = "拡大";
            this.discordZoomCheckBox.UseVisualStyleBackColor = true;
            this.discordZoomCheckBox.CheckedChanged += new System.EventHandler(this.discordZoomCheckBox_CheckedChanged);
            // 
            // stampGroupBox
            // 
            this.stampGroupBox.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom)
                        | System.Windows.Forms.AnchorStyles.Left)
                        | System.Windows.Forms.AnchorStyles.Right)));
            this.stampGroupBox.Controls.Add(this.label4);
            this.stampGroupBox.Controls.Add(this.label7);
            this.stampGroupBox.Controls.Add(this.numericUpDown);
            this.stampGroupBox.Controls.Add(this.reloadButton);
            this.stampGroupBox.Controls.Add(this.stampZoomCheckBox);
            this.stampGroupBox.Controls.Add(this.stampPanel);
            this.stampGroupBox.Location = new System.Drawing.Point(366, 206);
            this.stampGroupBox.Name = "stampGroupBox";
            this.stampGroupBox.Size = new System.Drawing.Size(642, 596);
            this.stampGroupBox.TabIndex = 22;
            this.stampGroupBox.TabStop = false;
            this.stampGroupBox.Text = "スタンプ";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(317, 27);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(56, 24);
            this.label4.TabIndex = 26;
            this.label4.Text = "label4";
            // 
            // autoCheckBox
            // 
            this.autoCheckBox.AutoSize = true;
            this.autoCheckBox.Location = new System.Drawing.Point(107, 236);
            this.autoCheckBox.Name = "autoCheckBox";
            this.autoCheckBox.Size = new System.Drawing.Size(93, 28);
            this.autoCheckBox.TabIndex = 23;
            this.autoCheckBox.Text = "自動更新";
            this.autoCheckBox.UseVisualStyleBackColor = true;
            this.autoCheckBox.CheckedChanged += new System.EventHandler(this.autoCheckBox_CheckedChanged);
            // 
            // timer
            // 
            this.timer.Interval = 2000;
            this.timer.Tick += new System.EventHandler(this.timer_Tick);
            // 
            // interval
            // 
            this.interval.Location = new System.Drawing.Point(200, 235);
            this.interval.Maximum = new decimal(new int[] {
            300000,
            0,
            0,
            0});
            this.interval.Minimum = new decimal(new int[] {
            1,
            0,
            0,
            0});
            this.interval.Name = "interval";
            this.interval.Size = new System.Drawing.Size(82, 31);
            this.interval.TabIndex = 24;
            this.interval.Value = new decimal(new int[] {
            2000,
            0,
            0,
            0});
            this.interval.ValueChanged += new System.EventHandler(this.interval_ValueChanged);
            // 
            // quitButton
            // 
            this.quitButton.Location = new System.Drawing.Point(789, 13);
            this.quitButton.Name = "quitButton";
            this.quitButton.Size = new System.Drawing.Size(148, 29);
            this.quitButton.TabIndex = 25;
            this.quitButton.Text = "探索打ち切り";
            this.quitButton.UseVisualStyleBackColor = true;
            this.quitButton.Click += new System.EventHandler(this.quitButton_Click);
            // 
            // label9
            // 
            this.label9.AutoSize = true;
            this.label9.Location = new System.Drawing.Point(134, 29);
            this.label9.Name = "label9";
            this.label9.Size = new System.Drawing.Size(56, 24);
            this.label9.TabIndex = 27;
            this.label9.Text = "label9";
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 24F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1020, 814);
            this.Controls.Add(this.label9);
            this.Controls.Add(this.quitButton);
            this.Controls.Add(this.interval);
            this.Controls.Add(this.autoCheckBox);
            this.Controls.Add(this.stampGroupBox);
            this.Controls.Add(this.discordZoomCheckBox);
            this.Controls.Add(this.refreshButton);
            this.Controls.Add(this.discordCountBox);
            this.Controls.Add(this.label6);
            this.Controls.Add(this.repairCountBox);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.answerAssignmentButton);
            this.Controls.Add(this.answerFileBox);
            this.Controls.Add(this.problemFileBox);
            this.Controls.Add(this.problemLoadButton);
            this.Controls.Add(this.discordPictureBox);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.afterPictureBox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.beforePictureBox);
            this.Font = new System.Drawing.Font("メイリオ", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.Margin = new System.Windows.Forms.Padding(5, 6, 5, 6);
            this.Name = "MainForm";
            this.Text = "高専プロコン2011競技部門用GUI";
            ((System.ComponentModel.ISupportInitialize)(this.beforePictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.afterPictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.discordPictureBox)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.numericUpDown)).EndInit();
            this.stampGroupBox.ResumeLayout(false);
            this.stampGroupBox.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.interval)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox beforePictureBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.PictureBox afterPictureBox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.PictureBox discordPictureBox;
        private System.Windows.Forms.Button problemLoadButton;
        private System.Windows.Forms.TextBox problemFileBox;
        private System.Windows.Forms.TextBox answerFileBox;
        private System.Windows.Forms.Button answerAssignmentButton;
        private System.Windows.Forms.FlowLayoutPanel stampPanel;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.TextBox repairCountBox;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox discordCountBox;
        private System.Windows.Forms.Button refreshButton;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.NumericUpDown numericUpDown;
        private System.Windows.Forms.Button reloadButton;
        private System.Windows.Forms.CheckBox stampZoomCheckBox;
        private System.Windows.Forms.CheckBox discordZoomCheckBox;
        private System.Windows.Forms.GroupBox stampGroupBox;
        private System.Windows.Forms.CheckBox autoCheckBox;
        private System.Windows.Forms.Timer timer;
        private System.Windows.Forms.NumericUpDown interval;
        private System.Windows.Forms.Button quitButton;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label label9;
    }
}

