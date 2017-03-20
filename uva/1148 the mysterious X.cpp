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

vector<int> v[5000001];
bool color[5000001];
int n;
int dis[5000001];
int bfs(int src,int target)
{
	for(int i=0;i<=n;i++){dis[i]=0; color[i]=false;}
	queue<int>q;
	q.push(src);
	color[src]=true;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(int i=0;i<v[top].size();i++)
		{
			int s=v[top][i];
			if(color[s]==false)
			{
				if(s==target) return dis[top];
				color[s]=true;
				q.push(s);
				dis[s]=dis[top]+1;
			}
		}
	}
	return 0;
}


int main()
{
	int cases;
	int x,y,temp;
	cin>>cases;

	while(cases--)
	{
		cin>>n;
		repi(i,0,n)
		{
			cin>>x>>y;
			while(y--)
			{
				cin>>temp;
				v[x].pb(temp);
				v[temp].pb(x);
			}

		}
		cin>>x>>y;
//		cout<<'j';
		cout<<x<<' '<<y<<' '<<bfs(x,y)<<endl;
		repi(i,0,n+1) v[i].clear();

		if(cases!=0) cout<<endl;
	}





	return 0;
}



