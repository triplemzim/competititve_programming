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


int main()
{
//    cout<<-9%6;
    iii dp[100009];
    iii n,k;
    iii a,b;
    scanf("%I64d %I64d",&n,&k);
    dp[0]=1;
    iii s[100009];
    s[0]=1;
    for(int i=1;i<100001;i++)
    {
        dp[i]=dp[i-1]+((i-k>=0)?dp[i-k]:0);
        s[i]=s[i-1]+dp[i];
//        if(i<10) cout<<s[i]<<endl;
        s[i]%=MOD;

        dp[i]%=MOD;

    }

    iii sum=0;
    while(n--)
    {
        sum=0;
        scanf("%I64d%I64d",&a,&b);
        sum=s[b]-s[a-1];
        sum%=MOD;
        if(sum<0) sum+=MOD;
        printf("%I64d\n",sum);
        
    }




    return 0;
}
