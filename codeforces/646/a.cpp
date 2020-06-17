/****************************
Author    : MANISH RATHI    *
Handle    : free__bird      *
Institute : NIT KURUKSHETRA *
*****************************/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define mode 1000000007
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define read(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define read2(x,y) scanf("%d%d",&x,&y);
#define tr(container,it) \
	for(typeof(container.begin()) it= container.begin();it!=container.end();it++)
ll power(ll x,ll y){ ll res = 1;
	while(y > 0){ if (y & 1) res = (res*x) ; x = (x*x); y = y>>1; }  return res; }

ll count_bits(ll n){ ll cnt = 0;
	while(n > 0) { n = n/2 ; cnt = (cnt + 1) ;}  return cnt ; }

int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    int t,h;
    read(t);
    for(h=1;h<=t;h++)
    {
        int n,x;
        cin>>n>>x;
        int num;
        int cnte=0, cnto=0;
        for(int i = 0; i < n; i++)
        {
            cin>>num;
            if(num&1)
                cnto++;
            else
                cnte++;
        }
        /*
            sum of x elements = odd 
            Sum = Odd = Odd + Even 
            if No_of_odds = 0, them Sum = Odd -> Not possible
            if x is even : 
                Even = Even + Even then x = No_of_odd_elements(even) + No_of_even_element(even), 
                    Sum = sum(Even_no_of_odd_element) +  sum(Even_no_of_even_element), this sum is always even , odd Not Possible
                Even = Odd + Odd then x = No_of_odd_elements(odd) + No_of_even_elements(odd)
                    Sum = sum(odd_no_of_odds_elements) + sum(even_no_of_even_elements0, this sum is always odd), POSSIBLE
            if x is ODD:
                ODD = ODD + EVEN 
                    SUM = sum(ODD_no_of_odd_elements) + sum(Even_no_of_even_elements), sum is always odd, POSSIBLE

                    SUM = sum(Even_no_of_odd_elements) + sum(ODD_no_of_even_elements), sum is always even, NOT POSSIBLE
        */
        if(cnto == 0)
        {
            cout<<"NO"<<endl;
            continue;
        }// No odd present
        if(cnte == 0)
        {
            if(x%2 ==0)
                cout<<"NO"<<endl;
            else
                cout<<"YES"<<endl;
            continue;
        }
        if(x%2 == 0)
        {
            if(cnte%2==0)
                cnte= cnte-1;
            if(cnto%2 == 0)
                cnto = cnto-1;
            if(cnte + cnto >= x)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else // x is odd 
        {
            if(cnte&1)
                cnte = cnte-1;
            if(cnto%2==0)
                cnto = cnto-1;
            if(cnte+cnto >= x)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
    return 0;
}
