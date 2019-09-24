/*
	Sparse table:
	- A better approach is to preprocess RMQ for sub arrays of length (2^k)
	- Maintain an array M[0, N-1][0, logN] where M[i][j]=index of the minimum value in the sub array
	  starting at i having length 2j i.e sub array(i,i+ 2^j -1).
	- 2^j = 2^(j-1) + 2^(j-1) 
	=> M[i][j]= M[i][j-1] if arr[M[i][j-1]] <= arr[M[i+2^(j-1)-1][j-1]] 
		      = M[i+2^(j-1)-1][j-1] otherwise. 
*/
Algo :
Table_Construction(int M[][MAX],int arr[],int n) // 1-Base Indexing
{
	for(int i=1;i<=n;i++)
		M[i][0]=arr[i];
	for(int j=1;(1<<j)<=n;j++)// j=1 to logN
	{
		for(int i=1;i+(1<<j)-1<=n;i++)// i+2^j-1 <=n i.e
		{
			 M[i][j]= M[i][j-1] if arr[M[i][j-1]] <= arr[M[i+2^(j-1)-1][j-1]] 
		      		= M[i+2^(j-1)-1][j-1] otherwise.
		}
	}
}
/* Query :(l,r) 
	- This range (r-l+1) can be broken down in chunks of (2^k)
	- Because any number can be broken down in powers of 2
	or 
	- Take Two overlapping chunks covering the whole range 
	- range : k= log2(r-l+1)
	chunk1 = (l,l+2^k -1)
	chunk2 = (r-2^k+1, r)
*/
int k=log2(n);
int dp[n][k];
void preprocess(int arr[],int n)
{
	for(int i=0;i<n;i++)
		dp[i][0]=arr[i];
	// no. of columns k= log2(N)
	// dp[i][j] = stores (i,i+2^j-1) i.e 2^j elements and 2^j = 2^(j-1)+ 2^(j-1)
	for(int j=1;(1<<j)<=n;j++) // 1+2^j-1 <= n-1 or 0+2^j-1 <=n
	{
		for(int i=0;i+(1<<j)-1<n;i++)// i+2^j-1<=n-1
		{
			// dp[i][j]= min(dp[i][j-1],dp[i+2^j][j-1])
			dp[i][j]= min(dp[i][j-1],dp[i+(1<<j)][j-1]);
		}
	}
}
int query(int l,int r)
{
	int k= log2(r-l+1);
	int ans= min(dp[l][k],dp[r-(1<<k)+1][k]);
}