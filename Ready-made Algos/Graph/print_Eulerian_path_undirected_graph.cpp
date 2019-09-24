/*
    UNDIRECTED GRAPH
    EULERIAN :- ALL NON-ZERO DEGREE NODES MUST BE CONNECTED  
                PATH : Exactly 2 odd vertices and REST 'EVEN' vertices
                Circuit: ALL 'EVEN' VERTICES
    ALGO : DON'T BURN THE BRIDGES.
    - start from the odd vertex(if no odd then start from '0'/'1' vertex).
    - try to avoid bridges as along as possible.
    - if only one unused edge is there follow that edge.
    - remove the edge from graph one it is 'used'.

    DIRECTED GRAPH
    EULERIAN :- ALL NON-ZERO DEGREE NODES SHOULD BELONG TO SINGLE STRONGLY CONNECTED COMPONENT
                EACH NODE HAS 'EQUAL' 'IN' AND 'OUT' DEGREE.

*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000007
#define mode 1000000007
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector< ii >
#define vvi vector< vi >
#define vvii vector< vii >
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(i=a;i<=b;i++)
#define tr(container,it) \
	for((typeof(container.begin()) it= container.begin();it!=container.end();it++))
vvi graph(MAX);
set< ii > bridge;
int low[MAX],disc[MAX],par[MAX];
int visited[MAX],ttime=0;
void dfs(int u)
{
    visited[u]=1;
    int len=graph[u].size();
    for(int i=0;i<len;i++)
    {
        int v= graph[u][i];
        if(visited[v]==0)
            dfs(v);
    }
}
bool isEulerian(int n,int m)
{
    // check that all non-zero degree vertices are connected.
    for(int i=0;i<n;i++)
        visited[i]=0;
    int start=0,i;
    for(i=0;i<n;i++)
    {
        if(graph[i].size())
            break;
    } 
    if(i==n)
        return false;
    start=i;
    dfs(start);
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0&&graph[i].size()!=0)
            return false;
    }
    // to check Eulerian we have to count the no. of odd vertices
    int odd=0;
    for(int i=0;i<n;i++)
    {
        int degree= graph[i].size();
        if(degree&1)// odd
            odd++;
    }
    if(odd>2) return false;
    return true;
}
void dfs2(int u)
{
    visited[u]=1;
    low[u]=disc[u]=++ttime;
    int len=graph[u].size();
    for(int i=0;i<len;i++)
    {
        int v=graph[u][i];
        if(visited[v]==0)
        {
            par[v]=u;
            dfs2(v);
            if(low[v]>disc[u]) // not connected to some ancestor so it's a bridge
            {
                if(bridge.find(ii(u,v))==bridge.end()&&bridge.find(ii(v,u))==bridge.end())
                    bridge.insert(ii(u,v));
            }
            low[u]= min(low[u],low[v]);
        }
        else if(par[u]!=v)
            low[u]=min(low[u],low[v]);
    }
}
void findBridge(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        par[i]=-1;
    }
    dfs2(0);
    // all bridges are inside set 'bridge'
}
void removeEdge(int u,int v)
{
    int len;
    len= graph[u].size();
    for(int i=0;i<len;i++)
    {
        if(graph[u][i]==v)
        {
            graph[u][i]=-1;break;
        }
    }
    len=graph[v].size();
    for(int i=0;i<len;i++)
    {
        if(graph[v][i]==u)
        {
            graph[v][i]=-1;break;
        }
    }
}
bool isValid(int u,int v)
{
    // Valid Two case : 1) if only 1 adjacent vertex
    int cnt=0;
    int len=graph[u].size();
    for(int i=0;i<len;i++)
        if(graph[u][i]!=-1)
            cnt++;
    if(cnt==1) return true;

    // case 2): Not a bridge node
    if(bridge.find(ii(u,v))!=bridge.end()||bridge.find(ii(v,u))!=bridge.end())
    {
        return false;
    }
    return true;
}
void traverseEulerian(int u)
{
    int len= graph[u].size();
    for(int i=0;i<len;i++)
    {
        int v= graph[u][i];
        if(v!=-1&&isValid(u,v))
        {
            cout<<u<<"-"<<v<<"-";
            removeEdge(u,v);
            traverseEulerian(v);
        }
    }
    /*
    if(len==1&&graph[u][0]!=-1) // only one edge
    {
        cout<<u<<"-"<<graph[u][0]<<"-";
        removeEdge(u,graph[u][0]);
        traverseEulerian(graph[u][0]);
        return ;
    }
    //else there are many edges so traverse non-bridge first
    // there is atmost 1 bridge with one vertex.
    int idx=-1;
    for(int i=0;i<len;i++)
    {
        int v= graph[u][i];
        if(v==-1) continue; // it means it is removed
        if(bridge.find(ii(u,v))!=bridge.end()||bridge.find(ii(v,u))!=bridge.end())
        {
            idx=i;
        }
        else
        {
            cout<<u<<"-"<<v<<"-";
            removeEdge(u,v);
            traverseEulerian(v);
        }
    }
    if(idx==-1) return ;
    cout<<u<<"-"<<graph[u][idx]<<"-";
    removeEdge(u,graph[u][idx]);
    traverseEulerian(graph[u][idx]);
    */
}
void printEulerian(int n,int m)
{
    // FIRST CHECK THAT IF EULERIAN CIRCUIT OR PATH EXIST OR NOT 
    if(!isEulerian(n,m))
    {
        cout<<"Graph is not Eulerian\n";
        return ;
    }
    // Graph is Eulerian,Now we need to find the starting vertex which is odd vertex if exist
    int start=0,i;
    for(i=0;i<n;i++)
    {
        if(graph[i].size()&1)
            break;
    }
    if(i!=n)
        start=i;
    // before actually starting the Traversal, we need to identify which edges are 'BRIDGES';
    findBridge(n,m);
    //Now traverse for Eulerian and Remember Don't burn the Bridges
    traverseEulerian(start);
}
int main()
{
    int n,m;
    cout<<"Enter the #vertices and #edges:";
    cin>>n>>m;
    cout<<"Enter the edges:\n";
    int u,v;
    for(int i=1;i<=m;i++)
    {
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    printEulerian(n,m);
    return 0;
}
