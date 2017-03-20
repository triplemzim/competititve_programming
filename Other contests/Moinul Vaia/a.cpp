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

double dp[1000009];

double calc(int N)
{
    if(N==1) return 0;
    if(dp[N]>-1) return dp[N];

    int sq=sqrt(N);
    double count=1,temp=0;

    for(int i=2;i<=sq;i++)
    {
        if(N%i==0){
            count++;
            temp+=calc(N/i);
            if(i*i==N) continue;
            count++;
            temp+=calc(i);
        }
    }

    
    temp/=count;
    temp+=(1.0/count);
    temp+=1;
    return dp[N]=temp;
}




int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases,caseno=1;
    int N;
    scan(cases);
    ms(dp,-1);
    while(cases--){
        scan(N);
        printf("Case %d: %.10lf\n",caseno++,calc(N));
    }




    return 0;
}   
