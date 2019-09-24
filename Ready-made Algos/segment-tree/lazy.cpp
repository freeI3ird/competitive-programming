/* Lazy Propagation used when range update is there ,otherwise no need 
   Soul of Logic : Update When only Required :if whole segment lies within the range of updation, 
   then update that segment node but don't go further , save update for its child .
   Now before query and updation check if some update is pending on it or not do that first
   */
// Lazy propagation : O(n + Q*logn)
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define mode 1000000007
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector< ii >
#define vvi vector< vi >
#define vvii vector< vii >
#define mp make_pair
#define pb push_back
#define read(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define read2(x,y) scanf("%d%d",&x,&y);
#define print2(x,y) printf("%d %d\n",x,y);
#define read_s(x) scanf("%s",x);
#define print_s(x) printf("%s",x);
#define rep(i,a,b) for(i=a;i<=b;i++)
//Time : O(N) , N : Size of segment tree which is nearly , 2*n-1 not exact 
void construct_tree(int ss,int se,int si,vi &tree)//: O(N) // ss :start of segment, se: end of segment, si : index of the segment
{
	if(ss==se)// leaf of complete tree
	{
		tree[si]= v[ss];
		return ;
	}
	int mid= (ss+se)/2;
	construct_tree(ss,mid,2*si,tree);
	construct_tree(mid+1,se,2*si+1,tree);
	tree[si] = tree[2*si] + tree[2*si+1]; // can perform any operation here 
}
int range_query(int ss,int se,int si,int l,int r,vi &tree,vi &lazy) // O(LogN)
{
	// if range is out of segment return non-considerable value
	if(ss>se||r<ss||se<l)
		return 0; // or anything that is desired, INT_MIN,INT_MAX;
	// if whole segment lies in the range then return value of this segment
	if(lazy[si]!=0)
	{
		tree[si] = tree[si] + (se-ss+1)*lazy[si];
		int left_child = 2*si;
		int right_child= 2*si+1;
		if(ss!=se)
		{
			lazy[left_child] += lazy[si];
			lazy[right_child] += lazy[si];
		}
		lazy[si]=0;
	}
	if(l<=ss&&se<=r)
		return tree[si];
	// if the segment and range partially overlapps then break the segment untill it is completely out or in the range
	int mid = (ss+se)/2;
	int left_ans = range_query(ss,mid,2*si,l,r,tree,lazy);
	int right_ans = range_query(mid+1,se,2*si+1,l,r,tree,lazy);
	return (left_ans+right_ans); // or anything that is desired
}
void point_update(int ss,int se,int si,int i,int value)  // O(LogN)
{
	// if point is not in the segment return 
	if(ss>se||i<ss||se<i) 
		return ;
	// if it is the leaf node then definitely its the point of updation becoz we have checked that it is in range of segment
	if(ss==se)
	{
		v[i]= value;
		tree[si]= value; // or anything that's desired
		return ;
	}
	// otherwise break the segment 
	int mid = (ss+se)/2;
	point_update(ss,mid,2*si,i,value,tree);
	point_update(mid+1,se,2*si+1,i,value,tree);
	// if update is done change the value of this segment also
	tree[si] = tree[2*si] + tree[2*si+1];
}
void range_update(int ss,int se,int si,int l,int r,int value,vi &tree,vi &lazy)  // O(N) : can improve this with lazy propagation
{
	// Check pending update 
	if(lazy[si]!=0)
	{
		tree[si] = tree[si] + (se-ss+1)*lazy[si]; // e.g when u have to add some value to all no. of range
		int left_child = 2*si;
		int right_child = 2*si+1;
		if(ss!=se)
		{
			lazy[left_child] += lazy[si]; // very important "+="
			lazy[right_child] += lazy[si];
		}
		lazy[si]=0;
	}
	// if range is not in the segment return 
	if(ss>se||r<ss||se<l) 
		return ;
	// if it is the leaf node then definitely its the point of updation becoz we have checked that it is in range of segment
	/*if(ss==se)
	{
		v[ss] = value;
		tree[si] = value; // or anything that's desired
		return ;
	}*/
	// here is some change ,if whole segment lies in the range then update it and no need to go down
	if(l<=ss&&se<=r) 
	{
		tree[si] += (se-ss+1)*value;
		if(ss!=se)
		{
			lazy[2*si] += value;
			lazy[2*si+1] += value;
		}
		return ;
	}
	// otherwise break the segment 
	int mid = (se+ss)/2;
	range_update(ss,mid,2*si,l,r,value,tree,lazy);
	range_update(mid+1,se,2*si+1,l,r,value,tree,lazy);
	// if update is done change the value of this segment also
	tree[si] = tree[2*si] + tree[2*si+1];
}
int main()
{
    int n;
    vi v(n+1); // 1...n
    int i,j;
    rep(i,1,n)
    	cin>>v[i];
    // Now take the tree array : size = 2*leaf-1 for 1 indexing take 2*leaf
    // Now leaf != n , it is pow(2,x)>=n ,  x =  (int)(ceil(log2(n))) 
    int x = (int)(ceil(log2n));
    int max_size = 2*pow(2,x)-1
    vi tree(max_size+1);
    vi lazy(max_size+1,0);
    construct_tree(1,n,1,tree);
    int l,r ;// query range  
    range_query(1,n,1,l,r,tree,lazy);
    point_update(1,n,1,i,value,tree); // at ith index update with value;
    range_update(1,n,1,l,r,value,tree,lazy);
}
