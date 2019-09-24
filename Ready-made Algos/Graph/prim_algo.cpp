Prim Algo : In this Algorithm,
1. we maintain a set 'S' ,set of vertices present in the MST, 
2. Every time we Select  a vertex from 'V-S' that adds a safe edge(min. wt) to the tree,
3. then for all the adj vertices of this recently added vertex if it is present in priority queue then relax it.

Algo : O(V) + O(V) + O(V*logV) + O(E*logV) => O((V+E)LogV)
Prim(Graph*g,int u)
{
	// initialization 
	for(i=1 to g->v)     : O(V)
		dist[i] = INF;
		par[i] = NIL;
	dist[u]= 0;
	S = NULL;
	S = S U {u};
	priority queue Q;          
	Q = create_queue() ; :O(V)// where each node : (dist,idx)
	while(Q.empty()==0)  :O(V)
	{
		u = extract_min(Q);   :O(logV)
		S= S U {u};
		for each v E adj[u]   : O(E)
			if(v E Q && dist[v]> weight(u,v))  
				dist[v]= weight(u,v);
				update in queue;  : O(LogV)
				par[v]=u;
	}
}
// Implementation using set 
void prim(vvii &graph,int u,int n)
{
	// Initialization
	vi dist(n+1,INT_MAX);
	vi par(n+1,-1);
	dist[u]=0;
	// Priority Queue
	set< ii > pq;
	for(int i=1;i<=n;i++)
	{
		pq.insert(mp(dist[i],i));
	}
	int sum =0 ; // wt of mst
	while(pq.empty()==0)
	{
		ii p = *(pq.begin());
		sum += p.first;
		int u = p.second;
		pq.erase(p);
		int len = graph[u].size();
		 for(int i=0;i<len;i++)
		{
			int v = graph[u][i].first;
			int wt = graph[u][i].second;
			// if present is queue: this checking was not necessary in "dijkstra" but important in prim
			// because here dist[parent]> wt as distance has different meaning here.
			if(pq.find(ii(dist[v],v)!=pq.end()&&dist[v]>wt)
			{
				pq.erase(ii(dist[v],v));
				dist[v] =wt;
				pq.insert(ii(dist[v],v));
				par[v] = u;
			}

		}
	}
}	