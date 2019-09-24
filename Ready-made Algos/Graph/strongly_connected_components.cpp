/* Strongly Connected Components : Using Kosaraju Algo : Reference :
	- Apply DFS and store the finishing time of vertices 
	- Take TRANSPOSE of Graph 
	- Now again Apply DFS considering src vertex in decreasing order of finishing time
*/
// 	NOTE : WE CAN CREATE TRANSPOSE GRAPH AT THE TIME WE ARE TAKING INPUT GRAPH
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define ii pair<int,int>
#define vi vector<int>
#define vvii vector< vector< ii > >
#define vvi vector< vi >
void dfs(vvi &graph,int src,vi &visited,stack<int> &s)
{
	visited[src]=1;
	int len = graph[src].size();
	for(int i=0;i<len;i++)
	{
		int v = graph[src][i];
		if(visited[v]==0)
			dfs(graph,v,visited,s);
	}
	s.push(src);
}
void dfs2(vvi &traph,int src,vi &visited,vvi &cmpnt,int idx)
{
	visited[src]=1;
	int len = traph[src].size();
	cmpnt[idx].pb(src);
	for(int i=0;i<len;i++)
	{
		int v = traph[src][i];
		if(visited[v]==0)
			dfs2(traph,v,visited,cmpnt,idx);
	}
}

void SCC(vvi &graph,int n)
{
	// For odering of vertex in a/c to finishing time we are taking a stack
	stack<int > s;
	vi visited(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(visited[i]==0)
			dfs(graph,i,visited,s);
	}
	// Now take transpose of Graph : no need to do this create tgraph while taking input graph
	vvi traph(n+1);
	for(int i=1;i<=n;i++)
	{
		int len = graph[i].size();
		for(int j=0;j<len;j++)
		{
			int v = graph[i][j];	
			// u -> v transpose v -> u
			traph[v].pb(i);
		}
	}
	// Again Apply dfs but according to finishing time
	//memset(visited,0,sizeof(visited));
	for(int i=0;i<=n;i++)
		visited[i]=0;
	vvi cmpnt(n+1);
	int idx=1;
	while(s.empty()==0)
	{
		int src = s.top();
		s.pop();
		if(visited[src]==0)
		{
			dfs2(traph,src,visited,cmpnt,idx);
			idx++;
		}
		// use a smart loop here
	}
	// No of componts = idx-1
	for(int i=1;i<idx;i++)
	{
		printf("Component #%d :",i);
		int len = cmpnt[i].size();
		for(int j=0;j<len;j++)
			cout<<cmpnt[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	vvi graph(v+1);
	int src,dest,wt;
	// Directed Graph
	for(int i=1;i<=e;i++)
	{
		cin>>src>>dest;
		graph[src].pb(dest);
		// tgraph[dest].pb(src);  doing this is better
	}
	SCC(graph,v);
}