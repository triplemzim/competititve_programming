//AC


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

vector<int>v[35];
vector<int>path[35];
int n,k;
int dp[35],dir[35];

int lis(int x)
{
	if(dp[x]!=-1) return dp[x];
	int a,b,mx=1;
	for(int i=0;i<path[x].size();i++)
	{
		a=1+lis(path[x][i]);
		if(a>mx)
		{
			mx=a;
			dir[x]=path[x][i];
		}
	}
	return dp[x]=mx;
}

int main()
{
	int temp;

	while(scanf("%d %d",&n,&k)!=EOF)
	{
		ms(dp,-1);
		ms(dir,-1);

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<k;j++)
			{
				cin>>temp;
				v[i].pb(temp);
			}
		}

		for(int i=0;i<n;i++)
		{
			sort(v[i].begin(),v[i].end());
		}

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				bool flag=true;
				if(i==j) continue;
				for(int m=0;m<k;m++)
				{
					if(v[i][m]>=v[j][m])
					{
						flag=false;
						break;
					}
				}
				if(flag==true)
				{
					path[i].pb(j);
				}
			}
		}
		int mx=0,start;
		for(int i=0;i<n;i++)
		{
			temp=lis(i);
			if(mx<temp)
			{
				mx=temp;
				start=i;
			}
		}
		cout<<mx<<endl;
		cout<<start+1;
		start=dir[start];
		while(start!=-1)
		{
			cout<<' '<<start+1;
//			for(int i=0;i<k;i++) cout<<v[start][i]<<' ';
//			cout<<endl;
			start=dir[start];
		}
		cout<<endl;
		for(int i=0;i<n;i++)
		{
			v[i].clear();
			path[i].clear();
		}
	}


	return 0;
}

