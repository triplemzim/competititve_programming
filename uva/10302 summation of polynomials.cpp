#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
	unsigned long long sum[50001],i;
	sum[0]=0;

	for(i=1;i<=50000;i++)
	{
		sum[i]=sum[i-1]+(i*i*i);
	}
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		printf("%llu\n",sum[x]);
	}
	return 0;
}
