
#define PG32 unsigned long int

//�摜�̊�{�N���X
class Image{
public:
	int w,h;	//���E�c
	int PGw;
	PG32 ** img;	//�摜�f�[�^
	vector<vector<unsigned short int>> ruiseki;
protected:
	Image * mask;	//�}�X�N
	vector<unsigned short int> * precom;
public:
	//�R���X�g���N�^
	Image(int w ,int h, Image* mask, vector<unsigned short int> * precom);
	//�R�s�[�R���X�g���N�^
	Image(const Image &obj);
	Image(const Image &obj1, const Image &obj2);	//obj1 XOR obj2 �̃C���[�W���쐬
	//void init(int v);
	void getimage(ifstream & fs);
	void outimage(ofstream & fs);
	
	bool is1px();
	bool stampShiftCross;
	~Image();
	//test
	void test_out();

	//���ԏo�͍쐬
	void middle_out( int tesu, int dis );

	void SetPixel( int x, int y, char val );
	char GetPixel( int x, int y );
	int Count();							//�l1�̃r�b�g�𐔂���
	PG32 GetPG( int x, int y );

	//csum
	unsigned long long csum();
	
	

protected:
	
	PG32 bit_p(int k);							//�w��r�b�g�ɃA�N�Z�X���邽�߂̃}�X�N�쐬
	void set_b(PG32 & dest, int k, char val);	//�w��r�b�g�ɒl���Z�b�g
	char get_b(PG32 & sourse, int k);			//�w��r�b�g�̒l�����o��
	int count_b(PG32 sourse);					//PG32�^��������l1�̃r�b�g�𐔂���

	//�X�^���v�p�̋@�\�@�V�t�g
private:
	char r_shift_b(PG32 & dest, char newlsb );
public:
	void r_shift();

	//Discord�C���[�W�p�̋@�\
public:
	int  _stampTry( Image *st, int PGx, int y );	//�X�^���v���������Ƃ��̕s��v�ˈ�v�ɕς�鐔�v�Z
	void _stampDo ( Image *st, int PGx, int y );	//�X�^���v������

	//br-bs
	void Image::MakeCumulative();
	int CalcBlack(int x, int y, int xran, int yran);
private:
	bool is_range( int PGx, int y );
};

class SImage{
public:
	int w,h;	//���E�c
	
	
public:
	Image *simg[32];	//Stamp�摜(32����)

public:
	//�R���X�g���N�^
	SImage( Image & StampImg );
	bool is1px() { 
		if (w==1 && h==1 && simg[0]->is1px()==true )
			return true;
		else return false;
	}

	
};

//�X�^���v�֐�
int StampTry( Image* d, SImage *st, int x, int y );
void StampDo( Image* d, SImage *st, int x, int y );

