// Take two sets 'S' and 'V-S' and everytime add a vertex from set 'V-S' to 'S' , the one having shortest distance
// time : O((E+V)logV)
void dijkstra(vvii &graph,int src)
{
	int vertex= graph.size();
	// initialization
	vi dist(v+1,INT_MAX);
	vi par(v+1,-1);
	set< ii > pq;
	dist[src]=0;
	for(int i=1;i<vertex;i++)
	{
		pq.insert(mp(dist[i],i));
	}
	while(pq.empty()==0)
	{
		ii p = *(pq.begin());
		pq.erase(p);
		int d = p.first;
		int u = p.second;
		int len = graph[u].size();
		for(int i=0;i<len;i++)
		{
			int v = graph[u][i].first;
			int wt = graph[u][i].second;
			// here it will never update its parent because distance of parent surely be less but same thing causes problem
			// in "prim's" algo there need to put a check if v E priority_queue, think of it 
			if(dist[v]> d + wt)
			{
				pq.erase(ii(dist[v],v));
				dist[v]= d+wt;
				pq.insert(ii(dist[v],v));
				par[v]=u;
			}
		}
	}
}