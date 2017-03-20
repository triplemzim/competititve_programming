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

char st[100];
int len;
iii dp[100][100];
int cnt=0;

iii fun(int a,int b)
{
    if(a==b) return 1;
    else if(a>b) return 0;
    if(dp[a][b]!=-1) return dp[a][b];
//    cout<<a<<' '<<b<<endl;
    cnt++;

    iii count=0;

    count=fun(a,b-1)+fun(a+1,b)-fun(a+1,b-1);

    if(st[a]==st[b])
    {
        count+=fun(a+1,b-1)+1;
    }
    
    
    return dp[a][b]=count;
}
    

int main() { 
//    freopen("in.txt","r",stdin);

    int cases;
    int caseno=1;
    scan(cases);
    while(cases--){
        ms(dp,-1);
        scanf("%s",st);
        len=strlen(st);
        printf("Case %d: %lld\n",caseno++,fun(0,len-1));
//        cout<<cnt<<endl;
//        cout<<dp[1][2]<<endl;


    }

    return 0;
}
