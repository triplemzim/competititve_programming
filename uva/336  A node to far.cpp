#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

int main()
{

	vector<long long int> v[110];
	vector<long long int> :: iterator it;
	map<long long int,int> :: iterator mp;
	queue<long long int> q;
	bool visited[110]={false};
	map<long long int,int> track;
	long long count,dist,last,temp1,temp2,src,top,caseno=1,cost[110],parent[110];

	long long index,nc;
	while(scanf("%lld",&nc)==1 && nc)
	{

		index=1;

		for(int i=0;i<nc;i++)
		{

			scanf("%lld%lld",&temp1,&temp2);
			if(track[temp1])
			{

				v[track[temp1]].push_back(temp2);
			}
			else
			{
				track[temp1]=index;
				v[index++].push_back(temp2);
			}
			if(track[temp2])
			{
				v[track[temp2]].push_back(temp1);
			}
			else
			{
				track[temp2]=index;
				v[index++].push_back(temp1);
			}
		}

		while(scanf("%lld%lld",&src,&dist)==2 && (src || dist))
		{
			count=0;
			q.push(src);

			cost[track[src]]=0;
			while(!q.empty())
			{
				top=q.front();

				visited[ track[top] ]=true;
				for(it=v[ track[top] ].begin();it<v[ track[top] ].end(); it++)
				{
					if(visited[ track[*it] ]==false)
					{

						parent[track[*it]]=track[top];
						cost[track[*it]]= cost[ track[top] ]+1;
//						if(cost[track[*it]]>dist) {count++;}
						visited[ track[*it] ]=true;
						q.push(*it);
					}
				}

				q.pop();

			}
			for(mp=track.begin();mp!=track.end();mp++)
			{
				if(cost[(*mp).second]>dist || visited[(*mp).second]==false) count++;
			}
			printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n",caseno++,count,src,dist);
			q.empty();
			memset(parent,0,sizeof(parent));
			memset(cost,0,sizeof(cost));
			memset(visited,false,sizeof(visited));
		}

		track.clear();
		memset(v,0,sizeof(v));

	}
	return 0;
}


