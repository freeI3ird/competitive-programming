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
        for(int i =0; i < n; i++)
            cin>>arr[i];
        vi g(n,-1), s(n,-1), sum(n,0), len(n,0), nextIdx(n,-1);
        int maxSum = -1;
        int startIdx = -1;
        int ansLen = 0;
        g[n-1] = n-1;
        s[n-1] = n-1;
        len[n-1] = 1;
        sum[n-1] = 0;
        for(int i = n-2; i >=0; i--)
        {
            g[i] = i;
            s[i] = i;
            if( arr[g[i+1]] > arr[g[i]])
                g[i] = g[i+1];
            if( arr[s[i+1]] < arr[s[i]])
                s[i] = s[i+1];

            int gSum = abs(arr[i] - arr[g[i]]) + sum[g[i]];
            int sSum = abs(arr[i] - arr[s[i]]) + sum[s[i]];
            int len1 = 1 + len[g[i]];
            int len2 = 1 + len[s[i]];
            if(gSum > sSum)
            {
                sum[i] = gSum;
                len[i] = len1;
                nextIdx[i] = g[i];
            }
            else if(gSum < sSum)
            {
                sum[i] = sSum ;
                len[i] = len2;
                nextIdx[i] = s[i];
            }
            else
            {
                if(len1 < len2)
                {
                    sum[i] = gSum ;
                    len[i] = len1;
                    nextIdx[i] = g[i];
                }
                else
                {
                    sum[i] = sSum;
                    len[i] = len2;
                    nextIdx[i] = s[i];   
                }
            }
            if(maxSum < sum[i])
            {
                maxSum = sum[i];
                ansLen = len[i];
                startIdx = i;
            }
            else if(maxSum == sum[i])
            {
                if(ansLen > len[i])
                {
                    ansLen = len[i];
                    startIdx = i;
                }
            }
        }
        // for(int i=0; i<n; i++)
        //     cout<<sum[i]<<" ";
        // cout<<endl;
        // for(int i =0; i < n; i++)
        //     cout<<g[i]<<" ";
        // cout<<endl;
        // for(int i = 0; i < n; i++)
        //     cout<<s[i]<<" ";
        // cout<<endl;
        cout<<ansLen<<endl;
        int cur = startIdx;
        while(cur != -1)
        {
            cout<<arr[cur]<<" ";
            cur = nextIdx[cur];
        }
        cout<<endl;
    }
    return 0;
}
