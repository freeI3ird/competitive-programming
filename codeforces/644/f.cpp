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

int cmp(string &stg, string &base, int start, int end)
{
    if( start > end)
        return 1;

    for(int i = start; i <= end ; i++)
    {
        if(stg[i] != base[i])
            return 0;
    }
    return 1;
}
int solve(string &stg, string & base, int pos, int &fixed, int m)
{
    if(fixed == 1)
    {
        if(stg == base)
            return 1;
        else 
            return 0;
    }
    if( cmp(stg, base, 0,pos-1) == 0 && cmp(stg,base,pos+1,m) == 0)
    {
        return 0;
    }
    if( cmp(stg, base, 0,pos-1) == 1 && cmp(stg,base,pos+1,m) == 1)
    {
        return 1;
    }
    if( cmp(stg, base, 0, pos - 1) == 0)
    {
        int diff = 0;
        for(int i = 0; i < pos; i++)
        {
            if(stg[i] != base[i])
                diff++;
        }
        if(diff > 1)
            return 0;
        // for(int i = 0; i < pos; i++)
        // {
        //     if(stg[i] != base[i])
        //         stg[i] = base[i];
        // }
        fixed =1;
        stg[pos] = base[pos];
    }
    else
    {
        int diff = 0;
        for(int i = pos+1; i < m; i++)
        {
            if(stg[i] != base[i])
                diff++;
        }
        if(diff > 1)
            return 0;
        // for(int i = pos+1; i < m; i++)
        // {
        //     if(stg[i] != base[i])
        //         stg[i] = base[i];
        // }
        fixed =1;
        stg[pos] = base[pos];
    }
    return 1;
}
int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    int t,h;
    read(t);
    for(h=1;h<=t;h++)
    {
        int n,m;
        cin>>n>>m;
        vector<string> grid(n);
        for(int i =0; i < n; i++)
            cin>>grid[i];
        string ans = "";
        for(int pos = 0; pos < m; pos++)
        {
            string stg = grid[0];
            // int flag = 1; // find the ans 
            //int fixed = 0;
            //char save = stg[pos];
            for(int i =0; i < 26; i++)
            {
                stg[pos] = 'a'+i;
                //flag = 1;
                int j;
                for(j = 1; j < n; j++)
                {
                    int cnt = 0;
                    for(int k=0; k < m; k++)
                    {
                        if(stg[k] != grid[j][k])
                            cnt++;
                    }
                    if(cnt > 1)
                        break;
                    // flag = solve(stg, grid[i], pos, fixed,m);
                    //if(flag == 0) // this string can't be our result
                    //    break;
                }
                if( j == n)
                {
                    ans = stg;
                    break;
                }
            }
            if(ans != "")
                break;
            // if(flag == 1)
            //     break;
        }
        if(ans == "")
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
