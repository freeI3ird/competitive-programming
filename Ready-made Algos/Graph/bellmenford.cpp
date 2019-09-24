/*Algo : Time : O(V.E)
BellmanFord(Graph *g,int src)
{
	Initialization :
	for(i=1 to g->v)
		dist[i]= INF
		par[i] = NIL
	dist[src]= 0;

	for(i=1 to V-1)    // How V-1 times help ? see below
	{
		for each edge (u-v)
			if(dist[v] > dist[u] + wt(u,v))     CAUTION:TAKE CARE OVERFLOW CAN  OCCUR HERE 
				dist[v] = dist[u] + wt(u,v);
				par[v] =u
	}
	// for checking negative cycle
	for(each edge (u-v))
		if(dist[v] > dist[u] + wt(u,v))
			then negative cylce exist
}
*/
/*  Intution:
	It first calculates the shortest distances for the shortest paths which have at-most one edge in the path.
 	Then, it calculates shortest paths with at-most 2 edges, and so on. After the ith iteration of outer loop, 
	the shortest paths with at most i edges are calculated. There can be maximum |V| – 1 edges in any simple path,
	that is why the outer loop runs |v| – 1 times.
*/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define iii pair< int,pair<int,int> >
void bellman_ford(vector< iii > &edge,int v,int src)
{
	// Initialization
	vi dist(v+1,INT_MAX);
	vi par(v+1,-1);
	dist[src]=0;
	int len = edge.size();
	for(int i=1;i<=v-1;i++)
	{
		for(int j=0;j<len;j++)
		{
			int u,v,wt;
			u = edge[j].second.first;
			v = edge[j].second.second;
			wt= edge[j].first;
			if(dist[u]!=INT_MAX&&dist[v] > dist[u] + wt)
			{
				dist[v] = dist[u] + wt;
				par[v] = u;
			}
		}
	}
	// Check for negative cycle
	for(int j=0;j<len;j++)
	{
		int u,v,wt;
		u = edge[j].second.first;
		v = edge[j].second.second;
		wt= edge[j].first;
		if(dist[u]!=INT_MAX&&dist[v] > dist[u] + wt)
		{
			cout<<"Negative cycle exists";
			return ;
		}
	}
	cout<<"Distances :"<<endl;
	for(int i=1;i<=v;i++)
	{
		cout<<i<<" :"<<dist[i]<<endl;
	}
}
int main()
{
	int v,e;
	cin>>v>>e;
	// Do we need adjacency list
	vector< iii > edge ;
	int src,dest,wt;
	for(int i=1;i<=e;i++)
	{
		cin>>src>>dest>>wt;
		edge.pb(mp(wt,mp(src,dest)));
	}	
	bellman_ford(edge,v,1);
} 
