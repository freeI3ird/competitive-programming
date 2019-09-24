#include<bits/stdc++.h>
using namespace std;
#define MAX 100007
#define ll long long 
#define mode 1000000007
ll mypower(ll a,ll b)
{
	if(b==0)return 1;
	if(b==1)return a;
	ll temp= mypower(a,b/2);
	if(b&1)//odd
		return (((temp*temp)%mode)*a)%mode;
	else 
		return (temp*temp)%mode;
}
int arr[MAX+7];
int mpp[MAX+7];
struct node{
	int count;// Total no. of elements present in Set 'S' in the range of this node
	node*left,*right;
	ll hash;
	node(int cnt,node*l,node*r,ll hs):
		count(cnt),left(l),right(r),hash(hs) {}
	/*node(int cnt,node*l,node*r,ll h)
	{
		count=cnt;
		left=l;right=r;
		hash=h;
	}*/
	node* insert(int ss,int se,int idx,ll val);// this function called by the previous version node,
	// returns the pointer to the new created node or the old version node(that is not modified)
};
node *null= new node(0,NULL,NULL,0);
node * node::insert(int ss,int se,int idx,ll val)
{
	if(idx<ss||se<idx) // out of range 
		return this; // old version node 
	// otherwise idx is in the range and a new element is going to be made in this range 
	// so new node is to be created 
	if(ss==se) // leaf node
	{
		return new node(this->count+1,null,null,(this->hash+mypower(val,11))%mode); 
		// new node's count is +1 greater than the old version 
		// null: special node signify the 'NULL' node i.e nothing 
	}
	// non-leaf node then modification is need to be done to its child as well as to itself also
	int mid= (ss+se)/2;
	// create a new node corresponding to old version of this node, increase its count by +1 to that of old version
	// its left and right child may be old one or new one
	return new node(this->count+1,this->left->insert(ss,mid,idx,val),this->right->insert(mid+1,se,idx,val),(this->hash+mypower(val,11))%mode);
	// with everything I have also added the hash value also (oldnode->hash+ val^11)
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
// new query function that returns the the sum of hash val till the k smallest element
ll hashquery(node*a,node*b,int ss,int se,int k)
{
	if(ss==se)
	{
		int count= a->count-b->count;
		// count can be greater than k 
		count= count-k;
		ll result= mypower(mpp[ss],11);
		result= (count*result)%mode;
		return (((((a->hash - b->hash))%mode+mode)%mode-result)%mode+mode)%mode;
	}
	int count= a->left->count- b->left->count;
	int mid=(ss+se)/2;
	if(count>=k)
		return hashquery(a->left,b->left,ss,mid,k);
	else 
		return ((((a->left->hash- b->left->hash)%mode+mode)%mode)+hashquery(a->right,b->right,mid+1,se,k-count))%mode;
} 

int main()
{
	int h;
	scanf("%d",&h);
	for(int z=1;z<=h;z++)
	{
		//printf("\nCase start\n");
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
		node* root[MAX+7];
		null->left=null;// Now this thing is really important
		null->right=null; 
		for(int i=0;i<n;i++)
		{
			root[i]= ((i==0)?null:root[i-1])->insert(0,maxi-1,M[arr[i]],arr[i]);
		}
		// here we have successfully created the all segment trees
		while(m--)
		{
			int a,b,c,d;
			scanf("%d%d%d%d",&a,&b,&c,&d);
			a--;b--;c--;d--;
			int low=1,high=b-a+1;
			int flag=0;
			while(low<high)
			{
				int mid=(low+high)/2;
				int lhash1= hashquery(root[b],((a==0)?null:root[a-1]),0,maxi-1,mid);
				lhash1= lhash1 - ((low==1)?0:hashquery(root[b],((a==0)?null:root[a-1]),0,maxi-1,low-1));
				int lhash2= hashquery(root[d],((c==0)?null:root[c-1]),0,maxi-1,mid);
				lhash2= lhash2- ((low==1)?0:hashquery(root[d],((c==0)?null:root[c-1]),0,maxi-1,low-1));

				int rhash1= hashquery(root[b],((a==0)?null:root[a-1]),0,maxi-1,high);
				rhash1= rhash1 - lhash1;//((low==1)?0:hashquery(root[b],((a==0)?null:root[a-1]),0,maxi-1,low-1));
				int rhash2= hashquery(root[d],((c==0)?null:root[c-1]),0,maxi-1,high);
				rhash2= rhash2- lhash2;//((low==1)?0:hashquery(root[d],((c==0)?null:root[c-1]),0,maxi-1,low-1));

				if(lhash1==lhash2) 
				{
					low=mid+1;
				}
				else 
				{
					if(rhash1==rhash2)
						high=mid-1;
					else 
					{
						flag=1;break;
					}
				}
			}
			if(flag==0)// i.e  similar 
				printf("YES\n");
			else 
				printf("NO\n");
		}
		//printf("case finished\n");
	}
	return 0;
}
	
