#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<iterator>
#include<map>
#include<cstring>

using namespace std;


int main()
{
	int src,caseno=1,index;
	long long u,e;
	bool color[10000];
	queue <int> q;
	map<long long,int> m;
	map<int,int>parent;
	vector<int> v[10000];
	while(scanf("%lld%lld",&u,&e)==2)
	{
		if(u<0 && e<0) break;
		index=1;
		while(u && e)
		{
			if(m[u])
			{
				v[m[u]].push_back(e);
			}
			else
			{
				m[u]=index;
				v[index++].push_back(e);
			}
			if(m[e])
			{
				parent[m[e]]=m[u];
			}
			else
			{
				m[e]=index;
				parent[index++]=m[u];
			}
//			cout<<m[u]<<">>"<<m[e]<<endl;
			scanf("%lld%lld",&u,&e);
		}

		map<long long int,int>::iterator it;
		src=0;
		for(it=m.begin();it!=m.end();it++)
			if(parent[(*it).second]==0)
			{
				src=(*it).second;
				break;
			}
		bool tree=true;
		if(!src && index!=1) tree=false;
		memset(color,false,sizeof(color));
		q.push(src);
		int top,cur;

		color[src]=true;

		while(!q.empty())
		{
			top=q.front();
			for(int i=0;i<v[top].size();i++)
			{
				cur=m[v[top][i]];
				if(color[cur])
				{
//					cout<<cur<<"Ekhane"<<endl;
					tree=false;
					break;
				}
				else
				{
//					cout<<cur<<" , "<<"||";
					color[cur]=true;
					q.push(cur);
				}
			}
			q.pop();
		}

		for(it=m.begin();it!=m.end();it++)
			if(!color[(*it).second])
			{
//				cout<<(*it).second<<endl;
				tree=false;
				break;
			}
		if(tree)
		{
			printf("Case %d is a tree.\n",caseno++);
		}
		else printf("Case %d is not a tree.\n",caseno++);
		m.clear();
		memset(v,0,sizeof(v));
		parent.clear();
		q.empty();


	}
	return 0;
}
