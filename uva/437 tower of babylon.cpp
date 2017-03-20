//verdict: AC


#include<bits/stdc++.h>

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

vector<int>v[200];
vector<int>path[200];
int n,k;
int dp[200],dir[200];

int lis(int x)
{
	if(dp[x]!=-1) return dp[x];
	int a=0,b,mx=v[x][2];
	for(int i=0;i<path[x].size();i++)
	{
		a=v[x][2]+lis(path[x][i]);
		if(a>=mx)
		{
			mx=a;
//			dir[x]=path[x][i];
		}
	}
	return dp[x]=mx;
}

int main()
{
	freopen("in.txt","r",stdin);
	int temp,caseno=1;

	while(scanf("%d",&n)==1)
	{
		if(!n) break;
		ms(dp,-1);
//		ms(dir,-1);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<3;j++)
			{
				cin>>temp;
				v[i].pb(temp);
			}
		}
		int index=n;
		for(int i=0;i<n;i++)
		{
			v[index].pb(v[i][1]);
			v[index].pb(v[i][2]);
			v[index++].pb(v[i][0]);

			v[index].pb(v[i][2]);
			v[index].pb(v[i][0]);
			v[index++].pb(v[i][1]);

			v[index].pb(v[i][0]);
			v[index].pb(v[i][2]);
			v[index++].pb(v[i][1]);

			v[index].pb(v[i][1]);
			v[index].pb(v[i][0]);
			v[index++].pb(v[i][2]);

			v[index].pb(v[i][2]);
			v[index].pb(v[i][1]);
			v[index++].pb(v[i][0]);
		}


//		for(int i=0;i<n;i++)
//		{
//			sort(v[i].begin(),v[i].end());
//		}

		int count;

		for(int i=0;i<index;i++)
		{
			for(int j=0;j<index;j++)
			{
				bool flag=true;
				if(i==j) continue;
				count=0;

				for(int m=0;m<2;m++)
				{
					if(v[i][m]>=v[j][m])
					{
						flag=false;
						break;
					}
				}
				if(flag==true)
				{
//					cout<<j<<' '<<i<<endl;
					path[j].pb(i);
				}
			}
		}
		int mx=0,start;
		for(int i=0;i<index;i++)
		{
			temp=lis(i);
			if(mx<temp)
			{
				mx=temp;
//				start=i;
			}
		}
		printf("Case %d: maximum height = %d\n",caseno++,mx);

		for(int i=0;i<index;i++)
		{
			v[i].clear();
			path[i].clear();
		}
	}


	return 0;
}


