/* Component Graph: This graph consider the SCC as its vertices 
 	- IT is DAG(Directed Acyclic Graph) ,so Topological Sort is possible
 	- Infact the way we produce SCC they all are in topological order
	Used strongly_connected_components.cpp
*/
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
void dfs2(vvi &traph,int src,vi &visited,vvi &cmpnt,int idx,vi &mapng)
{
	visited[src]=1;
	int len = traph[src].size();
	cmpnt[idx].pb(src);
	mapng[src]= idx;
	for(int i=0;i<len;i++)
	{
		int v = traph[src][i];
		if(visited[v]==0)
			dfs2(traph,v,visited,cmpnt,idx,mapng);
	}
}
void dfs3(vvi &graph,int src,vi &visited,vi &rank)
{
	visited[src]=1;
	int len = graph[src].size();
	for(int i=0;i<len;i++)
	{
		int v = graph[src][i];
		if(visited[v]==0)
			dfs3(graph,v,visited,rank);
		rank[src] = max(rank[src],1+rank[v]);
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
	// Now take transpose of Graph
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
	vi mapng(n+1,0);
	while(s.empty()==0)
	{
		int src = s.top();
		s.pop();
		if(visited[src]==0)
		{
			dfs2(traph,src,visited,cmpnt,idx,mapng);
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
	// Now to get Component Graph , G =(V1,E1) we need set V1 adn E1 
	// V1 : no. of distinct vertices i.e components given by idx-1
	// E1 : we will find it using mapping 'mapng' : vertex ~~> component
	// Now we will traverse the graph and generate the ordered pair (x,y) ; x= SCC(u),y= SCC(u) for (u,v) E 'E'
	// now we just have to remove the duplicate pair from it : for this either use Counting Sort :O(E) or set :O(ElogE)
	// I am using set for convience if TLE is there than modifiy it
	set< ii > edge;
	for(int i=1;i<=n;i++)
	{
		int len = graph[i].size();
		for(int j=0;j<len;j++)
		{
			int x,y,v;
			v = graph[i][j];
			x = mapng[i];
			y = mapng[v];
			if(x!=y)
				edge.insert(mp(x,y));
		}
	}
	// Now we have V1 = {1,2,...,idx-1} and E1 = set edge
	vvi c_graph(idx+1);
	set< ii > ::iterator it;
	for(it=edge.begin();it!=edge.end();it++)
	{
		int u,v;
		u = it->first;
		v = it->second;
		c_graph[u].pb(v);
	}
	// Now we have our Component Graph;
	printf("Component graph :\n");
	for(int i=1;i<idx;i++)
	{
		int len = c_graph[i].size();
		printf("#%d: ",i);
		for(int j=0;j<len;j++)
			cout<<c_graph[i][j]<<" ";
		cout<<endl;
	}
	// if the leaf node as Rank=1 and the node above other node in hierarchy has rank 1 more than below level
	// finding the max rank component and no. of its members
	vi rank(idx+1,1);
	vi c_visited(idx+1,0);
	for(int i=1;i<idx;i++)
	{
		if(c_visited[i]==0)
			dfs3(c_graph,i,c_visited,rank);
	}
	int max_rank=INT_MIN,member=0;
	for(int i=1;i<idx;i++)
	{
		if(rank[i]>max_rank)
		{
			max_rank = rank[i];
			member = cmpnt[i].size();
		}
		else if(rank[i]==max_rank)
		{
			member += cmpnt.size();
			//int temp = cmpnt[i].size(); HERE I WAS DOING MISTAKE : They have asked highest Rank and no. of people having it
			//member = max(member,temp);  Not that the size of group having the highest rank ,two or more components can have
			// 					    	  highest ranks 
		}
	}	
	printf("%d %d",max_rank,member);
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
	}
	SCC(graph,v);
}
