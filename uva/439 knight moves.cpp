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


bool valid(int a,int b)
{
	if(a>8 ||a<1 ||b>8 || b<1) return false;
	return true;
}
int dis[9][9];
int bfs(int x,int y,int a,int b)
{
	ms(dis,0);
	bool color[9][9]={false};

	queue<int>q;
	int top;
	q.push(x);q.push(y);
	color[x][y]=true;

	while(!q.empty())
	{
		x=q.front();q.pop();
		y=q.front();q.pop();

		if(x==a && y==b) return dis[x][y];
		int i,j;
		i=x+1;j=y+2;
		if(valid(i,j))
		{
			q.push(i);
			q.push(j);
			color[i][j]=true;
			dis[i][j]=dis[x][y]+1;
		}
		i=x-1;j=y+2;
		if(valid(i,j) && color[i][j]==false)
		{
			color[i][j]=true;
			q.push(i);
			q.push(j);
			dis[i][j]=dis[x][y]+1;
		}
		i=x-2;j=y+1;
		if(valid(i,j) && color[i][j]==false)
		{
			q.push(i);
			q.push(j);
			color[i][j]=true;
			dis[i][j]=dis[x][y]+1;
		}
		i=x-2;j=y-1;
		if(valid(i,j) && color[i][j]==false)
		{
			q.push(i);
			color[i][j]=true;
			q.push(j);
			dis[i][j]=dis[x][y]+1;
		}
		i=x+2;j=y+1;
		if(valid(i,j) && color[i][j]==false)
		{
			q.push(i);
			color[i][j]=true;
			q.push(j);
			dis[i][j]=dis[x][y]+1;
		}
		i=x+2;j=y-1;
		if(valid(i,j) && color[i][j]==false)
		{
			q.push(i);
			color[i][j]=true;
			q.push(j);
			dis[i][j]=dis[x][y]+1;
		}
		i=x-1;j=y-2;
		if(valid(i,j) && color[i][j]==false)
		{
			q.push(i);
			color[i][j]=true;
			q.push(j);
			dis[i][j]=dis[x][y]+1;
		}
		i=x+1;j=y-2;
		if(valid(i,j) && color[i][j]==false)
		{
			q.push(i);
			q.push(j);
			color[i][j]=true;
			dis[i][j]=dis[x][y]+1;
		}
	}

}


int main()
{
	char source[3],target[3];
	int x,y,a,b,c,di;
	while(scanf("%s%s",source,target)==2)
	{
		x=source[0]-96;
		y=source[1]-48;
		a=target[0]-96;
		b=target[1]-48;

//		cout<<x<<' '<<y<<' '<<a<<' '<<b<<endl;

		di=bfs(x,y,a,b);

		printf("To get from %s to %s takes %d knight moves.\n",source,target,di);
	}



	return 0;
}














