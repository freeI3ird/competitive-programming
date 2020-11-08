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
    	int n;
        cin>>n;
        if(n == 1)
        {
            cout<<"FastestFinger"<<endl;
            continue;
        }
        int cnt2=0, odd=0;
        while(n%2 == 0)
        {
            cnt2++;
            n = n/2;
        }
        if(n > 1)
            odd = 1;
        int cnto =0,i;
        for(i =3; i*i < n; i+=2)
        {
            if(n%i == 0)
            {
                cnto += 2;
            }
        }
        if( i*i == n )
            cnto += 1;
        
        // cout<<cnt2<<" "<<odd<<endl;
        if(odd==1)
        {
            if(cnt2 == 0)
            {
                cout<<"Ashishgup";
            }
            else
            {
                if(cnt2 == 1)
                {
                    if(cnto >=1)
                        cout<<"Ashishgup";
                    else
                        cout<<"FastestFinger";
                }
                else
                    cout<<"Ashishgup";
            }
        }
        else
        {
            if(cnt2 == 1)
                cout<<"Ashishgup";
            else 
                cout<<"FastestFinger";
        }
        cout<<endl;
    }
    return 0;
}
