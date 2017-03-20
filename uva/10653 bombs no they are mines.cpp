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

int r,c;
bool color[1001][1001];
template<typename t> inline t check(t i,t j)
{
	if(i<0 || i>=r || j<0 ||j>=c) return false;
	return true;
}
//bool check(int i,int j)
//{
//
//}

int bfs(int sx,int sy,int dx,int dy)
{
	color[sx][sy]=true;
	PII target=MP(dx,dy);
	if(sx==dx && sy==dy) return 0;
	queue<PII> q;
	PII p;
	q.push(MP(sx,sy));

	int dis[1000][1000]={0};
	while(!q.empty())
	{
		p=q.front();q.pop();

		if(check(p.first,p.second-1))
		{
			if(color[p.first][p.second-1]==false)
			{
				q.push(MP(p.first,p.second-1));
				color[p.first][p.second-1]=true;
				dis[p.first][p.second-1]=dis[p.first][p.second]+1;
				if(MP(p.first,p.second-1)==target) return dis[p.first][p.second-1];
			}
		}
		if(check(p.first,p.second+1))
		{
			if(color[p.first][p.second+1]==false)
			{
				q.push(MP(p.first,p.second+1));
				color[p.first][p.second+1]=true;
				dis[p.first][p.second+1]=dis[p.first][p.second]+1;
				if(MP(p.first,p.second+1)==target) return dis[p.first][p.second+1];
			}
		}
		if(check(p.first-1,p.second))
		{
			if(color[p.first-1][p.second]==false)
			{
				q.push(MP(p.first-1,p.second));
				color[p.first-1][p.second]=true;
				dis[p.first-1][p.second]=dis[p.first][p.second]+1;
				if(MP(p.first-1,p.second)==target) return dis[p.first-1][p.second];
			}
		}
		if(check(p.first+1,p.second))
		{
			if(color[p.first+1][p.second]==false)
			{
				q.push(MP(p.first+1,p.second));
				color[p.first+1][p.second]=true;
				dis[p.first+1][p.second]=dis[p.first][p.second]+1;
				if(MP(p.first+1,p.second)==target) return dis[p.first+1][p.second];
			}
		}
	}
}

int main()
{
	int temp_r,temp_c,temp,bomb;
	while(cin>>r>>c)
	{
		if(!r && !c) break;
		ms(color,false);
		cin>>temp;
		while(temp--)
		{
			cin>>temp_r>>bomb;
			while(bomb--)
			{
				cin>>temp_c;
				color[temp_r][temp_c]=true;
			}
		}
		int sx,sy,ds,dy;
		cin>>sx>>sy>>ds>>dy;
		cout<<bfs(sx,sy,ds,dy)<<endl;
	}

	return 0;
}
















