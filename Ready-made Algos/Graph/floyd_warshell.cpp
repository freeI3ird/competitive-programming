// Floyd_Warshell Algo : refer coreman page 694
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define vvi vector< vi >

// we don't need to use two matrices 'd1' and 'd2', we can update in the same matrix, nothing will get affected by that.
// When we take 'k' as intermediate node then we will access [i,k] and [k,j] cell for all 'i' and 'j', this means kth column and row are 
// accessed, we need to be sure that kth row and column are not modified. Now to modify them d[i,k] = d[i,k] + d[k,k], but d[k,k] =0, so
// d[i,k] = d[i,k] hence proved 
vvi Floyd_Warshell(vvi &graph)
{
	int n = graph.size();
	vvi d1(graph.begin(),graph.end());
	//vvi d2(n,vi(n+1,0));  we donot need d2
	//cout<<"Success:\n";
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				//cout<<i<<" :"<<j<<endl;
				// d(i,j,k) = min(d(i,j,k-1),d(i,k,k-1)+d(k,j,k-1))
				// d2[i][j] = min(d1[i][j],((d1[i][k]==INT_MAX||d1[k][j]==INT_MAX)?INT_MAX:(d1[i][k]+d1[k][j])));
				d1[i][j] = min(d1[i][j],((d1[i][k]==INT_MAX||d1[k][j]==INT_MAX)?INT_MAX:(d1[i][k]+d1[k][j])));
			}
		}
		//d1 = d2;
	}
	return d1;
}
int main()
{
	int n,e;
	cin>>n>>e;
	vvi graph(n+1,vi(n+1,INT_MAX));
	for(int i=1;i<=n;i++)
		graph[i][i]=0;
	int src,dest,wt;
	for(int i=1;i<=e;i++)		
	{
		cin>>src>>dest>>wt;
		graph[src][dest]=wt;
	}
	vvi dist = Floyd_Warshell(graph);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dist[i][j]==INT_MAX)
				printf("INF");
			else
				printf("%d  ",dist[i][j]);
		}
		cout<<endl<<endl;
	}
}
