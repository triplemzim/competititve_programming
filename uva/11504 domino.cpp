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
	vector<int>v[100010];
	bool color[100010]={false};
	queue<int>q;
	bool flag;
	scanf("%d",&cases);
//	memset(color,f,sizeof(color));
	while(cases--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&temp,&temp2);
			v[temp].push_back(temp2);
			v[temp2].push_back(temp2);
		}
		count=0;
		flag=true;
		while(flag)
		{
			flag=false;
			for(int i=1;i<=n;i++)
			{

				if(color[i]==false)
				{
					q.push(i);
//					cout<<i<<endl;
					color[i]=true;
					count++;
					flag=true;
					break;
				}
			}
			while(!q.empty())
			{
				top=q.front();
				for(int i=0;i<v[top].size();i++)
				{
					if(color[v[top][i]]==false)
					{
						q.push(v[top][i]);
						color[v[top][i]]=true;
					}
				}
				q.pop();
			}
		}
		printf("%d\n",count);
		for(int i=1;i<=n;i++) v[i].clear();
		for(int i=0;i<=n;i++) color[i]=false;
	}
	return 0;
}


