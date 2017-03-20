#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stdlib.h>

using namespace std;

int main()
{
	int n,d,r,morning[110],evening[110];
	long long overtime,taka;

	while(scanf("%d%d%d",&n,&d,&r)==3 )
	{
		if(n==0 && d==0 && r==0) break;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&morning[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&evening[i]);
		}
		sort(morning,morning+n);
		sort(evening,evening+n);
		overtime=0;
		for(int i=0;i<n;i++)
		{
			if(morning[i]+evening[n-i-1]>d) overtime+=morning[i]+evening[n-i-1]-d;
		}

		taka=overtime*r;
		printf("%lld\n",taka);

	}
	return 0;
}
