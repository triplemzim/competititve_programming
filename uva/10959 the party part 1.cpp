#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

using namespace std;

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999

bool color[1001][1001];

vector<int> v[1001];
int dis[1001];
int n;
void bfs()
{
	int top=0;
	queue<int>q;
	q.push(0);
	ms(dis,0);
	bool visited[n+2];
	ms(visited,false);
	visited[0]=true;
	while(!q.empty())
	{
		top=q.front();q.pop();
		for(int i=0;i<v[top].size();i++)
		{
			int x=v[top][i];
			if(visited[x]==false)
			{
				q.push(x);
				visited[x]=true;
				dis[x]=dis[top]+1;
			}
		}
	}
	return;
}

int main()
{
	int cases,d,x,y;
	cin>>cases;
	while(cases--)
	{
		ms(color,false);
		cin>>n>>d;
		while(d--)
		{
			cin>>x>>y;
			if(color[x][y]==false)
			{
				v[x].pb(y);
				v[y].pb(x);
				color[x][y]=true;
				color[y][x]=true;
			}
		}
		bfs();
		for(int i=1;i<n;i++)
		{
			cout<<dis[i]<<endl;
		}
		if(cases!=0) cout<<endl;
		for(int i=0;i<n;i++) v[i].clear();
	}



	return 0;
}
