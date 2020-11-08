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

vi cycle;
void dfs(int cur, vector< vi> &graph, vi &path, vi &visited, int par)
{
    visited[cur] = 1;
    path.pb(cur);
    int m = graph[cur].size();
    for(int i = 0; i < m ;i++)
    {
        int v = graph[cur][i];
        if(v != par && visited[v] == 0)
            dfs(v, graph, path, visited, cur);
        else if(v != par && visited[v] == 1) // cycle
        {
            int pSize = path.size();
            if( cycle.size() == 0)
            {
                for(int j = pSize-1; j >= 0 ; j--)
                {
                    if(path[j] == v)
                    {
                        cycle.pb(v);
                        break;
                    }
                    else
                        cycle.pb(path[j]);
                }
            }
        }
    }
    path.pop_back();
}
void findCycle(vector< vi > &graph, int n)
{
    int cur = 1;
    vi path;
    vi visited(n+1, 0);
    dfs(cur, graph, path, visited, -1);
}

void bfs(vector< vi > &graph ,int n, int k)
{
    set<int> s[2];
    queue< ii > q;
    q.push(mp(1, 0));
    vi visited(n+1, 0);
    s[0].insert(1);
    visited[1] = 1;
    while(q.empty() == false)
    {
        ii p = q.front(); q.pop();
        int setNo = (p.second^1);
        int m = graph[p.first].size();
        for(int i = 0; i < m ; i++)
        {
            int v = graph[p.first][i];
            if(visited[v] == 0)
            {
                visited[v] = 1;
                s[setNo].insert(v);
                q.push(mp(v, setNo));
            }
        }
    }
    int s0 = s[0].size();
    int s1 = s[1].size();
    int setNo = 0;
    if(s1 > s0)
        setNo = 1;
    cout<<1<<endl;
    for( auto it = s[setNo].begin(); it != s[setNo].end() && k > 0; it++, k--)
        cout<<*it<<" ";
    cout<<endl;
}
int main()
{
	//freopen("A-large.in", "r", stdin);
	//freopen("outout1b.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,k;
    cin>>n>>m>>k;
    vector< vi > graph(n+1);
    int src, dest;
    vector< ii > edges;
    for(int i =0; i < m; i++)
    {
        cin>>src>>dest;
        graph[src].pb(dest);
        graph[dest].pb(src);
        edges.pb(mp(src, dest));
    }
    int nEdges = edges.size();
    if(nEdges == n-1)
    {
        bfs(graph, n,(k+1)/2);
        return 0;
    }
    findCycle(graph, n);
    map< int, ii > mymap;
    int clen = cycle.size();
    int start, end;
    start = 0; end = clen-1;
    map< int, int> pos;
    for(int i = 0; i < clen; i++)
    {
        pos.insert(mp(cycle[i], i));
        if(i == 0)
        {
            mymap.insert(mp(cycle[i], mp(cycle[i+1], cycle[clen-1])));
        }
        else if(i == clen-1)
        {
            mymap.insert(mp(cycle[i], mp(cycle[0], cycle[i-1])));
        }
        else
            mymap.insert(mp(cycle[i], mp(cycle[i+1], cycle[i-1])));
    }
    for(int i =0; i < nEdges; i++)
    {
        int u,v;
        u = edges[i].first;
        v = edges[i].second;
        if(mymap.find(u) != mymap.end() && mymap.find(v) != mymap.end())
        {
            ii neigbor = mymap[u];
            if(neigbor.first != v && neigbor.second != v)
            {
                int flag = 0;
                //int newStart =-1, newEnd = -1;
                int newStart = pos[u], newEnd = pos[v];
                if(newStart > newEnd)
                {
                    newStart = newStart + newEnd;
                    newEnd = newStart - newEnd;
                    newStart = newStart - newEnd;
                }
                for(int idx = start; idx < newStart; idx++)
                    mymap.erase(cycle[idx]);
                for(int idx = newEnd+1; idx <= end; idx++)
                    mymap.erase(cycle[idx]);
                // for(int idx = start; idx <= end; idx++)
                // {
                //     if(cycle[idx] == u || cycle[idx] == v)
                //     {
                //         if(flag == 0)
                //         {
                //             newStart = idx;
                //             flag = 1;
                //         }
                //         else
                //         {
                //             newEnd = idx;
                //             flag = 0;
                //         }
                //     }
                //     else
                //     {
                //         if(flag == 0)
                //             mymap.erase(cycle[idx]);
                //     }
                // }
                start = newStart; 
                end = newEnd;
            }
        }
    }
    clen = end - start + 1;
    if(clen <= k)
    {
        cout<<2<<endl;
        cout<<clen<<endl;
        for(int idx = start; idx <= end; idx++)
            cout<<cycle[idx]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<1<<endl;
        int  cnt = (k+2-1)/2; // ceil(k/2);
        for(int idx = start; idx <= end && cnt >0; idx+=2, cnt--)
        {
            cout<<cycle[idx]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
