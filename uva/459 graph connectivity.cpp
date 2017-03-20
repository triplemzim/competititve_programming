#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;
vector<int>v[30];
queue<int >q;
bool color[30];
int total;
int bfs()
{
	int src,count=0;

	for(int i=1;i<=total;i++)
	{
		if(color[i])
		{
			src=i;
			break;
		}
	}
	q.push(src);count++;
	color[src]=false;
	int top;
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
	int cases;
	scanf("%d",&cases);

	char c,a,b;
	while(cases--)
	{
		memset(color,true,sizeof(color));
		scanf(" %c",&c);
		getchar();
		total=(int)c-64;
		while(scanf("%c",&a)==1 && (int)a!=10)
		{
			scanf("%c",&b);
			getchar();
			v[(int)a-64].push_back((int)b-64);
			v[(int)b-64].push_back((int)a-64);
		}

		int sum=0,subg=0;
		while(sum<total)
		{
			sum+=bfs();
			subg++;
		}
		printf("%d\n",subg);
		if(cases) printf("\n");
		for(int i=1;i<=total;i++)
			v[i].clear();
	}
	return 0;

}
