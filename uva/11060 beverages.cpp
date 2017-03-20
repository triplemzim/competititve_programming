#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
#include<map>

using namespace std;
int indegree[110];
vector<int> v[110];
bool color[110];
int main()
{
	int n,m,caseno=1;
	queue<int> q;
	map<string,int> mp;
	map<int,string> track;
	int index;
	char c[100],d[100];
	bool flag;

	memset(indegree,0,sizeof(indegree));
	while(scanf("%d",&n)==1)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%s",c);
			mp[c]=i;
//			cout<<i;
			track[i]=c;
		}
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%s %s",c,d);
			v[mp[c]].push_back(mp[d]);
			cout<<mp[c]<<" "<<mp[d]<<endl;
			indegree[mp[d]]++;
		}
//		cout<<indegree[3]<<indegree[2]<<indegree[1]<<endl;
		printf("Case #%d: Dilbert should drink beverages in this order: ",caseno++);
		flag=false;
		int top,count=0;
		memset(color,true,sizeof(color));
		while(count<n)
		{
			for(int i=1;i<=n;i++)
			{
				if(color[i]==true)
				{
					if(indegree[i]==0)
					{
						color[i]=false;
						q.push(i);
						count++;
						if(flag) printf(" ");
						else flag=true;

						cout<<track[i];
					}
				}
			}
			while(!q.empty())
			{
				top=q.front();
				for(int i=0;i<v[top].size();i++)
				{
					indegree[v[top][i]]--;
				}
				q.pop();
			}
		}
		printf(".\n\n");
		for(int i=1;i<=n;i++)	v[i].clear();
		mp.clear();
		track.clear();
	}
	return 0;
}

