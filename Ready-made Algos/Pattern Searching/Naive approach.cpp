/*
Author    : MANISH RATHI
Institute : NIT KURUKSHETRA

*******************************
Don't Stop when you are tired  *
Stop When you are Done         *
******************************* 
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
#define read(x) scanf("%d",&x)
#define print(x) printf("%d\n",x)
#define read2(x,y) scanf("%d%d",&x,&y);
#define print2(x,y) printf("%d %d\n",x,y);
#define read_s(x) scanf("%s",x);
#define print_s(x) printf("%s",x);
#define rep(i,a,b) for(i=a;i<=b;i++)
#define tr(container,it) \
	for((typeof(container.begin()) it= container.begin();it!=container.end();it++))

//Time : O(m*(n-m+1))
void search(char text[],char pattern[],int n,int m)
{
    cout<<"Occurences of pattern :\n";
    int i,j;
    for(i=0;i<=n-m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(text[i+j]!=pattern[j])
                break;
        }
        if(j==m)// pattern found
        {
            cout<<"Position :"<<i<<endl;
        }
    }
}
int main()
{
	char text[MAX],pattern[MAX];
    int n,m;
    // cout<<"Enter the length of TEXT and Pattern:";
    // cin>>n>>m;
    cout<<"Enter the Pattern:\n";
    scanf("%s",pattern);
    cout<<"Enter the Text:\n";
    scanf("%s",text);
    n= strlen(text);
    m= strlen(pattern);
    search(text,pattern,n,m);
    return 0;
}

