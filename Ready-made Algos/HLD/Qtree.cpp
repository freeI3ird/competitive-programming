/*
Author    : MANISH RATHI
Institute : NIT KURUKSHETRA

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
#define ii pair<int,int>
#define vi vector<int>
#define vii vector< ii >
#define vvi vector< vi >
#define vvii vector< vii >
#define mp make_pair
#define pb push_back
#define read(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define read2(x,y) scanf("%d%d",&x,&y);
#define print2(x,y) printf("%d %d\n",x,y);
#define read_s(x) scanf("%s",x);
#define print_s(x) printf("%s",x);
#define rep(i,a,b) for(i=a;i<=b;i++)
void dfs(int src,int par,int lev=0)
{
	father[src]=par;
	level[src]=lev;
	subsize[src]=1;
	int len= graph[src].size();
	for(int i=0;i<len;i++)
	{
		int v=graph[src][i];
		if(par==v)// 
			continue;
		dfs(v,src,level[src]+1);
		subsize[src]+=subsize[v];
	}
}
void preprocess()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
			sparse[i][j]=-1;
	}
	for(int i=0;i<n;i++)
	{
		sparse[i][0]=father[i];
	}
	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<n;i++)//for(int i=0;i+(1<<j)-1<n;i++): this doesnot work in the case of tree think
		{
			if(sparse[i][j-1]!=-1)
				sparse[i][j]= sparse[sparse[i][j-1]][j-1];
		}
	}
}
int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    int t,h;
    cin>>t;
    for(h=1;h<=t;h++)
    {
    	int n,a,b,c;
    	read(n);
    	vvi graph(n);
    	for(int i=0;i<n;i++)
    	{
    		read2(a,b);// u,v
    		read(c); // cost 
    		a--;b--;
    		graph[a].pb(b);
    		graph[b].pb(a);
    		// what to do with edge wt
    		//cout<<"Case #"<<h<<": "
    	}
    	// preparing the sparse table 
    	// find father,level,subsize
    	dfs(0,-1);// dfs(src,parent,level);
    	preprocess();
    	// lets decompose the tree
    	hld(0)// hld(curNode)
    }
    return 0;
}
void hld(int curNode)
{
	if(chainHead[chainNo]==-1)
		chainHead[chainNo]=curNode;
	nodeChain[curNode]=chainNo;
	nodePos[curNode]=chainSize[chainNo];
	chainSize[chainNo]++;
	int sc=-1,temp=-1;
	int len=graph[curNode].size();
	for(int i=0;i<len;i++)// finding special child
	{
		int v=graph[curNode][i];
		if(v==father[curNode]) continue;
		if(subsize[v]>temp)
		{
			temp=subsize[v];
			sc=v;
		}
	}
	if(sc!=-1)
	{
		hld(sc);
	}
	for(int i=0;i<len;i++)// finding special child
	{
		int v=graph[curNode][i];
		if(v==father[curNode]||v==sc) continue;
		chainNo++;
		hld(v);
	}
}
