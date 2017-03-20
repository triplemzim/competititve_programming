#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

using namespace std;

int main()
{
	int cases,n,count,hand,l,m,temp,temp2,top;
	vector<int>v[10010];
	bool color[10010];
	queue<int>q;
	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%d%d%d",&n,&m,&l);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&temp,&temp2);
			v[temp].push_back(temp2);
		}
		count=0;
		memset(color,true,sizeof(color));

		for(int i=0;i<l;i++)
		{
			scanf("%d",&temp);

			if(color[temp]==true)
			{
				count++;
				q.push(temp);
			}
			color[temp]=false;

		}

		while(!q.empty())
		{
			top=q.front();
			for(int i=0;i<v[top].size();i++)
			{
				if(color[v[top][i]]==true)
				{
					q.push(v[top][i]);
					color[v[top][i]]=false;
					count++;
				}
			}
			q.pop();
		}

		printf("%d\n",count);
		for(int i=1;i<=n;i++) v[i].clear();
	}
	return 0;
}

