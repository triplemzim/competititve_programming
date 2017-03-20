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

iii dp[1002][1002], grid[1002][1002];
int n, m;

iii Calc(int i, int j)
{
    if(i==n)
    {
        iii ans=0;
        for(int k=j; k<=m; k++)
        {
            ans+= grid[i][k];
        }
        return dp[i][j]= ans;
    }
    if(j==m)
    {
        iii ans=0;
        for(int k=i; k<=n; k++)
        {
            ans+= grid[k][j];
        }
        return dp[i][j]= ans;
    }

    if(i>n || j>m)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    iii ret=-inf;
    //cout<<i<<" "<<j<<" "<<Calc(i,j+1)<<" "<<Calc(i+1,j)<<endl;
    ret=max(ret,Calc(i,j+1)+grid[i][j]);
    ret=max(ret,Calc(i+1,j)+grid[i][j]);
    return dp[i][j]=ret;
}

int main()
{
    ios::sync_with_stdio(false);
    int test, cases=1;
    cin>>test;
    while(test--)
    {
        ms(dp,-1);
        cin>>n>>m;
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=m; j++)
            {
                cin>>grid[i][j];
            }
        }
        printf("Case %d: ", cases++);

        cout<<Calc(1,1)<<endl;
    }
    return 0;
}

