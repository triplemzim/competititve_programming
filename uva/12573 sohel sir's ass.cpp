#include<iostream>
#include<cstdio>
#include<cmath>
#define set(n,pos) (n|(1<<pos))
#define check(n,pos) bool(n & (1<<pos))
#define size 100000000
#define lim 10000

using namespace std;

int status[size>>6+12];

int main()
{
	unsigned i,j;

	for(i=3;i<=lim;i+=2)
	{
		if(check(status[i>>6],((i>>1)&31))==true)
		{
			if(i<100) cout<< i<<endl;
			for(j=i*i;j<=size;j+=i)
			{
				status[j>>6]=set(status[j>>6],((j>>1)&31));
			}
		}
	}
	return 0;
}
