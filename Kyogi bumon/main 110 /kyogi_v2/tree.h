class TNode{
public:
	class TNode* parent;
	int stamp;
	int x;
	int y;
	float value, cum_value;
	//float count_pow2;
	Image* img;
	PastInfo* past;
	list<Move_v> new_past_list;
public:
	bool operator <  ( const TNode& b ) const { return (value< b.value); }
	bool operator >  ( const TNode& b ) const { return (value> b.value); }
	TNode(){ 
		img=NULL; 
	}
	//コピーコンストラクタ
	TNode(const TNode &obj){
		parent=obj.parent;
		past=obj.past;
		stamp=obj.stamp;
		x=obj.x; y=obj.y;
		value=obj.value;
		cum_value=obj.cum_value;
		/*if(obj.img==NULL)
			img=NULL;
		else
			img=new Image(*obj.img);*/
		img=obj.img;
	}
	~TNode(){
//		if( img!=NULL )  delete img;
//		img=NULL;
	}
	Move getMove() { return Move(stamp,x,y); }
};

class Tree{
public:
	GameInfo* gi;
	list<TNode> * tnlist;
	list<list<TNode>*> tree;
	TNode top;
	int PARAM_E, PARAM_R, MAX_CHILDREN, MAX_MAX_CHILDREN;
	int gene;
	vector<Image*> parent_image;
	vector<Image*> parent_image2;
	vector<PastInfo*> parent_past;
	vector<PastInfo*> parent_past2;

	vector<unsigned short int> br_bsArray;
public:
	Tree(GameInfo* ginfo=NULL){
		gi=ginfo;
	}

	float calc_BlackParentChild();
	//float calc_value(TNode* node);
	int calc_discord(TNode* node);
	int br_bs(TNode* node, Move m);

	//探索関数
	//bool make_child(TNode* parent, list<TNode>* clist); //全探索


	void next_gene(list<TNode>* plist, list<TNode>* clist);
	void make_img(list<TNode>* clist);
	//void delete_oldimg();
	void msend( int gene );
	void outParentImg( Image * img );
	void ParentImgInit();
	void treemain();

};

class toThread{
public:
	int index;
	GameInfo * gi;
	list<TNode>  plist;
	list<TNode>  clist;
	static void nextgene_to_thread(void *ptr);
	//vector<unsigned short int> br_bsArray;
	
	toThread();
	void next_gene_inthread() ;
	bool make_child(TNode* parent, list<TNode>* clist); //全探索
	float calc_value(TNode* node);

};

#define THREAD_N 12

void engine_tree(GameInfo* gi);