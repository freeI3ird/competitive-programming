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
    	int n,m,a,b;
        cin>>n>>m>>a>>b;
        if((n*a) != (m*b))
        {
            cout<<"NO"<<endl;
            continue;
        }
        vector< vi > grid(n, vi(m,0));
        vi cnt(m,0);
        for(int i = 0; i < n; i++)
        {
            vector< pair<int,int> > temp;
            for(int j = 0; j < m; j++)
            {
                temp.push_back(make_pair(cnt[j],j));
            }
            sort(temp.begin(), temp.end());
            for(int k = 0; k < a; k++)
            {
                grid[i][temp[k].second] = 1;
                cnt[temp[k].second] += 1;
            }
        }
        cout<<"YES"<<endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout<<grid[i][j];
            cout<<endl;
        }
    }
    return 0;
}
