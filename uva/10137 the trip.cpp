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

	int cost[1010],avg,total;
	double excess;
	int n;
	double temp;
	while(scanf("%d",&n)==1 && n!=0)
	{
		total=excess=0.00;
		for(int i=0;i<n;i++)
		{
			scanf("%lf",&temp);
			temp*=100;
			total+=temp;
			cost[i]=temp;
		}
		sort(cost,cost+n);
		avg=total/n;
		avg--;
		for(int i=1;cost[i]<avg;i++)
		{
			excess+=(avg-cost[i]);
		}
//		cout<<excess<<endl;
		excess/=100;
		printf("$%.2lf\n",excess);
	}






	return 0;
}






