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
	int n,count[12]={0};
	char grid[20][20];
	scanf("%d",&n);
	bool flag=false;
	for(int i=0;i<4;i++) scanf("%s",grid[i]);

	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(grid[i][j]=='.') continue;
			else
			{
				count[(int)grid[i][j]-48]++;
				if(count[(int)grid[i][j]-48]>(2*n) )
				{
					flag=true;
				}
			}
		}
	}
	if(flag) printf("NO\n");
	else printf("YES\n");





	return 0;
}






