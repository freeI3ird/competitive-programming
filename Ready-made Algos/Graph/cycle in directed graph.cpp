/*
*******************************
Don't Stop when you are tired  *
Stop When you are Done         *
******************************* 
*/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define mode 1000000007
#define ll long long
#define pll pair<ll,ll>
#define ii pair<int,int>
#define vl vector< ll >
#define vll vector< pll >
#define vi vector<int>
#define vii vector< ii >
#define vvi vector< vi >
#define vvii vector< vii >
#define mp make_pair
#define pb push_back
#define read(x) scanf("%d",&x)
#define write(x) printf("%d\n",x)
#define read2(x,y) scanf("%d%d",&x,&y);
#define write2(x,y) printf("%d %d\n",x,y);
#define read_s(x) scanf("%s",x);
#define write_s(x) printf("%s",x);
#define rep(i,a,b) for(i=a;i<=b;i++)
#define viii vector< pair<int, ii > >
int dfs(vvi &graph,int u,vi &color)
{
    color[u] = 1;
    int i,j,k,len;
    len = graph[u].size();
    rep(i,0,len-1)
    {
        int v = graph[u][i];
        if(color[v]==1)// grey;
            return 1;
        else if(color[v]==0)
            if(dfs(graph,v,color))
                return 1;
    }
    color[u]=2;// black
    return 0;
}
int isCycle(vvi &graph,int n)
{
    vi color(n+1,0);
    // 0 :white, 1 : grey ,2: black
    int i,j;
    rep(i,0,n-1)
    {
        if(color[i]==0)
        {
            if(dfs(graph,i,color))
                return 1;
        }
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n,e;
    	cin>>n>>e;
    	vvi graph(n+1);
    	int i,j,k,temp,src,dest;
    	rep(i,1,e)
    	{
    	    cin>>src>>dest;
    	    graph[src].pb(dest);
    	}
    	if(isCycle(graph,n))
    	    cout<<"1\n";
    	else cout<<"0\n";
    }
    return 0;
}
