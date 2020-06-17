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
    read(t);
    for(h=1;h<=t;h++)
    {
        int n;
        cin>>n;
        vi arr(n,0);
        vi arr0,arr1;
        for(int i =0; i < n; i++)
        {
            cin>>arr[i];
            if(arr[i]&1)
                arr1.push_back(arr[i]);
            else
                arr0.pb(arr[i]);
        }
        int a,b;
        a = arr0.size(); b = arr1.size();
        int flag = 0;
        if(a&1)
        {
            for(int i =0; i < a; i++)
            {
                for(int j = 0; j < b; j++)
                {
                    if(abs(arr0[i]-arr1[j]) == 1)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
