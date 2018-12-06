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

	while( ((hi-lo)/lo) > 1e-10)
	// for( int i =0 ;i<100;i++)
	{
		double mid = lo + (hi - lo)/2;
		req_term = 0;
		base = price;
		double rate = mid/12;
		interest = (rate/100)*base;
		if( interest >= mp)
		{
		    hi = mid;
		    continue;
		}
		while((base + (rate/100)*base- mp) > 1e-12 )
		{
			interest = (rate/100)*base;
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
		// BELOW LOGIC IS BETTER
		/*req_term = loanTerm;
		while(req_term > 0)
		{
			base = base + (rate/100)*base - mp;
			req_term--;
		}
		if( base > 1e-12)
			hi = mid;
		else
			lo = mid;
		*/	
	}
	return lo;
}
int main()
{
    AutoLoan ob1;
    double price = 2000, mp = 510 ;
    int loanterm = 4;
    cout<<ob1.interestRate(price, mp, loanterm);
    // cout<<"hello";
}
/*
Auto dealerships frequently advertise tempting loan offers in order to make it easier for people 
to afford the "car of their dreams". A typical sales tactic is to show you various cars, and
then talk in terms of what your monthly payment would be, to say nothing of how much you are 
actually paying for the car, how much interest you pay, or how long you have to make payments.

A typical auto loan is calculated using a fixed interest rate, and is set up so that you make 
the same monthly payment for a set period of time in order to fully pay off the balance. 
The balance of your loan starts out as the sticker price of the car. Each month,
the monthly interest is added to your balance, and the amount of your payment
is subtracted from your balance. (The payment is subtracted after the interest is added.)
The monthly interest rate is 1/12 of the yearly interest rate. Thus, if your annual percentage
rate is 12%, then 1% of the remaining balance would be charged as interest each month.

You have been checking out some of the cars at your local dealership, TopAuto.
An excited salesman has just approached you, shouting about how you can have
the car you are looking at for a payment of only monthlyPayment for only loanTerm months!
You are to return a double indicating the annual percentage rate of the loan,
assuming that the initial balance of the loan is price.
*/
