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






int r,l,u;
int num[12];

bool color[10000];
iii dis[10000];
iii bfs()
{
	if(l==u) return 0;
	ms(color,false);

	int top,cur;
	queue<int>q;
	q.push(l);

	dis[l]=0;
	color[l]=true;
	while(!q.empty())
	{
		top=q.front();q.pop();
		for(int i=0;i<r;i++)
		{
			cur=(top+num[i])%10000;
			if(color[cur]==false)
			{
				dis[cur]=dis[top]+1;
				if(cur==u) return dis[cur];

				color[cur]=true;
				q.push(cur);
			}
		}
	}
	return -1;
}



int main()
{
	int caseno=1;
	while(scanf("%d%d%d",&l,&u,&r)==3)
	{
		if(!l && !u && !r) break;
		for(int i=0;i<r;i++)
		{
			cin>>num[i];
		}

		iii k=bfs();
		if(k>=0)	printf("Case %d: %lld\n",caseno++,k);
		else printf("Case %d: Permanently Locked\n",caseno++);
	}

	return 0;
}





