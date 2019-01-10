#include<bits/stdc++.h>
using namespace std;

int **mattrix;
int *pos;

int valid_Value(int k, int n)
{
	int cur_col = pos[k] -1 ;
	for( int x = k-1, coly = cur_col-1, colz = cur_col+1; x >=0; x--, coly--, colz++)
	{
		if( pos[x] == pos[k]) // same column condition
			return 0;

		if( coly >= 0) // condition for main diagonal
		{
			if(pos[x] - 1 == coly)
				return 0;
		}
		if(colz < n)  // condition for second diagonal
		{
			if(pos[x] - 1 == colz)
				return 0;
		}
	}
	return 1;
}
void next_Value(int k, int n)
{
	while(1)
	{
		pos[k] = (pos[k]+1)%(n+1);
		if(pos[k] == 0)
			return ;

		if(valid_Value(k, n))
			return;
	}
}
int back_Track(int k, int n)
{
	if( k == n )
		return 1;

	while(1)
	{
		next_Value(k, n);
		if( pos[k] == 0)
			return 0;
		if( back_Track(k+1, n))
			return 1;
	}
}
int main()
{
	int n = 8;
	printf("Enter the no. of Queens:");
	scanf("%d",&n);
	mattrix = (int**)malloc(sizeof(int*)*n);
	pos = (int*)malloc(sizeof(int)*n);
	for(int i=0; i < n;i++)
	{
		mattrix[i] = (int*)malloc(sizeof(int)*n);
		pos[i] = 0;
	}
	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j<n;j++)
			mattrix[i][j] = 0;
	}
	int solution = back_Track(0, n);
	if( solution )
	{	
		printf("Position of queens are: \n");
		for(int i = 0;i < n;i++)
		{	
			printf("%d, ",pos[i]);
			mattrix[i][pos[i]-1] = 1;
		}
		printf("\n");
		for(int i = 0;i < n;i++)
		{
			for(int j=0;j<n;j++)
				printf("%d ",mattrix[i][j]);
			printf("\n");
		}
	}
	else
	{
		printf("Solution doesnot exist");
	}
}
