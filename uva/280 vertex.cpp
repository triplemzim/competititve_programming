#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;
int vertex;
bool color[110];
queue<int> q;
vector<int>v[102];
int bfs(int src)
{
	int top,count=0;
	q.push(src);
	while(!q.empty())
	{
		top=q.front();
		for(int i=0;i<v[top].size();i++)
		{
			if(color[v[top][i]])
			{
				q.push(v[top][i]);
				color[v[top][i]]=false;
				count++;
			}
		}
		q.pop();
	}
	return count;
}


int main()
{

	int src,node,subnode,no_ac,queries;

//	memset(color,true,sizeof(color));
	while(scanf("%d",&vertex)==1 && vertex)
	{

		while(scanf("%d",&node)==1 && node)
		{
			while(scanf("%d",&subnode)==1 && subnode)
			{
				v[node].push_back(subnode);
			}
		}
		scanf("%d",&queries);
		while(queries--)
		{
			for(int i=1;i<=vertex;i++) color[i]=true;

			scanf("%d",&src);
			no_ac=vertex-bfs(src);
			if(no_ac)
			{
				printf("%d",no_ac);
				for(int i=1;i<=vertex;i++)
				{
					if(color[i]) printf(" %d",i);
				}
			}
			else printf("0");
			printf("\n");
		}
		for(int i=1;i<=vertex;i++) v[i].clear();
	}
	return 0;
}
