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

map<string,int> m;
vector<int> v[40];
int mm,n,k;

bool color[40];
int bfs(int src,int target)
{
	if(src==target) return 0;
	ms(color,false);
//	int parent[40]={0};
	int dis[40]={0};
//	parent[src]=src;
	color[src]=true;
	queue<int> q;
	q.push(src);
	int leg=1;
	while(!q.empty())
	{
		int top=q.front();q.pop();
//		if(top==target) return leg;
//		if(parent[top]!=src)
//		{
//			src=top;
//			leg++;
//		}

		for(int i=0;i<v[top].size();i++)
		{
			if(color[v[top][i]]==false)
			{

				q.push(v[top][i]);
				color[v[top][i]]=true;

				dis[v[top][i]]=dis[top]+1;
				if(v[top][i]==target) return dis[v[top][i]];
			}
		}
	}
	return 0;
}

int main()
{
	int cases,caseno=1;
	cout<<"SHIPPING ROUTES OUTPUT\n\n";
	cin>>cases;
	string st,stt;
	while(cases--)
	{
		cin>>mm>>n>>k;
		cout<<"DATA SET  "<<caseno++<<"\n"<<endl;
		for(int i=1;i<=mm;i++)
		{
			cin>>st;
			m[st]=i;
		}
		for(int i=0;i<n;i++)
		{
			cin>>st>>stt;
			v[m[st]].pb(m[stt]);
			v[m[stt]].pb(m[st]);
		}
		int si;
		for(int i=0;i<k;i++)
		{
			cin>>si;
			cin>>st>>stt;
			int k=bfs(m[st],m[stt]);
			if(k)
			{
				printf("$%d\n",k*si*100);
			}
			else printf("NO SHIPMENT POSSIBLE\n");
		}
		cout<<endl;
		repi(i,0,40)
		{
			v[i].clear();
		}
		m.clear();

	}

	cout<<"END OF OUTPUT\n";
	return 0;
}



















