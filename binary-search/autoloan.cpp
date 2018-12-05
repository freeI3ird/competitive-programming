#include<bits/stdc++.h>
using namespace std;

class AutoLoan
{
public:
	double interestRate(double ,double,int);
};

double AutoLoan::interestRate(double price, double monthlyPayment, int loanTerm)
{
	double lo = 0, hi = 100;
	double base = price, interest = 0.0, mp = monthlyPayment;
	int req_term = 0;

	while( (hi-lo) > 1e-9)
	{
		double mid = lo + (hi - lo)/2;
		req_term = 0;
		while(base >= mp)
		{
			interest = mid*base;
			base = base + interest - mp;
			req_term++;
		}
		if( req_term >= loanTerm)
		{
			hi = mid;
		}	
		else
		{
			lo = mid;
		}
	}
	return lo;
}