/*
	SPARSE TABLE : stores the 2^i ancestor of some node
	Usage: -to ans the range queries query(L,R)
		   -only when 'arr is immutable' i.e no update queries
		   -Function F is associative: F(a, b, c) = F(F(a, b), c) = F(a, F(b, c)).
	Time: Preprocess : O(n*log(n))
		  Each query : O(log(n))
	Implementation:
		  - maintain 2d array => table[N][K],where N=no. of elements, K=O(logN))
		  - Exact Value of 'K':  lowest pow of 2,int x = floor(log2(N)) => K= x 
		  - table[i][j], ans the query from (L,R) = (i,i+(2^j)-1)
		  - (i,i+1,i+2,i+3,...,i+(2^j)-1) : total terms= 2^j
		  - means table is storing ans in powers of 2
		  - any no. can be break down in powers of 2 and these queries can be answered respectively
    Pseudo Code
    break_down(int n)
    {
		int k = floor(log2(n)); // such that n < 2^(k+1)
		for(i=k to 0)
			if(n>=(2^i))
				print(2^i)
				n=n-(2^i)
    }
    	  - How to Construct this table : table[i][j]
    	  - BASE CASE:for j=0 range [i,j] = (i,i+(2^0)-1) = (i,i) therefore table[i][0] = F(arr[i]) 
		  - for any i,j : table[i][j] contains 2^j terms => 2^j = 2^(j-1) + 2^(j-1) 
		  - table[i][j] = F(table[i][j-1],table[i+2^(j-1)][j-1])
		  - so for column j, col j-1 is need to be known, so things goes Column Wise
    Pseudo Code
    Table_Construction(int n)
    {
		int k= floor(log2(n));
		for(i=0 to n-1)
			table[i][0]=F(arr[i]);
		for(j=1 to k)
		{
			for(i=0 to (n-2^j))  // becoz i+2^j <= N, hence i <= (N-2^j)
			table[i][j]=F(table[i][j-1],table[i+2^(j-1)][j-1]);
		}
    }
	Applications : 
	- Range Sum queries
	- Range Min/Max queries
	- Range GCD queries
	- Applicable on tree
Problem : Given arr[1...N] ans the queries(L,R) find sum of elements
*/
int n=1e5;
int k=16;
// 2^17 > 1e5
ll table[n][k+1];
ll query(int l,int r)
{
	ll ans=0;
	for(int i=k;i>=0;i--)
	{
		//if(r-l+1>=pow(2,i))
		if((r-l+1)>= (1<<i))   // L+(2^j)-1 <= R
		{
			ans+= table[l][i];
			//l= l+pow(2,i);
			l= l+ (1<<i);  
		}
	}
	return ans;
}
void construct_table(vi &arr)
{
	for(int i=0;i<n;i++)
		table[i][0]= arr[i];
	for(int j=1;j<=k;j++)
	{
		for(int i=0;i<=(n-(1<<j));i++)
			table[i][j] = table[i][j-1] + table[i+(1<<(j-1))][j-1];
	}
}