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

int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    int t,h;
    t=1;
    for(h=1;h<=t;h++)
    {
    	int n;
        cin>>n;
        vi arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        vi b(n,-1);
        set<int> myset;
        int last = arr[n-1];
        for(int i= 0; i < last ; i++)
            myset.insert(i);
        for(int i = n-1; i >=1; i--)
        {
            if(arr[i-1] < arr[i])
            {
                b[i] = arr[i-1];
                myset.erase(arr[i-1]);
            }
        }
        int high = last+1;
        for(int i =0; i < n; i++)
        {
            if(b[i] == -1)
            {
                if(myset.empty())
                    b[i] = high;
                else
                {
                    b[i] = *(myset.begin());
                    myset.erase(b[i]);
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
