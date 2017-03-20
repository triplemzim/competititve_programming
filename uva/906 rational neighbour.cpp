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
	double last,cur,a,b,nu,deno,m,dif,n,con;
	while(scanf("%lf%lf%lf",&a,&b,&n)!=EOF)
	{

		con=a/b;
		deno=nu=last=1;
		dif=last-con;

		while(dif<=0 || dif-n>.000000000000001)
		{
			if(last>con) deno++;
			else nu++;
			last=nu/deno;
			dif=last-con;



		}
		printf("%.0lf %.0lf\n",nu,deno);
	}







	return 0;
}






