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

#define sets(n,pos) (n|(1<<(pos)))
#define reset(n,pos) (n& ~(1<<(pos)))
#define check(n,pos) (bool(n&(1<<(pos))))


int n,k;
iii dp[16][1<<16];

iii calc(int num,int bitmask)
{
    if(bitmask==(1<<n)-1) return 1;

    if(dp[num][bitmask]!=-1) return dp[num][bitmask];
    
    iii temp=0;
    for(int i=1;i<=n;i++)
    {
       if(i!=num && abs(num-i)<=k && check(bitmask,i-1)==false){
          if(calc(i,sets(bitmask,i-1))!=0) temp+=calc(i,sets(bitmask,i-1));
       }
    }
   return dp[num][bitmask]=temp; 
    
}

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);
    int cases;
    scan(cases);
    while(cases--){
        scan(n);
        scan(k);
        ms(dp,-1);
        iii sum=0;
        for(int i=1;i<=n;i++){
            sum+=calc(i,1<<(i-1));
        }
        printf("%lld\n",sum);
    }




    return 0;
}
