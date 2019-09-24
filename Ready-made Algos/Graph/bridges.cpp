/* Bridges : refer to that edges after removing them , the no. of components increases 
   It is quite similar to Articulation point but here NO NEED OF SPECIAL CASE FOR THE ROOT NODE OF DFS TREE
   Algo :
   - Do dfs traversal 
   - if for node 'u', any child has low[v] > disc[u] then (u-v) is a bridge . (equality condition is missing)
   low[v] =   earliest visited vertex(i.e disc[] smallest) reachable from subtree rooted with v.
*/
// TIME : O(V+E)
// Reference :Geeks for Geeks
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define vvi vector< vi >
#define ii pair<int,int>
#define mp make_pair
#define MAX 1005
vi parent(MAX+1,-1);
int ttime=0;
vi visited(MAX+1,0);
vi disc(MAX+1,0);
vi low(MAX+1,0);
vector< ii > brdge;
void dfs(vvi &graph,int u)
{
	visited[u]=1;
	disc[u] = low[u] = ++ttime;
	int len = graph[u].size();
	for(int i=0;i<len;i++)
	{
		int v = graph[u][i];
		if(visited[v]==0)
		{
			parent[v]=u;
			dfs(graph,v);
			low[u] = min(low[u],low[v]);
			if(low[v]>disc[u])			// No equality condition and no special case for the ROOT node
				brdge.pb(mp(u,v));
		}
		else if(v!=parent[u])// i.e ensures back edge
			low[u] = min(low[u],disc[v]);
	}
}
void Bridge(vvi &graph,int n)
{
	// vi parent(n+1,-1);
	// int children =0;
	// vi visited(n+1,0);
	// vi disc(n+1,0);
	// vi low(n+1,0);
	for(int i=1;i<=n;i++)
		if(visited[i]==0)
			dfs(graph,i); // create dfs tree
	cout<<"Bridges :\n";
	int len= brdge.size();
	for(int i=0;i<len;i++)
		printf("(u-v) :%d--%d\n",brdge[i].first,brdge[i].second);
}
int main()
{
	int n,e;
	cin>>n>>e;
	vvi graph(n+1);
	int src,dest;
	for(int i=1;i<=e;i++)
	{
		cin>>src>>dest;
		graph[src].pb(dest);
		graph[dest].pb(src);
	}
	Bridge(graph,n);
}
