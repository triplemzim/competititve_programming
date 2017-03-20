#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
typedef long long iii;
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999

iii N,dp[22][20002],n_track,track[22];

iii cal_track(iii x,iii cost)
{
//	cout<<cost;
	if(dp[x][cost]!=-1) return dp[x][cost];
	if(x>=n_track) return 0;

	iii temp1=0,temp2=0;
	if(cost+track[x]<=N)
	{
		temp1=track[x]+cal_track(x+1,cost+track[x]);
	}
	temp2=cal_track(x+1,cost);

	return dp[x][cost]=temp1>temp2?temp1:temp2;

}
bool fg=false;
void print_sol(iii x,iii cost,iii cur)
{
	if(x>=n_track) return;
	iii temp1=0,temp2;
	if(track[x]+cost<=N)
	{
		temp1=track[x]+cal_track(x+1,cost+track[x]);
		if(temp1==cur) {
			printf("%lld ",track[x]);
			fg=true;
			print_sol(x+1,cost+track[x],cur-track[x]);
		}
		else print_sol(x+1,cost,cur);
	}
	else print_sol(x+1,cost,cur);

}

int main()
{
//	freopen("in.txt","r",stdin);
	bool flag=false;
	while(scanf("%lld",&N)!=EOF)
	{
//		if(flag) cout<<endl;
//		flag=true;
		fg=false;
		ms(dp,-1);
		scanf("%lld",&n_track);
		for(int i=0;i<n_track;i++) scanf("%lld",&track[i]);

		int MX=cal_track(0,0);
//		cout<<dp[1][1]<<endl;

		print_sol(0,0,MX);
		printf("sum:%lld\n",MX);
//		else printf("sum:%lld",MX);
	}


	return 0;
}
