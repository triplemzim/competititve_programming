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
	char ch;
	int t,w,a,b,cases,n,caseno=1;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&n);
		t=w=a=b=0;
		for(int i=0;i<n;i++)
		{
			scanf(" %c",&ch);
			if(ch=='B') b++;
			else if(ch=='W') w++;
			else if(ch=='A') a++;
			else if(ch=='T') t++;
		}
		if(a==n) printf("Case %d: ABANDONED\n",caseno++);
		else if(b+a==n) printf("Case %d: BANGLAWASH\n",caseno++);
		else if(w+a==n) printf("Case %d: WHITEWASH\n",caseno++);

		else if(w==b) printf("Case %d: DRAW %d %d\n",caseno++,w,t);
		else if(b>w) printf("Case %d: BANGLADESH %d - %d\n",caseno++,b,w);
		else printf("Case %d: WWW %d - %d\n",caseno++,w,b);
	}






	return 0;
}








