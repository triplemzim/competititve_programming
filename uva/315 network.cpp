#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<cstring>

using namespace std;
vector<int>v[102];
queue<int>q;
int parent[101];
bool color[102],critic[102];

int bfs(int src,int bad)
{

	int top,count=0;
	color[bad]=false;
	q.push(src);
	color[src]=false;
	while(!q.empty())
	{
		top=q.front();
		for(int i=0;i<v[top].size();i++)
		{
			if(color[v[top][i]] )
			{
				q.push(v[top][i]);
				color[v[top][i]]=false;
				count++;
			}
		}
		q.pop();
	}
//	cout<<count<<"for "<<bad<<endl;
	return count;
}
int main()
{
	char c;
	memset(color,true,sizeof(color));
	int node,src,con;
	while(scanf("%d",&node)==1 && node)
	{

		while(scanf("%d%c",&src,&c)==2 && src!=0)
		{

			while((int)c!=10)
			{
				scanf("%d%c",&con,&c);
				v[src].push_back(con);
				v[con].push_back(src);

			}
		}
		con=0;
		if(bfs(2,1)!=node-2) con++;
		for(int i=2;i<=node;i++)
		{
			for(int j=1;j<=node;j++) color[j]=true;
			if(bfs(1,i)!=node-2) con++;
		}
		cout<<con<<endl;
		for(int i=1;i<=node;i++)
		{
			color[i]=true;
			v[i].clear();
		}

	}
	return 0;
}
