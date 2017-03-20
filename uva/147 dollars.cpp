#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int coin[]={10000,5000,2000,1000,500,200,100,50,20,10,5};
double n;

unsigned long long dp[12][30009];
unsigned long long coin_change(int i,int cost)
{

	if(i>10)
	{
		if(cost==0) return 1;
		else return 0;
	}
	if(dp[i][cost]!=-1) return dp[i][cost];
	unsigned long long sum=0,sum2=0;

	if(cost-coin[i]>=0)
		sum=coin_change(i,cost-coin[i]);

	sum2=coin_change(i+1,cost);

	return dp[i][cost]=sum+sum2;

}

int main()
{
	memset(dp,-1,sizeof(dp));
	int money;double x;
	while(scanf("%lf",&n)==1 && n!=0)
	{
		money=(int)(n*100 +.5);

		printf("%6.2lf%17llu\n",n,coin_change(0,(money)));

	}
	return 0;
}
