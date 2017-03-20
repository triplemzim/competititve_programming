#include<iostream>
#include<cstdio>
#include<cmath>
#define iii unsigned long long
using namespace std;

int main()
{
	iii a,b,i,j,temp;
	iii total=0,zero1=0,zero2=0,one1=0,one2=0;
	scanf("%llu%llu",&a,&b);
	iii len1=0,len2=0;
	temp=a;
	while(temp)
	{
		if((temp&1)==0) zero1++;
		else one1++;
		temp=temp>>1;
		len1++;
	}
	temp=b;
	while(temp)
	{
		if((temp&1)==0) zero2++;
		else one2++;
		temp=temp>>1;
		len2++;
	}
	cout<<len1<<" "<<len2;


	return 0;
}
