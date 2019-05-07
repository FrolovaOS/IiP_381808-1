class Play
{
private:
	int n;
	int *Count1;//computer numbers
	int *Count2;//player numbers
	int Count[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int Cows;
	int Bulls;
public:
	Play();
	~Play();
	void Setn(int _n);
	void GetCount();//random number generation
	void SetCount();
	void GetAnswer();
	void coincidence();//number matches
	int ShowRes();

}; 
