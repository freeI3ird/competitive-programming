#include<bits/stdc++.h>
using namespace std;

#define sz size()
#define pb push_back
#define rep(i,n) for(int i=0;i<n;i++)
#define fd(i,a,b) for(int i=a; i>=b; i--)

#define N 111111
#define ll long long
struct node
{
	int count;
	node *left, *right;
	ll val;

	node(int count, node *left, node *right,ll val):
		count(count), left(left), right(right),val(val) {}

	node* insert(int l, int r, int w);
};
ll mode=1000000007;
node *null = new node(0, NULL, NULL,0); //see line 135

int a[N], RM[N];
node *root[N];
ll power(ll a,ll b)
{
	if(b==0)return 1;
	if(b==1)return a;
	ll temp= power(a,b/2);
	if(b&1)//odd
		return ((temp*temp)%mode)%mode*a;
	else 
		return (temp*temp)%mode;
}
node * node::insert(int l, int r, int w)
{
	if(l <= w && w < r)
	{
		// With in the range, we need a new node
		if(l+1 == r)
		{
			return new node(this->count+1, null, null,(this->val+power(RM[w],11)%mode));
		}

		int m = (l+r)>>1;

return new node(this->count+1,this->left->insert(l,m,w),this->right->insert(m,r,w),((this->left->val+this->right->val)%mode+power(RM[w],11))%mode);
	}

	// Out of range, we can use previous tree node.
	return this;
}

ll query(node *a, node *b, int l, int r, int k)
{
	if(l+1 == r)
	{
		return (a->val-b->val);//this->val;
	}

	int m = (l+r)>>1;
	int count = a->left->count - b->left->count;
	if(count==k) // means this is the required node
		return (a->left->val-b->left->val);
	else if(count > k)
		return query(a->left, b->left, l, m, k);

	return ((a->left->val - b->left->val)+ query(a->right, b->right, m, r, k-count))%mode;
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n, m;
	    scanf("%d%d", &n, &m);
		map <int, int> M;
		rep(i, n)
		{
			scanf("%d", &a[i]);
			M[a[i]];
		}

		int maxi = 0;

		for(map <int, int> :: iterator it = M.begin(); it != M.end(); it++)
		{
			M[it->first] = maxi;
			RM[maxi] = it->first;
			maxi++;
		}
	//printf("RM[]: ");
	//for(int i=0;i<maxi;i++)
	//{
//		printf("%d ",RM[i]);
//	}
	//printf("\n");
		null->left = null->right = null;
		rep(i, n)
		{
			// Build a tree for each prefix using segment tree of previous prefix
			root[i] = (i == 0 ? null : root[i-1])->insert( 0, maxi, M[a[i]] );
		}
		for(int i=0;i<n;i++)
		{
			printf("val(0-%d):%lld\n",i,root[i]->val);
		}
	/*while(m--)
	{
		int u, v, k;
		scanf("%d%d%d", &u, &v, &k);
		u--; v--;

		int ans = query(root[v], (u==0?null:root[u-1]), 0, maxi, k);
		printf("%d\n", RM[ans]);
	}*/
	while(m--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		a--;b--;c--;d--;
		int low=0,high=b-a;
		int flag=0;
	while(low<high)
	{
		int mid= (low+high)/2;
			// find for a+low, b+mid => left portion
		ll left1,left2,right1,right2;
		if(low+1==high)
		{
			left1= query(root[b], (a==0?null:root[a-1]), 0, maxi, low+1);
		 	left2= query(root[d], (c==0?null:root[c-1]), 0, maxi, low+1);
		 	right1= query(root[b], (a==0?null:root[a-1]), 0, maxi, high+1)-left1;
		 	right2 = query(root[d], (c==0?null:root[c-1]), 0, maxi, high+1)-left2;
		}
		else
		{
		left1= query(root[b], (a==0?null:root[a-1]), 0, maxi, mid+1)-((low==0)?0:query(root[b], (a==0?null:root[a-1]), 0, maxi, low));
		left2= query(root[d], (c==0?null:root[c-1]), 0, maxi, mid+1)-((low==0)?0:query(root[d], (c==0?null:root[c-1]), 0, maxi, low));
		right1= query(root[b], (a==0?null:root[a-1]), 0, maxi, high+1)-query(root[b], (a==0?null:root[a-1]), 0, maxi, mid+1);
		right2 = query(root[d], (c==0?null:root[c-1]), 0, maxi, high+1)-query(root[d], (c==0?null:root[c-1]), 0, maxi, mid+1);
		}
		if(left1==left2)// i.e left are equal
			low=mid+1;
		else
		{
			if(right1==right2)// right sides are equal
				high=mid;
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
	}
}
//printf("low:%d,high:%d,left1:%lld,left2:%lld,right1:%lld,right2:%lld\n",low,high,left1,left2,right1,right2);
			