// Time : O(n*k), space :O(k)
// C(n,k) : C(n-1,k-1)+C(n-1,k)
#include<stdc++.h>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	int c[k+1];
	for(int i=0;i<=k;i++) 
		c[i]=0;
	c[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=min(i,k);j>0;j--)
		{
			c[j]= c[j]+ c[j-1]; // C(n,j)=C(n-1,j)+C(n-1,j-1)
		}
	}
	printf("%d",c[k]);
}