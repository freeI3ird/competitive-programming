#include<bits/stdc++.h>
using namespace std;

class SortEstimate
{
public:
	double howMany(int c,int time);
};
double SortEstimate:: howMany(int c,int time)
{
	double lo = 1,hi = time;
	// while((hi-lo) > 1e-10)
	while((hi-lo)/lo > 1e-10) // this works
	{
		double mid = lo + (hi-lo)/2;
		double tmp = c*mid*log2(mid);
		cout<<"lo,hi,mid"<<lo<<", "<<hi<<", "<<mid<<endl;
		if(tmp > ((double)time))
			hi = mid;
		else 
			lo = mid;
	}
	return lo;
}
int main()
{
	SortEstimate obj;
	cout<<obj.howMany(1, 2000000000);
}