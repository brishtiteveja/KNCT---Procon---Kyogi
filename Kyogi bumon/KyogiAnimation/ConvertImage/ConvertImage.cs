using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.IO;

namespace ConvertImageLibrary
{
    public class ConvertImage
    {
        public ImageData BeforePicture { get { return beforePicture; } }
        public ImageData AfterPicture { get { return afterPicture; } }
        public ImageData[] Stamps { get { return stamps; } }
        public int[] StampsW { get { return stampsW; } }
        public int[] StampsH { get { return stampsH ; } }
        public int AfterW { get { return afterW; } }
        public int AfterH { get { return afterH; } }

        public int PictureSideLength
        {
            get { return pictureSideLength; }
            set
            {
                pictureSideLength = value;
                beforePicture.Image = BytesToImage(beforePicture.Bytes, pictureSideLength);
                afterPicture.Image = BytesToImage(afterPicture.Bytes, pictureSideLength);
            }
        }
        public int StampSideLength
        {
            get { return stampSideLength; }
            set
            {
                stampSideLength = value;
                for (int i = 0; i < stamps.Length; i++)
                {
                    stamps[i].Image = BytesToImage(stamps[i].Bytes, stampSideLength);
                }
            }
        }

        public void SetStampSideLength( int stamp_no, int w, int h ) {
            if (w < h)
            {
                stamps[stamp_no].Image = BytesToImage(stamps[stamp_no].Bytes, h);
            }
            else
            {
                stamps[stamp_no].Image = BytesToImage(stamps[stamp_no].Bytes, w);
            }
        }

        public struct ImageData
        {
            public Image Image { get; set; }
            public byte[,] Bytes { get; set; }
            public int w { get; set; }
            public int h { get; set; }
        }

        private int pictureSideLength, stampSideLength;
        private ImageData beforePicture;
        private ImageData afterPicture;
        private ImageData[] stamps;


        private static int beforeW, beforeH, afterW, afterH; 
        private static int[] stampsW;
        private static int[] stampsH;
        private static int stampNo;
        private static int what;

        public ConvertImage(string problemFilePath, int pictureSideLength, int stampSideLength)
        {
            this.pictureSideLength = pictureSideLength;
            this.stampSideLength = stampSideLength;
            try
            {
                using (var reader = new StreamReader(problemFilePath))
                {
                    what = 0;
                    beforePicture = new ImageData { Bytes = GetBytes(reader) };
                    beforePicture.w = beforeW;
                    beforePicture.h = beforeH;
                    beforePicture.Image = BytesToImage(beforePicture.Bytes, pictureSideLength);
                    what = 1;
                    afterPicture = new ImageData { Bytes = GetBytes(reader) };
                    afterPicture.w = afterW;
                    afterPicture.h = afterH;
                    afterPicture.Image = BytesToImage(afterPicture.Bytes, pictureSideLength);
                    int stampCount = int.Parse(reader.ReadLine());
                    stamps = new ImageData[stampCount];
                    stampsW = new int[stampCount];
                    stampsH = new int[stampCount];
                    for (int i = 0; i < stampCount; i++)
                    {
                        what  = 2;
                        stampNo = i;
                        stamps[i] = new ImageData { Bytes = GetBytes(reader) };
                        stamps[i].w = stampsW[i];
                        stamps[i].h = stampsH[i];
                        stamps[i].Image = BytesToImage(stamps[i].Bytes, stampSideLength);
                    }
                   
                }
            }
            catch
            {
                throw;
            }
        }

        public Image GetFirstDiscord(int maxSideLength, out int discordCount)
        {
            int width, height, count;
            width = beforePicture.Bytes.GetLength(1);
            height = beforePicture.Bytes.GetLength(0);
            count = 0;
            byte[,] data = new byte[height, width];

            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    data[i, j] = (byte)(beforePicture.Bytes[i, j] ^ afterPicture.Bytes[i, j]);
                    if (data[i, j] == 1) count++;
                }
            }
            discordCount = count;
            return BytesToImage(data, maxSideLength);
        }

        /// <summary>
        /// 解答ファイルから discord の画像を取得
        /// </summary>
        /// <param name="reader">解答ファイルを読み込んでいる StreamReader</param>
        /// <param name="maxSideLength">画像の最大の辺の長さ</param>
        public static Image GetDiscord(StreamReader reader, int maxSideLength)
        {
            try
            {
                Image discord = null;
                discord = BytesToImage(GetBytes(reader), maxSideLength);
                return discord;
            }
            catch
            {
                throw;
            }
        }

        public static Image BytesToImage(byte[,] data, int maxSideLength)
        {
            int width = data.GetLength(1);
            int height = data.GetLength(0);
            SolidBrush brush = new SolidBrush(Color.Black);
            Bitmap bmp;
            Rectangle rec;
            if (width < maxSideLength / 2 && height < maxSideLength / 2)
            {
                int d = width > height ? maxSideLength / width : maxSideLength / height;
                bmp = new Bitmap(d * width, d * height);
                rec = new Rectangle(0, 0, d, d);
            }
            else
            {
                bmp = new Bitmap(width, height);
                rec = new Rectangle(0, 0, 1, 1);
            }

            using (var g = Graphics.FromImage(bmp))
            {
                g.Clear(Color.White);
                for (int i = 0; i < height; i++)
                {
                    for (int j = 0; j < width; j++)
                    {
                        if (data[i, j] == 1)
                        {
                            rec.Location = new Point(j * rec.Width, i * rec.Height);
                            g.FillRectangle(brush, rec);
                        }
                    }
                }
            }
            return bmp;
        }

        private static byte[,] GetBytes(StreamReader reader)
        {
            int width =  int.Parse(reader.ReadLine());
            int height =  int.Parse(reader.ReadLine());

            if (what == 2)
            {
                stampsW[stampNo] = width;
                stampsH[stampNo] = height;
            }
            else if (what == 1)
            {
                afterW = width;
                afterH = height;
            }
            else
            {
                afterW = width;
                afterH = height;
            }

            byte[,] data = new byte[height, width];
            for (int i = 0; i < height; i++)
            {
                var bits = reader.ReadLine().Select(c => byte.Parse(c.ToString())).ToArray();
                for (int j = 0; j < bits.Length; j++)
                {
                    data[i, j] = bits[j];
                }
            }
            return data;
        }
    }
}
