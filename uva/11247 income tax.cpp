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
	double m,x,y,cur;
	while(scanf("%lf%lf",&m,&x)==2)
	{
		if(!m && !x) break;
		cur=0;
		y=m-1;
		if(x==0 || x==100 || m==1)
		{
			printf("Not found\n");
		}
		else
		{
			while(cur<m-1)
			{
				y++;
				cur=y-(y*x)/100;

			}
			if(y-1>=m) printf("%.0lf\n",y-1);
			else printf("Not found\n");
		}
	}




	return 0;
}






