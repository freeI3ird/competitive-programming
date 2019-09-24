/*
	if gcd(a,b) = r  ==  gcd(b,a%b)
	then  ax + by = r  ....(1)
	also  bx1 + (a%b)y1 =r 
	      bx1 + (a - (a/b)*b)y1 =r  
	      ay1 + b(x1 - (a/b)*y1) = r ...(2)
	comparing equation (1) and (2):
	x= y1 
	y = x1 - (a/b)*y1
	
	Now when gcd(a,b)=1 
	then x = modulo inverse of a(mod b)
		y= modulo inverse of b(mod a)
*/


#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b,int *x,int *y)
{
	if(b==0)
	{
		*x=1;
		*y=0;
		return a;
	}
	int x1,y1;
	int g=gcd(b,a%b,&x1,&y1); // x1 and y1 are used for back substitution

	*x= y1;
	*y= x1 - (a/b)*y1;
	return g;
}
int main()
{
	int a,b,x,y;
	cin>>a>>b;
	int g= gcd(a,b,&x,&y);
	cout<<"ax+by=gcd(a,b)\n";
	printf("%d(%d)+%d(%d)=%d\n",a,x,b,y,g);
}
