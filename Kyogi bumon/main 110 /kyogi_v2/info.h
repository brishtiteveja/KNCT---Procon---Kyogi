 
#define  NONE  -999999.0

class StampInfo{
public:
	int use;


	//今までに何回使ったか
	//いつ使ったか
	//使って何個一致させたか
};

class Stamp{
public:
	vector<SImage*> s;
	vector<StampInfo> sinf;

	


	int s_n;	//stamp_n
	int s_n_max;
	int s_min;	//stamp_min
public:
	//コンストラクタ
	Stamp(int stamp_n);
	//コピーコンストラクタ
	Stamp(const Stamp &obj);
	//デストラクタ
	~Stamp();

	void append(SImage* stampimg);	//スタンプ画像の追加
	bool check();		//スタンプが正しく読み込めているかチェック

	SImage* GetImg(int n) { return s[n]; }	//スタンプ画像取得
	int N(){ return s_n; }				//スタンプ数
	int Min() { return s_min; }			//最小スタンプ
	
};

class Move{
public:
	int stamp;
	int x,y;
	Move(){};
	Move(int _stamp, int _x, int _y){
		stamp=_stamp;
		x=_x; y=_y;
	}
};


class GameInfo{
public:
	int w,h;
	int swmax,shmax;
	Image *shoki;
	Image *saishu;
	Stamp *stamp;
	Image *shoki_discord;

	//bit
	Image *mask;
	vector<unsigned short int> precom;

	string cmd_fname;

	time_t t;
	int alno;
	vector<Move> answer;
	int answer_tesu;

public:	//コマンド変数
	int cmd_start;		//本選モードの場合、ここが１になると探索開始
	int cmd_quit;		//探索終了(本選モードの場合は次の問題の待機開始
	int cmd_alno;		//アルゴリズム番号
	int cmd_msend;		//途中解答を作成し送信
	int cmd_param1;		//パラメータ変更
	int cmd_param2;

	//全探索・近傍探索
	int search_mode;	// 0:全探索  1:近傍探索

public: //問題解析のためのパラメータ
	int discord;
	float discord_rate;
private:
	//shoki_discordを生成
	void GameInfo::set_discord();


	//
public:
	GameInfo();
	GameInfo(const GameInfo &obj);
	~GameInfo();

	void GameInfo::readfile(string fname);	//問題読み込み

	void read_command();	//途中命令読み込み
	void reset_command();	//途中命令リセット

	void OutAnswer();				//解答出力
	void OutAnswer_Middle( int tesu, Image * img );		//途中で解答出力

	Image* CopyShokiImg() { 
		Image* ret = new Image(*shoki);
		return ret; 
	}
	Image* CopySaishuImg(){ 
		Image* ret = new Image(*saishu);
		return ret;
	}
	SImage* CopyStampImg(int n) { 
		SImage* ret = new SImage(*(stamp->s[n]));
		return ret;
	}
	Image* CopyDiscordImg(){ 
		Image* ret = new Image(*shoki_discord);
		return ret;
	}
	SImage* PointStampImg(int n){
		return stamp->s[n];
	}
	void ZeroTime(){ t=time(NULL);}
	time_t Time() { return time(NULL)-t;}
};

//過去の探索結果を格納
class PastInfo{
public:
	GameInfo *gi;
	
private:
	float *** val;
public:
	//コンストラクタ
	PastInfo( GameInfo* );

	//コピーコンストラクタ
	PastInfo( const PastInfo &obj );

	//デストラクタ
	~PastInfo();

	float GetVal( Move m );			//値の取得
	void SetVal( Move m, float val );	//値のセット

	void DeletePart( Move m );

	void test_out();
};


struct Move_v {
	Move move;
	int val;
	Move_v(){};
	Move_v( Move _move, int _val ){
		move=_move;
		val=_val;
	}
};
