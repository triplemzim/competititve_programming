#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define sets(n,pos) (n|(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))
#define mx 10000000
#define lim 3500
unsigned prime[mx>>6];
void seive()
{
	unsigned k,i,j;
	prime[2>>6]=sets(prime[2>>6],0);
	for(i=3;i<lim;i+=2)
	{
		if(check(prime[i>>6],((i>>1)&31))==0)
		{
//			if(i<100) cout<<i<<" ";
			k=i<<1;
			for(j=i*i;j<=mx;j+=k)
			{
				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
			}
		}
	}
	return;
}

int main()
{

	seive();

	long long sq,num,factors[10000];
	unsigned i,j;
	int index,temp;
	while(scanf("%lld",&num)==1)
	{
		if(num<0) break;


		for(i=0;num>1 && i<mx;i++)
		{
			if(check(prime[i>>6],((i>>1)&31))==0)
			{
				while(!(num%i))
				{
					printf("    %lld\n",i);
					num/=i;
				}
			}
		}
		if(num>1) printf("    %lld\n",num);
		printf("\n");
	}









	return 0;
}





