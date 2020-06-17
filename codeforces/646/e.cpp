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

struct Node
{
    ll val, target, cost;
    Node(int a,int b,int c)
    {
        cost = a;
        val = b;
        target = c;
    }
};
void dfs(vector< vi > &graph, int src, vector<Node*> &arr, int par)
{
    ll small = INT_MAX;
    if(par != -1)
        small = arr[par]->cost;
    arr[src]->cost  = min(small, arr[src]->cost);
    small = arr[src]->cost;
    int m = graph[src].size();
    for(int i = 0; i < m; i++)
    {
        int dest = graph[src][i];
        if(dest != par)
        {
            dfs(graph, dest, arr, src);
        }
    }
}
ii solve(vector< vi > &graph, int src, vector<Node*> &arr, ll &ans, int par)
{
    int cnt[] = {0,0};
    if(arr[src]->val != arr[src]->target)
    {
        cnt[arr[src]->val]++;
    }
    int m= graph[src].size();
    for(int i=0; i < m; i++)
    {
        int dest = graph[src][i];
        if(dest != par)
        {
            ii p = solve(graph, dest, arr, ans, src);
            cnt[0] += p.first;
            cnt[1] += p.second;
        }
    }
    ii result(0,0);
    ll rem = 0;
    if(cnt[0] > cnt[1])
    {
        result.first = cnt[0]-cnt[1];
        rem = cnt[1];
    }
    else
    {
        result.second = cnt[1] - cnt[0];
        rem = cnt[0];
    }
    ans += rem*(arr[src]->cost)*(2LL);
    return result;
}


int main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("outout1b.txt", "w", stdout);
    int n;
    cin>>n;
    vector<Node*> arr(n, NULL);
    int cnt[] = {0,0};
    for(int i = 1; i <= n; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        arr[i-1] = new Node(a,b,c);
        if(b != c)
        {
            cnt[b]++;
        }
    }
    vector< vi > graph(n);
    for(int i = 0; i < n-1; i++)
    {
        int src,dest;
        cin>>src>>dest;
        src--; dest--;
        graph[src].pb(dest);
        graph[dest].pb(src);
    }
    if(cnt[0] != cnt[1])
    {
        cout<<-1<<endl;
        return 0;
    }
    vi visited(n,0);
    dfs(graph, 0, arr, -1);
    ll ans = 0;
    solve(graph, 0, arr, ans, -1);
    cout<<ans<<endl;
    return 0;
}

