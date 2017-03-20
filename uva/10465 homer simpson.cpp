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
#define inf 1<<30

int m,n,t,mx;
bool flag;
int mn;
int dp[10001];

int calc(int t,int burger)
{
	if(dp[t]!=-1) return dp[t];

	if(t<mn)
	{
		mx=burger;
		mn=t;
	}


	if(t==0)
	{
		flag=true;
		return 0;
	}
	else if(t<m) return 0;

	int temp1=0,temp2=0;

	temp1=1+calc(t-m,burger+1);
	if(flag) return dp[t]=temp1;

	if(t-n>=0) temp2=1+calc(t-n,burger+1);
	if(flag) return dp[t]=temp2;

	if(temp1>temp2)
	{
		return dp[t]=temp1;
	}
	else return dp[t]=temp2;
}






int main()
{
	int dif,temp;
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d%d",&m,&n,&t)!=EOF)
	{
		ms(dp,-1);
		flag=false;
		mn=inf;mx=0;
		if(m>n) temp=m,m=n,n=temp;

		dif=calc(t,0);
		if(flag)
		{
			printf("%d\n",dif);
		}
		else
		{
			printf("%d %d\n",mx,mn);
		}

	}



	return 0;
}

