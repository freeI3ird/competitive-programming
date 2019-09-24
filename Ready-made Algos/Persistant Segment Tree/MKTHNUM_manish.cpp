#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
struct node{
	int count;// Total no. of elements present in Set 'S' in the range of this node
	node*left,*right;

	node(int cnt,node*l,node*r)
	{
		count=cnt;
		left=l;right=r;
	}
	node* insert(int ss,int se,int idx);// this function called by the previous version node,
	// returns the pointer to the new created node or the old version node(that is not modified)
};
node* null= new node(0,NULL,NULL);
node* node::insert(int ss,int se,int idx)
{
	if(idx<ss||se<idx) // out of range 
		return this; // old version node 
	// otherwise idx is in the range and a new element is going to be made in this range 
	// so new node is to be created 
	if(ss==se) // leaf node
	{
		return new node(this->count+1,null,null); 
		// new node's count is +1 greater than the old version 
		// null: special node signify the 'NULL' node i.e nothing 
	}
	// non-leaf node then modification is need to be done to its child as well as to itself also
	int mid= (ss+se)/2;
	// create a new node corresponding to old version of this node, increase its count by +1 to that of old version
	// its left and right child may be old one or new one
	return new node(this->count+1,this->left->insert(ss,mid,idx),this->right->insert(mid+1,se,idx));
}
int query(node*a,node*b,int ss,int se,int k)
{
	// we have to return the index of the k smallest no. out of elements present in SET 's'
	// we assumed that 'k' is passed in such a way that it is always in the range
	if(ss==se)
	{
		return ss; // this is desired index of kth smallest element
	}
	//int count= a->count - b->count; instead of this we can precheck in what side (left/right) we should go to find'k'
    int count= a->left->count - b->left->count;
	int mid = (ss+se)/2;
	if(count>=k)
		return query(a->left,b->left,ss,mid,k);
	else 
		return query(a->right,b->right,mid+1,se,k-count);
	// we did 'k-count' because 'count' no. of smaller elements are on the left side 
	// now from right side we have to find the (k-count) smallest no.
}
int arr[MAX+7];
int mpp[MAX+7];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);// n= 1e5,m=1e3
	map<int,int> M;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		M[arr[i]];
	}	
	// Now we have to do data compression
	int maxi=0;
	for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
	{
		M[it->first]= maxi;
		mpp[maxi]= it->first;
		maxi++;
	}
	// now the values are compressed and data lies in(0,maxi-1), maxi-1= total distinct elements
	// Need to create the segment tree for this range only (0,maxi-1)
	// Now create the segement trees with updates for ranges: (0-0,0-1,0-2,...,0-n-1);
	node* root[maxi];
	null->left= null;// Now this thing is really important
	null->right=null; 
	for(int i=0;i<n;i++)
	{
		root[i]= ((i==0)?null:root[i-1])->insert(0,maxi-1,M[arr[i]]);
	}
	// here we have successfully created the all segment trees
	while(m--)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		l--;r--;
		int idx= query(root[r],((l==0)?null:root[l-1]),0,maxi-1,k);
		printf("%d\n",mpp[idx]);
	}
}
