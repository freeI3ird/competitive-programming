/*
*******************************
Don't Stop when you are tired  *
Stop When you are Done         *
******************************* 
*/

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
void construct_tree(int ss,int se,int si,vi& arr,vi &tree)//: O(N) // ss :start of segment, se: end of segment, si : index of the segment
{
	if(ss==se)// leaf of complete tree
	{
		tree[si]= arr[ss];
		return ;
	}
	int mid= (ss+se)/2;
	construct_tree(ss,mid,2*si,arr,tree);
	construct_tree(mid+1,se,2*si+1,arr,tree);
	tree[si] = tree[2*si] + tree[2*si+1]; // can perform any operation here 
}
int range_query(int ss,int se,int si,int l,int r,vi &tree) // O(LogN)
{
	// if range is out of segment return non-considerable value
	if(ss>se||r<ss||se<l)
		return 0; // or anything that is desired, INT_MIN,INT_MAX;
	// if whole segment lies in the range then return value of this segment
	if(l<=ss&&se<=r)
		return tree[si];
	// if the segment and range partially overlapps then break the segment untill it is completely out or in the range
	int mid = (ss+se)/2;
	int left_ans = range_query(ss,mid,2*si,l,r,tree);
	int right_ans = range_query(mid+1,se,2*si+1,l,r,tree);
	return (left_ans+right_ans); // or anything that is desired
}
void point_update(int ss,int se,int si,int i,int value,vi &arr,vi &tree)  // O(LogN)
{
	// if point is not in the segment return 
	if(ss>se||i<ss||se<i) 
		return ;
	// if it is the leaf node then definitely its the point of updation becoz we have checked that it is in range of segment
	if(ss==se)
	{
		arr[i]= value;
		tree[si]+= value; // or anything that's desired
		return ;
	}
	// otherwise break the segment 
	int mid = (ss+se)/2;
	point_update(ss,mid,2*si,i,value,arr,tree);
	point_update(mid+1,se,2*si+1,i,value,arr,tree);
	// if update is done change the value of this segment also
	tree[si] = tree[2*si] + tree[2*si+1];
}
void range_update(int ss,int se,int si,int l,int r,int value,vi &arr,vi &tree)  // O(N) : can improve this with lazy propagation
{
	// if range is not in the segment return 
	if(ss>se||r<ss||se<l) 
		return ;
	// if it is the leaf node then definitely its the point of updation becoz we have checked that it is in range of segment
	if(ss==se)
	{
		arr[ss]= value;
		tree[si]= value; // or anything that's desired
		return ;
	}
	// otherwise break the segment 
	int mid = (ss+se)/2;
	range_update(ss,mid,2*si,l,r,value,arr,tree);
	range_update(mid+1,se,2*si+1,l,r,value,arr,tree);
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
    // Since the array is full binary tree i.e every node has 0 or 2 childs, therefore "if n = #leaf nodes, internal nodes = n-1"
    // So, total nodes = 2*n -1  = 2*leaf -1,
    // Now take the tree array : size = 2*leaf-1 for 1 indexing take 2*leaf
    // Now leaf != n , it is pow(2,x)>=n ,  x =  (int)(ceil(log2(n))) ; here pow(2,x) = smallest pow of 2 which is greater than n.
    // see https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/ 
    int x = (int)(ceil(log2(n)));
    int max_size = 2*pow(2,x)-1;
    vi tree(max_size+1);
    construct_tree(1,n,1,v,tree);	// if range is out of segment return non-considerable value
	// if range is out of segment return non-considerable value

    int l,r ;// query range 
	int value=0; 
    range_query(1,n,1,l,r,tree);	// if range is out of segment return non-considerable value

    point_update(1,n,1,i,value,v,tree); // at ith index update with value;
    range_update(1,n,1,l,r,value,v,tree);
}
