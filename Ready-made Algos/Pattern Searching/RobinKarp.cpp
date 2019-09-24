#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll mod;
#define B 256
ll int_mod(ll a,ll b)
{
	return ((a%b+b)%b);
}
ll power(ll a,ll b)
{
	if(b==0) return 1;
	if(b==1) return a;
	ll temp= power(a,b/2);
	if(b&1) 
		return int_mod((int_mod(temp*temp,mod)*a),mod);
	else 
		return int_mod(temp*temp,mod);
}
void robinKarp(string text,string pattern)
{
	int n,m;
	n=text.length();
	m=pattern.length();
	ll hp=0;// hash value for the pattern hp= s[0]*B^m-1 +s[1]*B^m-2 +...+ s[m-2]*B+ s[m-1]*1
	ll ht=0;// hash value for the substring of size 'm' in text
	ll E=1;// E= B^m-1
	for(int i=0;i<m;i++)
	{
		if(i!=m-1)
			E= int_mod(E*B,mod);
		hp = int_mod(int_mod(hp*B,mod)+pattern[i],mod);// hp = (hp*B+pattern[i])
		ht = int_mod(int_mod(ht*B,mod)+text[i],mod);
	}
	for(int i=0;i<=n-m;i++)
	{
		if(hp==ht) // hash values matched,so either check char by char or check the second hash value to become double sure
		{
			// match at position i
			printf("%d\n",i);
		}
		// Now calculate Hash value for next substring in the text
		if(i==n-m) continue;
		ht= int_mod(ht-int_mod(text[i]*E,mod),mod);//ht = (ht- s[i]*E)*B+s[i+m];
		ht= int_mod(ht*B,mod);
		ht= int_mod(ht+text[i+m],mod);
	}
}
int main()
{
	int n;
	mod=1000000007;
	while(cin>>n)
	{
		string pattern,text;
		cin>>pattern;
		cin>>text;
		robinKarp(text,pattern);
		printf("\n");
	}
}
