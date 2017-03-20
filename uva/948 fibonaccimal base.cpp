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

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long

using namespace std;

//#define sets(n,pos) (n|(1<<pos))
//#define check(n,pos) (bool(n&(1<<pos)))
//#define mx 100000000
//#define lim 10000
//unsigned prime[mx>>6];
//void seive()
//{
//	unsigned k,i,j;
//	prime[2>>6]=sets(prime[2>>6],0);
//	for(i=3;i<lim;i+=2)
//	{
//		if(check(prime[i>>6],((i>>1)&31))==0)
//		{
//			if(i<100) cout<<i<<" ";
//			k=i<<1;
//			for(j=i*i;j<=mx;j+=k)
//			{
//				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
//			}
//		}
//	}
//	return;
//}

int main()
{
	iii fib[1000],temp,a,b;
	fib[0]=0;fib[1]=1;
	for(int i=2;fib[i-1]<=100000000;i++)
	{
		fib[i]=fib[i-1]+fib[i-2];
//		cout<<i<<endl;
	}
	iii n;
	int cases;
	bool flag;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%lld",&n);
		flag=false;
		printf("%lld = ",n);
		for(int i=39;i>1;i--)
		{
			if(fib[i]<=n)
			{
				flag=true;
				cout<<1;
//				cout<<"-"<<fib[i]<<"- ";
				n-=fib[i];
			}
			else if(flag) cout<<0;
		}
		cout<<" (fib)\n";
	}


	return 0;
}






