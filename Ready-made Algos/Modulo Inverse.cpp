/*
	MODULO MULTIPLICATIVE INVERSE : 
	FIND MODULO INVERSE OF (A mod P) :  A.(A') = 1(mod P)
	INVERSE IS POSSIBLE ONLY WHEN 'A' AND 'P' ARE CO-PRIME i.e GCD(A,P)=1 
	gcd(a,b)=r =>  ax+by =r 
	here  ax+by=1 => ax = (1-by) => ax(modp)=(1-by)(mod b) => ax= 1(mod b)
	so 'x' = inverse of (a mod b)
	and 'y'= inverse of (b mod a)

	Fermat LITTLE THEOREM: 
	if p = prime , a= natural no. 
	(a^p - a) = k*p = integer multiple of p
	 a^p = a(mod p)

	 if  p doesn't divides a 
	 a^(p-1) -1 = k*p 
	 a^(p-1) = 1(mod p) 
	 a.a^(p-2) = 1(mod p) 
	 so Inverse = a^(p-2)
*/
#include<bits/stdc++.h>
using namespace std;
int eucleid(int a,int b,int *x,int *y)
{
	if(b==0)
	{
		*x=1;*y=0;
		return a;
	}
	int x1,y1;
	int g= eucleid(b,a%b,&x1,&y1);
	/*
		ax+ by =r 
		bx1+ (a%b)y1= r =>  bx1+ (a- (a/b)*b)y1=r
		ay1+ b(x1-(a/b)y1)=r
		so x=y1, y=x1-(a/b)y1;
	*/
	*x=y1;
	*y= x1-(a/b)*y1;
	return g;
}
int inverse(int a,int p)
{
	int x,y;
	int g= eucleid(a,p,&x,&y);
	if(g!=1) 
		return -1;
	else
		return x;// inverse of a mod p
}
long long power(long long a,long long b,long long mode)
{
	if(b==0) return 1;
	if(b==1) return a;
	long long temp= power(a,b/2,mode);
	if(b&1) // odd
		return (((temp*temp)%mode)*a)%mode;
	else 
		return ((temp*temp)%mode);
}
long long inverse2(int a,int p)
{
	// if P is a large prime no. > a
	// then obviously they are Co-Prime and P doesnot divide a so, a^(p-1)=1(mod P) ans inverse  = a^(p-2)
	long long ans = power(a,p-2,p);
	return ans;
}
int main()
{
	int a,p;
	cin>>a>>p;
	cout<<inverse(a,p)<<endl;
	cout<<inverse2(a,p)<<endl;
}
