/*
Author    : MANISH RATHI
Institute : NIT KURUKSHETRA

*******************************
Don't Stop when you are tired  *
Stop When you are Done         *
******************************* 
*/
/*
    Use the same concept as Inversion Count
    For each element find the no. of elements smaller in left side and large in right side
    then final_ans = small[i]*large[i]; treating each element as middle one
    treating it middle one only insures correct ans,think it why? 
    treating it leftmost or rightmost don't insure correctness
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
void point_update(vi &bit,int idx,int val)
{
	int len = bit.size();// 5000+1;
	while(idx<len)
	{
		bit[idx]+=val;
		idx = idx+(idx&(-idx));
	}
}
int getSum(vi &bit,int idx)
{
	// 1 - idx
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx = idx - (idx&(-idx));
	}
	return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	vi arr(n+1);
    	int i,j,k;
    	rep(i,1,n)
    		read(arr[i]);
    	vi bit(5001,0);
    	vii ans(n+1,ii(0,0));
    	point_update(bit,arr[1],1);
    	ans[1].first=0;// smaller elements
    	for(int i=2;i<=n;i++)
    	{
    		k= getSum(bit,arr[i]-1);
            point_update(bit,arr[i],1);
    		ans[i].first=k;
    	}
    	//memset(bit,0,sizeof(bit));
    	for(int i=0;i<5001;i++)
			bit[i]=0;
		ans[n].second=0;
    	point_update(bit,arr[n],1);
    	for(int i=n-1;i>0;i--)
    	{
    		k=getSum(bit,5000)-getSum(bit,arr[i]);
            point_update(bit,arr[i],1);
    		ans[i].second=k;
    	}
        int counter=0;
    	for(int i=1;i<=n;i++)
    	{
    		counter+= (ans[i].first)*(ans[i].second);
    	}
    	cout<<counter<<endl;
    }
    return 0;
}
