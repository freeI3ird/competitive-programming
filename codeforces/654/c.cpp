#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, r;
        cin>>n>>r;
        if( r > n)
            r = n;
        ll count = 0;
        if( r == n)
        {
            count += 1;
            r = r-1;
        }
        count += (r*(r+1))/2;
        cout<<count<<endl;
    }
}