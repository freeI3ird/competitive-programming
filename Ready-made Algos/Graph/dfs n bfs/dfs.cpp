#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector< vi > 
#define pb push_back
void dfs(vvi &graph,int u,vi &visited)
{
	visited[u]=1;
	cout<<u<<" ";
	int len = graph[u].size();
	for(int i=0;i<len;i++)
	{
		int v = graph[u][i];
		if(visited[v]==0)
			dfs(graph,v,visited);
	}
}
void dfs_util(vvi &graph)
{
	int n = graph.size();
	vi visited(n+1,0);
	cout<<"DFS:";
	for(int i=1;i<n;i++)
		if(visited[i]==0)
			dfs(graph,i,visited);
}
int main()
{
	int v,e;
	cin>>v>>e;
	vvi graph(v+1);
	for(int i=1;i<=e;i++)
	{
		int src,dest;
		cin>>src>>dest;
		graph[src].pb(dest);
		graph[dest].pb(src);
	}
	dfs_util(graph);
}
