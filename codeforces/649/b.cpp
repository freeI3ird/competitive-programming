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

int isOrder(int l, int r, vi &arr)
{
    if(arr[l] > arr[r-1] && arr[r-1] > arr[r])
        return 1;
    if(arr[l] < arr[r-1] && arr[r-1] < arr[r])
        return 1;
    return 0;
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
        cin>>n;
        vi arr(n);
        for(int i =0; i < n; i++)
            cin>>arr[i];
        vi ans;
        int l =0, mid=2;
        for(mid = 2; mid < n; mid++)
        {
            if(isOrder(l,mid, arr) == 0)
            {
                ans.pb(arr[l]);
                l = mid-1; 
            }
        }
        ans.pb(arr[l]);
        ans.pb(arr[mid-1]);
        int ssize = ans.size();
        cout<<ssize<<endl;
        for(int i = 0; i < ssize; i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
