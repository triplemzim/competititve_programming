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
#define mx ((102*101)/2)
#define MOD 1000000007
int main()
{
    iii dp[mx][2];
    ms(dp,0);
    int n,k,d;
    cin>>n>>k>>d;
    int temp=0;
    dp[0][0]=1;
    dp[0][1]=0;

    for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=min(i,k);j++)
        {
            if(j<d)
            {
                dp[i][0]+=dp[i-j][0];
                dp[i][1]+=dp[i-j][1];
            }
            else
            {


                dp[i][1]+=dp[i-j][0]+dp[i-j][1];
            }

        }
        dp[i][0]%=MOD;
        dp[i][1]%=MOD;
    }

    cout<<dp[n][1]<<endl;




    return 0;
}



