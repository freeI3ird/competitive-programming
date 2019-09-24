#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector< vi > 
#define pb push_back
void bfs(vvi &graph,int src,vi &visited)
{
	queue<int> q;
	q.push(src);
	visited[src]=1;
	while(q.empty()==0)
	{
		int u = q.front(); 
		cout<<u<<" ";
		q.pop();
		int len = graph[u].size();
		for(int i=0;i<len;i++)
		{
			int v = graph[u][i];
			if(visited[v]==0)
			{
				visited[v] = 1;  // this is important to mark 'visited' here at time of pushing
				q.push(v);
			}
		}
	}
}
void bfs_util(vvi &graph)
{
	int n = graph.size();
	vi visited(n+1,0);
	cout<<"BFS:";
	for(int i=1;i<n;i++)
		if(visited[i]==0)
			bfs(graph,i,visited);
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
	bfs_util(graph);
}
