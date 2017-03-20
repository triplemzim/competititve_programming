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
#define inf 1<<24

int t1,t2,total,n,num[35],costA[35][35],costB[35][35];


int dp[32][302],dir[32][302];


int solve()
{


	for(int i=0;i<=num[1];i++) dp[1][i]=costA[1][i]+costB[1][num[1]-i],dir[1][i]=i;


	int flag=0,lim=0,a=0;

	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=t1;j++)
		{
			int temp=inf,mn=inf;
			flag=0;
			for(int s=0;s<=j;s++)
			{
				if(num[i]<s && dp[i-1][j-s]==inf) break;
				else if(num[i]<s)
				{
					flag=1;
					temp=dp[i-1][j]+costB[i][num[i]];
				}
				else if(dp[i-1][j-s]==inf)
				{
					if(num[i]>=j) temp=costA[i][j]+costB[i][num[i]-j]+dp[i-1][0],flag=2;
				}
				else
				{
					flag=3;
					temp=dp[i-1][j-s]+costA[i][s]+costB[i][num[i]-s];
				}
				if(mn>temp)
				{
					mn=temp;
					if(flag==1)
						lim=0;
					else if(flag==2)
						lim=j;
					else if(flag==3)
						lim=s;
					else lim=0;
				}
			}
			dp[i][j]=mn;
			dir[i][j]=lim;

		}

	}

	return dp[n][t1];

}


void psol(int i,int x)
{
	if(i<1) return;

	psol(i-1,x-dir[i][x]);
	cout<<dir[i][x];
	if(i!=n) cout<<' ';

}







int main()
{
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&t1,&t2)==2)
	{
//		ms(costA,inf);
//		ms(costB,inf);

		for(int i=0;i<32;i++)
		{
			for(int j=0;j<302;j++)
			{
				dp[i][j]=inf;
			}
		}


		if(t1==0 && t2==0) break;
		scanf("%d",&n);
		for(int i=0;i<=n;i++) costA[i][0]=costB[i][0]=0;

		for(int i=1;i<=n;i++)
		{
			scanf("%d",&num[i]);
			for(int j=1;j<=num[i];j++)
			{
				scanf("%d",&costA[i][j]);

			}
			for(int j=1;j<=num[i];j++)
			{
				scanf("%d",&costB[i][j]);
			}
		}

		int ans=solve();

		printf("%d\n",ans);
		psol(n,t1);

		printf("\n\n");
	}

	return 0;
}
