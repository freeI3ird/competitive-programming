#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        if(k%n == 0)
            cout<<"0"<<endl;
        else 
            cout<<"2"<<endl;
        int grid[n][n];
        memset(grid, 0, sizeof(grid));
        // int p = 0;
        // while(k > 0)
        // {
        //     int row,c1,r2,c2;
        //     row = 0; c1 = p; c2 = 0;
        //     for(int i = 0; i < n; i++)
        //     {
        //         if(k == 0) break;
        //         if( c1 < n)
        //             grid[row++][c1++] = 1;
        //         else 
        //             grid[row++][c2++] = 1;
        //         k--;
        //     }
        //     if(k == 0) break;
        //     p++;
        // }
        int p = 0, q = 0;
        while(k > 0)
        {
            k--; 
            grid[p][q] = 1;
            p++; q++;
            q = q%n;
            if(p == n)
            {
                p = 0;
                q = (q+1)%n;
            }
        }
        for(int i =0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
                cout<<grid[i][j];
            cout<<endl;
        }
    }
}