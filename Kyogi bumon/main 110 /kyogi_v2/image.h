
#define PG32 unsigned long int

//画像の基本クラス
class Image{
public:
	int w,h;	//横・縦
	int PGw;
	PG32 ** img;	//画像データ
	vector<vector<unsigned short int>> ruiseki;
protected:
	Image * mask;	//マスク
	vector<unsigned short int> * precom;
public:
	//コンストラクタ
	Image(int w ,int h, Image* mask, vector<unsigned short int> * precom);
	//コピーコンストラクタ
	Image(const Image &obj);
	Image(const Image &obj1, const Image &obj2);	//obj1 XOR obj2 のイメージを作成
	//void init(int v);
	void getimage(ifstream & fs);
	void outimage(ofstream & fs);
	
	bool is1px();
	bool stampShiftCross;
	~Image();
	//test
	void test_out();

	//中間出力作成
	void middle_out( int tesu, int dis );

	void SetPixel( int x, int y, char val );
	char GetPixel( int x, int y );
	int Count();							//値1のビットを数える
	PG32 GetPG( int x, int y );

	//csum
	unsigned long long csum();
	
	

protected:
	
	PG32 bit_p(int k);							//指定ビットにアクセスするためのマスク作成
	void set_b(PG32 & dest, int k, char val);	//指定ビットに値をセット
	char get_b(PG32 & sourse, int k);			//指定ビットの値を取り出す
	int count_b(PG32 sourse);					//PG32型引数から値1のビットを数える

	//スタンプ用の機能　シフト
private:
	char r_shift_b(PG32 & dest, char newlsb );
public:
	void r_shift();

	//Discordイメージ用の機能
public:
	int  _stampTry( Image *st, int PGx, int y );	//スタンプを押したときの不一致⇒一致に変わる数計算
	void _stampDo ( Image *st, int PGx, int y );	//スタンプを押す

	//br-bs
	void Image::MakeCumulative();
	int CalcBlack(int x, int y, int xran, int yran);
private:
	bool is_range( int PGx, int y );
};

class SImage{
public:
	int w,h;	//横・縦
	
	
public:
	Image *simg[32];	//Stamp画像(32枚分)

public:
	//コンストラクタ
	SImage( Image & StampImg );
	bool is1px() { 
		if (w==1 && h==1 && simg[0]->is1px()==true )
			return true;
		else return false;
	}

	
};

//スタンプ関数
int StampTry( Image* d, SImage *st, int x, int y );
void StampDo( Image* d, SImage *st, int x, int y );

