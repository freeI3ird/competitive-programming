#include<bits/stdc++.h>
using namespace std;
/*
    Time complexity of Naive Approach : O((n-m+1)*m)
    KMP : We reduce it to O(n)
    Concept : We apply the concept of 'Automaton' where we have many no. of states.
              Each time a information is provided and depending on this information, automaton goes from 
              the current state to some other state(uniquely determined by the some internal rules)
    Suppose Pattern ='ABABAC'
      Prefixes(or states of automaton) :          Longest Proper Suffix which is also Prefix     F[]   
   0. \0 (Initial state)                            \0                                           0
   1. A                                             \0                                           0
   2. AB                                            \0                                           0
   3. ABA                                            A                                           1
   4. ABAB                                           AB                                          2
   5. ABABA                                          ABA                                         3
   6. ABABAC (Final State)                           \0                                          0

    Array F[] : Size equal to no. of states 
    F[i] : points to position of 'Longest Proper Suffix which is also Prefix' Or 'Partial Match'

    e.g We are at State (5) :(ABABA) 
    case 1: if next char in text ='C' then (ABABA) can be expanded to state (ABABAC) using'C',which is the next state
    case 2: if next char ='B' then (ABABA) can't be expanded using'B' as(C is needed).So in such case we go the partial
            match using F[5] (F[5]=3) State (3): (ABA) it can be expanded to state (ABAB) so now current state 
            becomes (ABAB) state(4)
    case 3: if next char='D' then (ABABA) can't be expanded using'D', First Best partial Match F[5]=3 (ABA)
            can't be expanded,Second best F[F[5]]=F[3]=1 (A) can't be expanded, Third Best F[F[F[5]]]=F[1]=0 
            0= means Null state, so even Null state can't be expanded using char 'D', 
            In such case Ignore the char'D' and choose the next char.
    
    ***Calculating F[] array***
    failure_function(int patter[],int m,int F[])
    {
        int i,j;
        F[0] represents 'NULL' state
        F[0]=0;
        F[1]=0;
        for(i=2;i<=m;i++)
        {
            j=F[i-1];
            while(1)
            {
                if(patter[j]==pattern[i-1])
                {
                    F[i]=j+1; break;
                }
                if(j==0)
                {
                    F[i]=0; break; 
                }
                j=F[j];
            }
        }
    }

    Now for Searching Pattern in Text 
    - Current state pointer :i=0 initially
    - Text char is input into automaton
    - F[] : Best Partial Match

    KMP(int text[],int pattern,int n,int m)
    {
        int F[m+1]; // including Null state and rest are prefixes of Pattern.
        failure_function(pattern,m,F);
        int i,j;
        i=0; // initial state :NULL
        j=0; // points to next char in text
        while(1)
        {
            if(j==n) // end of text
                break;
            // First we try current state can be expanded using the char at 'j'
            if(text[j]==patter[i])
            {
                // automaton goes to next state
                i++;
                j++;
                if(i==m) // state is final
                    // Pattern Match found
            }
            else if(i>0)
            {
                // we will go to Best Partial Match and see if that can expand using this char
                i= F[i];
            }
            else
            {
                // if i==0 then this means this char can't even expand the null state,so ignore this char
                j++;
            }
        }

    }

*/
#include<bits/stdc++.h>
using namespace std;
void failure_function(string pattern,int f[],int m)
{
    f[0]=0;// 0 corresponds to NUll state
    f[1]=0;
    int i,j;
    for(i=2;i<=m;i++)
    {
        // calculate f[] for the ith state
        j=f[i-1]; // take help of i-1 state
        while(1)
        {
            if(pattern[j]==pattern[i-1])
            {
                f[i]=j+1;break;
            }
            if(j==0)// null state is even not expanded
            {
                f[i]=0;break;
            }
            j=f[j];
        }
    }
}
int solve(string text,string pattern)
{
    int n=text.length();
    int m= pattern.length();
    int i,j;
    i=0; // Initial state i=m final state: current state
    j=0;// input char ,last one= j=n-1; : input
    int f[m+1];// best partial match 
    failure_function(pattern,f,m);
    // for(int k=0;k<=m;k++)
    // {
    //     printf("%d. %d\n",k,f[k]);
    // }
    while(1)
    {
        if(j==n) break;
        // check if char at 'j' can expand the current state
        if(text[j]==pattern[i])
        {
            i++;
            j++;
            if(i==m) // final state
            {
                return 1;
                // Match at Position= j-m= (j-1)-m+1
            }
        }
        else if(i>0)
        {
            // then we check at best partial match
            i= f[i];
        }
        else // j==0 even can't expand it ignoere
        j++;
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string text,pattern;
        cin>>text;
        cin>>pattern;
        if(solve(text,pattern))
            cout<<"found";
        else 
            cout<<"not found";
        cout<<endl;
    }
}
