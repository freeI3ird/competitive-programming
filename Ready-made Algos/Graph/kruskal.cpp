/* In Kruskal’s algorithm, the set A is a forest whose vertices are all those of the given graph.
   The safe edge added to A is always a least-weight edge in the graph that connects two distinct components.
   In Prim’s algorithm, the set A forms a single tree. The safe edge added to A is always a least-weight edge
   connecting the tree to a vertex not in the tree.
 */
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii >
#define viii vector< iii >
#define vvii vector< vector< ii > >
#define pb push_back
#define mp make_pair
int find_set(vi &parent,int x)
{
	if(parent[x]<0)
		return x;
	parent[x] = find_set(parent,parent[x]);
	return parent[x];
}
void union_set(vi &parent,int u,int v)
{
	// in this implementation no need to check if they belong to same set,already done
	int par_u = find_set(parent,u);
	int par_v = find_set(parent,v);
	if(parent[par_u]<parent[par_v])
	{
		// par_u becomes parent
		parent[par_u]+= parent[par_v];
		parent[par_v] = par_u;
	}
	else
	{
		// par_v becomes the parent
		parent[par_v] += parent[par_u];
		parent[par_u] = par_v;
	}
}
vvii kruskal(viii &edge,int n)
{
	vi parent(n+1,-1); // make_set
	sort(edge.begin(),edge.end());
	vvii graph(n+1);// MST
	int sum =0;   // wt of MST
	int idx=0;
	for(int i=1;i<=n-1;i++)
	{
		int u,v,wt;
		do
		{
			iii p = edge[idx];
			 u = p.second.first;
			 v = p.second.second;
			 wt = p.first;
			idx++;
		// check cycle	
		}while(find_set(parent,u)==find_set(parent,v));
		sum+= wt;
		union_set(parent,u,v);
		graph[u].pb(mp(v,wt));
		graph[v].pb(mp(u,wt));
	}
	cout<<"Sum :"<<sum;
	return graph;
}
int main()
{
	int v,e;
	cin>>v>>e;
	viii edge(e+1);
	int src,dest,wt;
	for(int i=1;i<=e;i++)
	{
		cin>>src>>dest>>wt;
		edge.pb(mp(wt,mp(src,dest)));
	}
	vvii graph = kruskal(edge,v);
}
