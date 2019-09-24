#include<bits/stdc++.h>
using namespace std;
#define MAX 1007
void next_value(int k)
{
	while(1)
	{
		val[k]= (val[k]+1)%(n+1);
		if(val[k]==0) return;
		if(k==1)  // special case for k==1
			return ;
		int i;
		for(int i=1;i<k;i++)
		{
			if(val[i]==val[k])
				break;
		}
		if(i==k&&graph[val[k-1]][val[k]]==1)
			return ;
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
			return 1;
		if(backtrack(k+1))
			return 1;
	}
}