#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
#define printL(x) printf("%I64d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vector<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

iii n,dp[4999999][6];
iii comb(iii x,iii r)
{
//    cout<<x<<' '<<r<<endl;
    if(x==0 || r==0) return 0;
    if(x==r) return 1;
    if(x<r) return 0;
    if(dp[x][r]!=-1) return dp[x][r];

    return dp[x][r]=(comb(x-1,r-1) + comb(x-1,r))%MOD;
}
    

int main()
{
    ms(dp,-1);
//    cout<<comb(499998,5);
    cin>>n;
    iii ans;

    ans=0;
//    iii start=(n-2+n%2)/2 -1;
    iii start;
    start=n;
    dp[0][0]=1;

    for(int i=1;i<=start;i++)
    {
        dp[i][0]=1;
        for(int j=1;j<6;j++)
        {
            dp[i][j]= dp[i-1][j-1]+dp[i-1][j];
        }
    }
    cout<<dp[5][3]<<endl;
    
    for(int i=start;i>=5;i--)
    {
//        cout<<"combi: "<<i<<' '<<5<<endl;
        ans=(ans+comb(i,5)%MOD)%MOD;
    }

    cout<<ans<<endl;


    



    return 0;
}
