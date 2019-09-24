#include<bits/stdc++.h>
using namespace std;
#define MAX 1007
int graph[MAX][MAX];
int val[MAX];
int n;
void next_value(int k)
{
	while(1)
	{
		val[k]= (val[k]+1)%(n+1);
		if(val[k]==0) return;
		int i;
		if(k==1)
			break;
		for(i=1;i<k;i++)
		{
			if(val[i]==val[k])
				break;
		}
		if(i==k&&graph[val[k-1]][val[k]]==1)
		{
			if(k<n||(k==n&&graph[val[n]][val[1]]==1))
				return ;
		}
	}
}
int backtrack(int k)
{
	while(1)
	{
		next_value(k);
		if(val[k]==0)// if no value is valid on this position then backtrack
			return 0; 
		if(k==n) // k==n reached that means path is complete
		{
			for(int i=1;i<=n;i++)
				cout<<val[i]<<" ";
			cout<<val[1]<<endl;
			return 1;
		}	
		if(backtrack(k+1))
			return 1;
	}
}
int main()
{
	freopen("testcase.txt", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		val[i]=0;
		for(int j=1;j<=n;j++)
			cin>>graph[i][j];
	}
	val[1]=1;
	cout<<backtrack(2);
}
