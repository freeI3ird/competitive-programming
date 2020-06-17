/****************************
Author    : MANISH RATHI    *
Handle    : free__bird      *
Institute : NIT KURUKSHETRA *
*****************************/

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define mode 1000000007
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define mp make_pair
#define pb push_back
#define read(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define read2(x,y) scanf("%d%d",&x,&y);
#define tr(container,it) \
	for(typeof(container.begin()) it= container.begin();it!=container.end();it++)
ll power(ll x,ll y){ ll res = 1;
	while(y > 0){ if (y & 1) res = (res*x) ; x = (x*x); y = y>>1; }  return res; }

ll count_bits(ll n){ ll cnt = 0;
	while(n > 0) { n = n/2 ; cnt = (cnt + 1) ;}  return cnt ; }

#define vii vector< pair<int,int> >
#define pii pair<int,int>
void construct_tree(int ss,int se,int si,vi& arr,vii &tree)//: O(N) // ss :start of segment, se: end of segment, si : index of the segment
{
    if(ss==se)// leaf of complete tree
    {
        tree[si]= make_pair(arr[ss], arr[ss]);
        return ;
    }
    int mid= (ss+se)/2;
    construct_tree(ss,mid,2*si+1,arr,tree);
    construct_tree(mid+1,se,2*si+2,arr,tree);
    int large = max(tree[2*si+1].first, tree[2*si+2].first);
    int small = min(tree[2*si+1].second, tree[2*si+2].second);
    tree[si] = make_pair(large, small); // can perform any operation here 
}
pii range_query(int ss,int se,int si,int l,int r,vii &tree) // O(LogN)
{
    // if range is out of segment return non-considerable value
    if(ss>se||r<ss||se<l)
        return make_pair(INT_MIN, INT_MAX); // or anything that is desired, INT_MIN,INT_MAX;
    // if whole segment lies in the range then return value of this segment
    if(l<=ss&&se<=r)
        return tree[si];
    // if the segment and range partially overlapps then break the segment untill it is completely out or in the range
    int mid = (ss+se)/2;
    pii left_ans = range_query(ss,mid,2*si+1,l,r,tree);
    pii right_ans = range_query(mid+1,se,2*si+2,l,r,tree);
    int large = max(left_ans.first, right_ans.first);
    int small = min(left_ans.second, right_ans.second);
    return make_pair(large, small); // or anything that is desired
}

int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    
    int t,h;
    read(t);
    for(h=1;h<=t;h++)
    {
        int n;
        read(n);//cin>>n;
        vi arr(n);
        for(int i = 0; i < n; i++)
            read(arr[i]); //cin>>arr[i];
        if(n == 1)
        {
            print(n); //cout<<n<<endl;
            continue;
        }
        if(n== 2)
        {
            print(n+1);//cout<<n+1<<endl;
            continue;
        }
        // int x = (int)(ceil(log2(n)));
        // int max_size = 2*pow(2,x)-1;
        // vii tree(max_size+5);
        vii tree(4*n);
        construct_tree(0,n-1,0,arr,tree);   
        int cnt = 0;
        cnt = n + n-1;
        for(int i = 0; i < n-2; i++)
        {
            int small = arr[i], large = arr[i];
            for(int j = i + 2; j < n; j++)
            {
                small = min(arr[i], arr[j]);
                large = max(arr[i], arr[j]);

                // pair<int,int> p = range_query(0,n-1,0,i,j,tree);
                if((abs(arr[i]-arr[j]) == large- small))
                    cnt++;
            }
        }
        print(cnt);//cout<<cnt<<endl;
    }
    return 0;
}
