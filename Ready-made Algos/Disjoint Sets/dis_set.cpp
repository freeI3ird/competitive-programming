// Disjoint Set : here the code is most advance one 
// Used : Union by size and Path Compression : O((m+n)logn) , m = no. of queries reference: Narasimha Karumanchi
/* We take a parent array and make_set i.e initialize size for each set = -1
    find_set : then we recursively search for parent untill we get a negative value
	Union : first check if they belong to same set if not then the set with less size becomes the child of other
*/
// No. of components and Total no of nodes in each component can be find in a graph easily using this algo
#include<bits/stdc++.h>
using namespace std;
int find_set(vector<int> &parent,int x)
{
	if(x<=0|| x>parent.size()) // then out of range value of x
		return -1;
	if(parent[x]<0)
		return x;
	parent[x] = find_set(parent,parent[x]); // path compression
	return parent[x];
}
void union_set(vector<int> &parent,int x,int y)
{
	if(x<=0 || x> parent.size())
		return ;
	int par_x = find_set(parent,x);
	int par_y = find_set(parent,y);
	if(par_x==par_y)
		return ;   // they already belong to same set
	// otherwise union by size
	if(parent[par_x]<parent[par_y])
	{ 
		// x becomes parent and y child : because negative values are stored to represent the size
		parent[par_x]+= parent[par_y];
		parent[par_y] = x;
	}
	else
	{
		// y becomes parent 
		parent[par_y] += parent[par_x];
		parent[par_x] = y;
	}
}
int main()
{
	int n;
	cin>>n;
	vector<int> v(n+1,-1); // make_set 
}