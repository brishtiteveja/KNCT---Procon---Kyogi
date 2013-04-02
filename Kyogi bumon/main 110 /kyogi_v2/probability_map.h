
struct HProb{	//ƒqƒbƒgŠm—¦
	float probability;
	

};


class ProbMap{
private:
	HProb ***Map;
	GameInfo* gi;
public:
	float mag;	//”{—¦
public:
	ProbMap( GameInfo* gi );
	~ProbMap();

	void SetMag( float time );
	float average();
	float Prob( Move m );
	void Adjust();
	void ProbMap::MultiProb( Move m, float x );


};