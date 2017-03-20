#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<cstring>
#include<iterator>
#include<algorithm>

using namespace std;

int main()
{
	vector<int> hotel[20];
	map<int,int> track;
//	vector<int> :: iterator it;
	int N,B,h,wk,cost[20],temp;
	long a;
	while(scanf("%d%d%d%d",&N,&B,&h,&wk)==4)
	{
		for(int i=0;i<h;i++)
		{
			scanf("%d",&cost[i]);
			for(int j=0;j<wk;j++)
			{
				scanf("%d",&temp);
				hotel[i].push_back(temp);
				track[cost[i]]=i;
			}
		}
		sort(cost,cost+h);
		bool flag=false;

		for(int it=0;it<h;it++)
		{
			temp=track[cost[it]];
			for(int i=0;i<wk;i++)
			{
				if(hotel[temp][i]>=N)
				{
					a=cost[it]*N;
					if(a<=B)
					{
						printf("%ld\n",a);
						flag=true;
						break;
					}
				}
			}
			if(flag) break;
		}
		if(flag==false)
		{
			printf("stay home\n");
		}
//		cost.clear();
		memset(hotel,0,sizeof(hotel));
	}
	return 0;

}

