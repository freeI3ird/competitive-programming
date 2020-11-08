#include<bits/stdc++.h>
using namespace std;

#define ll long long

int isCompare(ll a, ll b, ll n, ll m)
{
    if(a > b)
    {
        a = a+b;
        b = a-b;
        a = a-b;
    }
    if(n > m)
    {
        n = n+m;
        m = n-m;
        n = n-m;
    }
    if( n > a)
    {
        if( m > b)
        {
            // n > a , m > b
            return 1;
        }
        else // m <=b
        {
            // n > a && m <= b
            if((n-a) > (b - m))
                return 1;
            else 
                return 0;
        }
    }
    else // n <= a 
    {
        if(m > b)
        {
            // n <= a && m > b
            if( (m-b) > ( a - n))
                return 1;
            else 
                return 0;
        }
        else
        {
            // n <=a , m <=b
            return 0;
        }
        
    }

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b,n,m;
        cin>>a>>b>>n>>m;
        if( isCompare(a,b,n,m) )
        {
            cout<<"No"<<endl;
            continue;
        }
        if( a > b)
        {
            a = a+b;
            b = a-b;
            a = a-b;
        }
        string ans = "";
        if(m > a)
        {
            ans = "No";
        }
        else 
            ans = "Yes";
        cout<<ans<<endl;
    }
}