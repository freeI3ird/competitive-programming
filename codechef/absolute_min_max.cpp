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
        vi arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        if(n == 1)
        {
            cout<<n<<endl;
            continue;
        }
        if(n== 2)
        {
            cout<<n+1<<endl;
            continue;
        }
        int l = 0, r = 1;
        int small = l;
        int large = r;
        if(arr[small] > arr[large])
        {
            small = r;
            large = l;
        }
        r++;
        int len = 0;
        int cnt = n;
        while(r < n)
        {
            if(arr[r-1] == arr[small])
            {
                // descending order 
                if(arr[r] <= arr[small])
                {
                    if(arr[r] < arr[small])
                        small = r;
                    r++;
                }
                else
                {
                    // previous segment ends here 
                    len = (r-1 - l + 1);
                    cnt += ((len*(len-1))/2);
                    l = small;
                    large = r;
                    int reduce = r-1 - l + 1;
                    if(reduce != 1)
                        cnt -= ((reduce*(reduce-1))/2);
                    r++;
                }
            }
            else
            {
                // ascending order 
                if(arr[r] >= arr[large])
                {
                    if(arr[r] > arr[large])
                        large = r;
                    r++;
                }
                else
                {
                    len = (r-1 - l + 1);
                    cnt += ((len*(len-1))/2);
                    l = large;
                    small = r;
                    int reduce = r- 1 - l + 1;
                    if(reduce != 1)
                        cnt -= ((reduce*(reduce-1))/2);
                    r++;
                }
            }
        }
        len = (r-1-l+1);
        cnt += ((len*(len-1))/2);
        cout<<cnt<<endl;
    }
    return 0;
}
