#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> g[101000];
vector<int> tg[101000];
stack<int> s;
int vis[101000];

int scc[101000];
vector<int> ng[101000];
map< pair<int,int>,int > memo;
int rnk[101000];

void dfs(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        if(!vis[ g[x][i] ]){
            dfs(g[x][i]);
        }
    }
    s.push(x);
}

void dfs1(int x,int c){
    vis[x]=1;
    scc[x] = c;
    for(int i=0;i<tg[x].size();i++){
        if(!vis[ tg[x][i] ])
            dfs1(tg[x][i], c);
    }
}

void dfs2(int x){
    vis[x]=1;
    int t=0;
    for(int i=0;i<ng[x].size();i++){
        if(!vis[ ng[x][i] ]){
            dfs2(ng[x][i]);
        }
        t = max(t, rnk[ ng[x][i] ]);
    }
    rnk[x] = t+1;
}

int main()
{
   // freopen("sample01.txt","r",stdin);
    //freopen("sampleout01.txt","w",stdout);
    int i,j,k;
    int x,y,z;
    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        g[x].push_back(y);
        tg[y].push_back(x); // OMG , creating transpose graph along with the input
    }

    for(i=0;i<n;i++)
        if(!vis[i])
            dfs(i);

    for(i=0;i<n;i++)
        vis[i]=0;
    int c=0;
    while(!s.empty()){
        x = s.top();
        s.pop();

        if(!vis[x]){
            dfs1(x,c);
            c++;
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<g[i].size();j++){
            x = scc[i];
            y = scc[ g[i][j] ];

            if(x!=y && memo[make_pair(x,y)]==0){
                memo[make_pair(x,y)]=1;   // Removing duplicacy nice way to think
                ng[x].push_back(y);
            }
        }
    }

    for(i=0;i<n;i++)
        vis[i]=0;

    for(i=0;i<c;i++){
        if(!vis[i])
            dfs2(i);
    }

    int hRank = 0;
    for(i=0;i<c;i++){
        hRank = max(hRank, rnk[i]);
    }

    int ans=0;
    for(i=0;i<n;i++){
        if( rnk[ scc[i] ] == hRank )
            ans++;
    }

   /* for(i=0;i<n;i++)
        cout<<scc[i]<<" ";
    cout<<endl;
    cout<<"Num scc: "<<c<<endl;
    for(i=0;i<c;i++)
        cout<<rnk[i]<<" ";
    cout<<endl;*/

    printf("%d %d\n",hRank,ans);

    return 0;
}