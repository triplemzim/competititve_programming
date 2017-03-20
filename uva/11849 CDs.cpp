#include<iostream>
#include<cstdio>
#include<map>

using namespace std;


int main()
{
	long n,m,count;
	long long c;
	map<long long,bool> mp;


	while(scanf("%ld%ld",&n,&m)==2)
	{
		if(n==0 && m==0) break;
		count=0;
		while(n--)
		{
			scanf("%lld",&c);
			mp[c]=true;
		}
		while(m--)
		{
			scanf("%lld",&c);
			if(mp[c]==true) count++;
		}
		printf("%ld\n",count);
		mp.clear();
	}
	return 0;
}
