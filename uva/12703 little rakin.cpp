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
#include<set>
#include<iterator>

#define ull unsigned long long
#define iii long long

using namespace std;

#define sets(n,pos) (n|(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))
#define mx 1010
#define lim 32
unsigned prime[mx>>6];
void seive()
{
	unsigned k,i,j;
	prime[2>>6]=sets(prime[2>>6],0);
	for(i=3;i<lim;i+=2)
	{
		if(check(prime[i>>6],((i>>1)&31))==0)
		{
			if(i<100) cout<<i<<" ";
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
	long int fib[45];
	int a=0,b=1;
	fib[0]=1;
	for(int i=1;i<42;i++)
	{
		fib[i]=a+b;
		a=b;
		b=fib[i];
//		cout<<fib[i]<<endl;
	}

	int sq,n,cases;
	long long p[1001]={0},temp;
	bool flag=false;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d%d%d",&n,&a,&b);

		sq=sqrt(a);
		if((a&1)==0)
		{
			while((a&1)==0)
			{
				p[2]++;
				a=a>>1;
			}
			p[2]*=fib[n-2];
		}
		for(int i=3;i<=sq;i+=2)
		{
			if(check(prime[i>>6],((i>>1)&31))==0)
			{
				if(a%i==0)
				{
					while(a%i==0)
					{
						p[i]++;
						a/=i;
					}
					p[i]*=fib[n-2];

				}
			}
		}
		if(a!=1)
		{
			p[a]++;
			p[a]*=fib[n-2];
		}

		sq=sqrt(b);
		if((b&1)==0)
		{
			temp=0;
			while((b&1)==0)
			{
				temp++;
				b=b>>1;
			}
			p[2]=p[2]+ fib[n-1]*temp;
		}
		for(int i=3;i<=sq;i+=2)
		{
			if(check(prime[i>>6],((i>>1)&31))==0)
			{
				temp=0;
				if(b%i==0)
				{
					while(b%i==0)
					{
						temp++;
						b/=i;
					}
					p[i]=p[i]+ temp*fib[n-1];
				}
			}
		}
		if(b!=1)
		{
			p[b]+=fib[n-1];
		}
		for(int i=2;i<1000;i++)
		{
			if(p[i])
			{
				printf("%d %lld\n",i,p[i]);
			}
		}
		memset(p,0,sizeof(p));
		cout<<endl;

	}


	return 0;
}






