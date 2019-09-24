#include <stdio.h>
#include <algorithm>
#include<bits/stdc++.h>
using namespace std;
static const int maxn = (1 << 17); // smallest power of 2 not less than 10^5

int coords[maxn];
int array[maxn];
int arrayp[maxn];

typedef struct node {
    node *l, *r;
    int sum;
} *Node;

node buffer[maxn * 20]; // XXX: Perhaps 20 is not a correct value
Node ver[maxn];

/*Node allocate(int number = 1)
{
    static Node freep = buffer;
    if (freep + number > buffer + maxn * 1000)
        for (;;) ;
    Node res = freep;
    freep += number;
    return res;
}

Node update(Node v, int vl, int vr, int x)
{
    if (vl == x && vr == x + 1) {
        Node u = allocate();
        *u = *v;
        u->sum = 1;
        return u;
    }
    Node u = allocate();
    *u = *v;
    int m = (vl + vr) / 2;
    if (x < m)
        u->l = update(u->l, vl, m, x);
    else
        u->r = update(u->r, m, vr, x);
    ++u->sum;
    return u;
}


std::pair<int, bool> find_nth(Node u, Node v, int vl, int vr, int k)
{
    int sum = v->sum - u->sum;
    if (vr - vl == 1) {
        if (k == sum)
            return std::make_pair(vl, false);
    }
    if (sum < k)
        return std::make_pair(vr, true);
    if (vr - vl == 1)
        return std::make_pair(vl, false);
    auto p = find_nth(u->l, v->l, vl, (vl + vr) / 2, k);
    if (!p.second)
        return p;
    return find_nth(u->r, v->r, (vl + vr) / 2, vr, k - v->l->sum + u->l->sum);
}*/

int main()
{
    int n;
    //FILE *in = fopen("input.txt", "r");
    //FILE *out = fopen("output.txt", "w");
    //fscanf(in, "%d", &n);
    scanf("%d",&n);
	for (int i = 0; i < n; ++i)
        scanf("%d",&array[i]);//fscanf(in, "%d", &array[i]);
    std::copy(array, array + n, coords);
    std::sort(coords, coords + n);
    for (int i = 0; i < n; ++i)
        array[i] = std::lower_bound(coords, coords + n, array[i]) - coords;
    for (int  i = 0; i < n; ++i)
        arrayp[array[i]] = i;
    cout<<"Coords[] =";
    for(int i=0;i<n;i++)
        cout<<coords[i]<<" ";
    cout<<endl;
    cout<<"array[]= ";
    for(int i=0;i<n;i++)
        cout<<array[i]<<" ";
    cout<<endl;
    cout<<"arrayp[]= ";
    for(int i=0;i<n;i++)
        cout<<arrayp[i]<<" ";
    /*allocate(2 * maxn - 1);
    for (int i = maxn - 2; i >= 0; --i)  {
        buffer[i].l = &buffer[2 * i + 1];
        buffer[i].r = &buffer[2 * i + 2];
    }
    ver[0] = buffer;
    for (int i = 0; i < n; ++i)
        ver[i + 1] = update(ver[i], 0, maxn, array[i]);
    int m;
    fscanf(in, "%d", &m);
    for (int i = 0; i < m; ++i) {
        int l, r, k;
        fscanf(in, "%d%d%d", &l, &r, &k);
        --l;
        fprintf(out, "%d\n", arrayp[find_nth(ver[l], ver[r], 0, maxn, k).first] - l + 1);
    }*/
    return 0;
}
