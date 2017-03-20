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
#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
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

int n,num[110],cum[110],dp[110][110];

int fun(int a,int b)
{
    if(a==b)
    {
       return num[a];
    }
    if(a>b)
    {
       return 0;
    }
    if(dp[a][b]!=-1) return dp[a][b];

    int sum=0;
    int mx=-inf;
    for(int i=a;i<=b;i++)
    {
        sum+=num[i];
        int temp=sum-fun(i+1,b);
        mx=max(mx,temp);
    }
    sum=0;
    for(int i=b;i>=a;i--)
    {
        sum+=num[i];
        int temp=sum-fun(a,i-1);
        mx=max(mx,temp);
    }

    return dp[a][b]= mx;

}









int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);

    int cases,caseno=1;
    scan(cases);
    cum[0]=0;
    while(cases--)
    {
        ms(dp,-1);
        scan(n);
        for (int  i = 1; i <= n; i++) {
            scan(num[i]);
            cum[i]=(i>0?cum[i-1]:0)+num[i];
        }
        int ans=fun(1,n);
        printf("Case %d: ",caseno++);
        cout<<ans<<endl;
    
    }



    return 0;
}
