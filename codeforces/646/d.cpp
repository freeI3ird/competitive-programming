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

int binarySearch(int left, int right, int maxNum)
{
    if(left == right)
        return left;
    int l = left, r = right, mid = 0;
    int response=0;
    int ansIdx =0;
    while(l < r)
    {
        mid = l + (r-l)/2;
        // start query
        cout<<"? "<<(mid-l+1)<<" ";
        for(int i =l; i<=mid;i++)
            cout<<i<<" ";
        cout<<endl;            
        cout.flush();
        // end query

        cin>>response;
        if(response == -1)
            return 0;
        if(response == maxNum)
        {
            ansIdx = mid;
            r = mid;
        }
        else
        {   
            l = mid+1;
            ansIdx = mid+1;
        }
    }
    return ansIdx;
}

int main()
{
    //freopen("A-large.in", "r", stdin);
    //freopen("outout1b.txt", "w", stdout);
    int t,h;
    read(t);
    for(h=1;h<=t;h++)
    {
        int n,k;
        cin>>n>>k;
        vector< vi > subset(k);
        int num,idx;
        for(int i = 1; i <=k ; i++)
        {
            cin>>num;
            for(int j = 0;j<num; j++)
            {
                cin>>idx;
                subset[i-1].push_back(idx);
            }
        }
        // start of query
        cout<<"? "<<n<<" ";
        for(int i =1; i<=n;i++)
            cout<<i<<" ";
        cout<<endl;
            
        cout.flush();
        // end of query
        
        int response;
        cin>>response;
        if(response == -1) // end the program
        {
            return 0;
        }
        int maxNum = response;
        // binary search and find the idx of maxNum
        int maxIdx = binarySearch(1,n, maxNum);
        if(maxIdx == 0)
            return 0;
        vi arr(k);
        for(int i = 0; i < k; i++)
        {
            int m = subset[i].size();
            int j =0;
            for(j = 0; j < m;j++)
            {
                if(subset[i][j] == maxIdx)
                    break;
            }
            if(j == m)
                arr[i] = maxNum;
            else
            {
                vi visited(n+1,1);
                for(int x = 0; x < m;x++)
                {
                    visited[subset[i][x]] = 0;
                }
                // start of query
                cout<<"? "<<n-m<<" ";
                for(int i =1; i<=n;i++)
                {
                    if(visited[i])
                        cout<<i<<" ";
                }
                cout<<endl;
                    
                cout.flush();
                // end of query
                cin>>response;
                if(response == -1)
                    return 0;
                arr[i] = response;
            }
        }
        // make a guess
        cout<<"! ";
        for(int i =0; i < k; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
        string result;
        cin>>result;
        if(result=="Correct")
            continue;
        else
            return 0;

    }
    return 0;
}
