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

#define vii vector< pair<int,int> >
#define pii pair<int,int>

int solve(vector< vi > &grid, int a, int b, vi &arr)
{
    int n = grid.size();
    vi par(n,-1);
    queue<int> q;
    q.push(a);
    int reachDest = 0;
    par[a] = a;
    while(q.empty() == false || !reachDest)
    {
        int cur = q.front(); q.pop();
        if(cur == b)
            reachDest = 1;
        else
        {
            int mysize = grid[cur].size();
            for(int i = 0; i < mysize; i++)
            {
                int dest = grid[cur][i];
                if(par[dest] == -1)
                {
                    par[dest] = cur;
                    q.push(dest);
                }
            }
        }
    }
    vi result;
    int cur = b;
    while(par[cur] != cur)
    {
        result.push_back(arr[cur]);
        cur = par[cur];
    }
    result.push_back(arr[cur]);
    sort(result.begin(), result.end());
    int small = INT_MAX;
    int m = result.size();
    for(int k = 1; k < m; k++)
    {
        small = min(small, result[k] - result[k-1]);
    }
    return small;
}

int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    
    int t,h;
    read(t);
    for(h=1;h<=t;h++)
    {
        int n, q;
        read(n);
        read(q);
        vi arr(n);
        for(int i = 0 ; i < n; i++)
            read(arr[i]);

        vector< vi > grid(n);
        for(int i = 1 ; i <= n-1; i++) // edges
        {
            int s,d;
            read(s); read(d);
            grid[s-1].pb(d-1);
            grid[d-1].pb(s-1);
        }
        for(int k =0 ; k < q; k++)
        {
            int a,b;
            read(a); read(b);
            cout<<solve(grid, a-1, b-1, arr)<<endl;
        }
    }
    return 0;
}
