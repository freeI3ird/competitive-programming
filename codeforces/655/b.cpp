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
        int a = 0,b=0;
        if(n%2 == 0) // even
        {
            a = b = n/2;
            cout<<a<<" "<<b<<endl;
            continue;
        }
        vi divisor;
        int i =0;
        for(i = 2; i*i < n; i++)
        {
            if(n%i==0)
            {
                divisor.push_back(i);
                divisor.push_back(n/i);
            }
        }
        if(i*i == n)
        {
            divisor.push_back(i);
        }
        sort(divisor.begin(), divisor.end());
        int len = divisor.size();
        if(len == 0)
        {
            a = 1; b = n-1;
        }
        else 
        {
            a = 1;
            vi arr;
            int num = n;
            int k = 0;
            while(num && k < len)
            {
                if(num%divisor[k] == 0)
                {
                    arr.push_back(divisor[k]);
                    num = num/divisor[k];
                }
                else
                {
                    k++;
                }
            }
            int len2 = arr.size();
            a=1;
            for(int k = 1; k < len2; k++)
                a = a*arr[k];
            b = n - a;
        }
        cout<<a<<" "<<b<<endl;
    }
    return 0;
}
