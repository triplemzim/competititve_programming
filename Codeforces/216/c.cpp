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

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long

using namespace std;

//#define sets(n,pos) (n|(1<<pos))
//#define check(n,pos) (bool(n&(1<<pos)))
//#define mx 100000000
//#define lim 10000
//unsigned prime[mx>>6];
//void seive()
//{
//	unsigned k,i,j;
//	prime[2>>6]=sets(prime[2>>6],0);
//	for(i=3;i<lim;i+=2)
//	{
//		if(check(prime[i>>6],((i>>1)&31))==0)
//		{
//			if(i<100) cout<<i<<" ";
//			k=i<<1;
//			for(j=i*i;j<=mx;j+=k)
//			{
//				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
//			}
//		}
//	}
//	return;
//}


bool color[100009]={false};
vector<int> v[100009];
map<pair<int,int>, bool> mp;
int n;
vector<int> ans;
queue<int> q;


void bfs(int top)
{
	color[top]=true;
	q.push(top);
	int last=0;
	bool flag=false;

	if(mp[make_pair(1,top)]==true)
	{
		flag=true;
		if(v[top].size()==1) ans.push_back(top);

	}

	while(!q.empty())
	{
		top=q.front();q.pop();
		for(int i=0;i<v[top].size();i++)
		{
			if(color[v[top][i]]==false)
			{
				color[v[top][i]]=true;
				if(mp[make_pair(top,v[top][i])]==true)
				{
					flag=true;
//					if(v[v[top][i]].size()==1) ans.push_back(v[top][i]);

				}
				if(flag && v[v[top][i]].size()==1)
				{
					ans.push_back(v[top][i]);
					flag=false;
				}
				q.push(v[top][i]);
			}
		}
	}

}


int main()
{
	int x,y,con,index=1;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y>>con;
		v[x].push_back(y);
		v[y].push_back(x);
		if(con==2)
		{
			mp[make_pair(y,x)]=true;
			mp[make_pair(x,y)]=true;
		}
		else
		{
			mp[make_pair(y,x)]=false;
			mp[make_pair(x,y)]=false;
		}
	}


	int count=0;
	color[1]=true;


	for(int i=0;i<v[1].size();i++)
	{
		bfs(v[1][i]);

	}

	x=ans.size();

	cout<<x<<endl;
	for(int i=0;i<x-1;i++)
	{
		cout<<ans[i]<<" ";
	}
	if(x>0) cout<<ans[x-1]<<endl;


	return 0;
}






