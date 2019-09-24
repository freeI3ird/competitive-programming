Index: 
- Unweighted Shortest path: BFS 
- Weighted Shortest path (no negative edges): Dijkstra :O((V+E)logV)
- Weighted Shortest path (with negative edges+ no -ve weight cycle):Directed graph and cycles may be there 
	Bellmen-ford :O(V.E)
- Weighted Shortest Path (-ve edges+ Directed Acycle graph) : no cycle
	topolical sort ; traverse in that order and relax edges :O(V+E)



Doubts :

- Time Complexity of unweighted shortest distance with DFS
- Bellmen ford proof(done)
- karger Algorithm for Minimum cut.
