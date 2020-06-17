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
    	int n, m;
        cin>>n>>m;
        vi rows(n,1);
        vi cols(m,1);
        int temp;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin>>temp;
                if(temp == 1)
                {
                    rows[i] = 0;
                    cols[j] = 0;
                }
            }
        }
        int cntr=0, cntc =0;
        for(int i = 0; i < n; i++)
        {
            if(rows[i] == 1)
                cntr++;
        }
        for(int i = 0; i < m; i++)
        {
            if(cols[i] == 1)
                cntc++;
        }
        int cnt = min(cntr, cntc);
        if(cnt&1)
            cout<<"Ashish"<<endl;
        else
            cout<<"Vivek"<<endl;
    }
    return 0;
}
