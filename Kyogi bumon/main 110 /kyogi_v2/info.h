 
#define  NONE  -999999.0

class StampInfo{
public:
	int use;


	//���܂łɉ���g������
	//���g������
	//�g���ĉ���v��������
};

class Stamp{
public:
	vector<SImage*> s;
	vector<StampInfo> sinf;

	


	int s_n;	//stamp_n
	int s_n_max;
	int s_min;	//stamp_min
public:
	//�R���X�g���N�^
	Stamp(int stamp_n);
	//�R�s�[�R���X�g���N�^
	Stamp(const Stamp &obj);
	//�f�X�g���N�^
	~Stamp();

	void append(SImage* stampimg);	//�X�^���v�摜�̒ǉ�
	bool check();		//�X�^���v���������ǂݍ��߂Ă��邩�`�F�b�N

	SImage* GetImg(int n) { return s[n]; }	//�X�^���v�摜�擾
	int N(){ return s_n; }				//�X�^���v��
	int Min() { return s_min; }			//�ŏ��X�^���v
	
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

public:	//�R�}���h�ϐ�
	int cmd_start;		//�{�I���[�h�̏ꍇ�A�������P�ɂȂ�ƒT���J�n
	int cmd_quit;		//�T���I��(�{�I���[�h�̏ꍇ�͎��̖��̑ҋ@�J�n
	int cmd_alno;		//�A���S���Y���ԍ�
	int cmd_msend;		//�r���𓚂��쐬�����M
	int cmd_param1;		//�p�����[�^�ύX
	int cmd_param2;

	//�S�T���E�ߖT�T��
	int search_mode;	// 0:�S�T��  1:�ߖT�T��

public: //����͂̂��߂̃p�����[�^
	int discord;
	float discord_rate;
private:
	//shoki_discord�𐶐�
	void GameInfo::set_discord();


	//
public:
	GameInfo();
	GameInfo(const GameInfo &obj);
	~GameInfo();

	void GameInfo::readfile(string fname);	//���ǂݍ���

	void read_command();	//�r�����ߓǂݍ���
	void reset_command();	//�r�����߃��Z�b�g

	void OutAnswer();				//�𓚏o��
	void OutAnswer_Middle( int tesu, Image * img );		//�r���ŉ𓚏o��

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

//�ߋ��̒T�����ʂ��i�[
class PastInfo{
public:
	GameInfo *gi;
	
private:
	float *** val;
public:
	//�R���X�g���N�^
	PastInfo( GameInfo* );

	//�R�s�[�R���X�g���N�^
	PastInfo( const PastInfo &obj );

	//�f�X�g���N�^
	~PastInfo();

	float GetVal( Move m );			//�l�̎擾
	void SetVal( Move m, float val );	//�l�̃Z�b�g

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
