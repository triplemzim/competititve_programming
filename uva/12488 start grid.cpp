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



int main()
{
	int n,dif,total;
	int pos[30],pos2[30];
	while(scanf("%d",&n)==1)
	{

		total=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pos[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&pos2[i]);
//			if(dif-pos[i]>0) total+=(dif-pos[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(pos[j]>pos[i] && pos2[j]<pos2[i]) total++;
			}
		}
		printf("%d\n",total);
	}





	return 0;
}


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



