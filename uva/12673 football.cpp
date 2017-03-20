#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;


int main()
{
	long long n,g,point,index;
	int dis[100009],dci,khaici;


	while(scanf("%lld%lld",&n,&g)!=EOF)
	{
		point=0;
		index=0;
		while(n--)
		{
			scanf("%d%d",&dci,&khaici);
			if(dci>khaici) point+=3;
			else if(dci==khaici)
			{
				if(g) {g--;point+=3;}
				else point++;
			}
			else
			{
				dis[index++]=khaici-dci;
			}
		}
		sort(dis,dis+index);
		for(int i=0;i<index;i++)
		{
			if(g>dis[i])
			{
				g=g-dis[i]-1;
				point+=3;
			}
			else if(g==dis[i])
			{
				g=0;
				point++;
			}
			else break;
		}
		printf("%lld\n",point);
	}
	return 0;
}
