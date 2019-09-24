/* Articulation points(CUT VERTEX) : Those vertices in undirected graph ,removing them will divide the graph
   (increase the no. of components)
   SIMPLE THEORY : if we do DFS of a graph, we get DFS tree,take any vertex 'u',after removing
   this vertex, If all the ancestors and descendents can still be connected then it is not
   CUT vertex ,then it means there is back edge in subtree of 'u' which can connect it to ancestors of u.
   but if a single node in subtree(descendent) of 'u' violate this condition then 'u' is CUT vertex
   or in terms of children if any children 'v' has low[v] >= discovering_time[u] 
  
   ***** “Low” value of a node tells the topmost reachable ancestor (with minimum possible Disc value) 
   via the subtree of that node.******

   ALGO :
   - Do the dfs traversal,maintain parent[],discovery_time[],low[],children for every node
   - Any vertex is articulation point 
   		> if u=Root node , then children >1 (chidren>1 in dfs tree not graph)
   		> else among all its children atleast for one 'v', low[v]>= disc[u] i.e no back edge in sub-tree of 'v'
   		> the value low[v] indicates "earliest visited vertex"(i.e disc[] smallest) reachable from subtree rooted with v.
   - Common Mistakes :
   		back edge is from child to ancestor and same edge comes from ancestor to child(forward edge),
   		direct parent of some node 'v' is not to be considered for back edge
*/
// TIME : O(V+E)
// Reference :Geeks for Geeks
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define vi vector<int>
#define vvi vector< vi >
#define MAX 1005
vi parent(MAX+1,-1);
int ttime=0;
vi visited(MAX+1,0);
vi disc(MAX+1,0);
vi low(MAX+1,0);
vector<bool> art(MAX+1,false);
void dfs(vvi &graph,int u)
{
	visited[u]=1;
	disc[u] = low[u] = ++ttime;
	int len = graph[u].size();
	int child=0;
	for(int i=0;i<len;i++)
	{
		int v = graph[u][i];
		if(visited[v]==0)
		{
			// increase children of this node in dfs tree
			child++;
			parent[v]=u; // THIS CONDITION MUST BE BEFORE THE DFS CALL FOR V
			dfs(graph,v);
			low[u] = min(low[u],low[v]);
			if(parent[u]==-1&&child>1)// root node
				art[u]= true; 
			else if(parent[u]!=-1&&low[v]>=disc[u]) // other than root:no back edge in subtree(v)
				art[u] = true;
		}
		else if(v!=parent[u])// i.e ensures back edge ,this condition also true for 'forward edge' but that does not change
			low[u] = min(low[u],disc[v]);   // the val of low[u] becoz disc[v] > low[u] always in case of forward edge
	}
}
void cut_vertex(vvi &graph,int n)
{
	// vi parent(n+1,-1);
	// int children =0;
	// vi visited(n+1,0);
	// vi disc(n+1,0);
	// vi low(n+1,0);
	for(int i=1;i<=n;i++)
		if(visited[i]==0)
			dfs(graph,i); // create dfs tree
	cout<<"Articulation Points :";
	for(int i=1;i<=n;i++)
		if(art[i]==true)
			cout<<i<<" ";
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
	cut_vertex(graph,n);
}
