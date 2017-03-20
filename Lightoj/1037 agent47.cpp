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
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))



int n,life[20];
char bullet[20][20];
int dp[(1<<15)+10][20];


int calc(int bitmask,int i)
{
    if(bitmask==(1<<n)) return 0;


    if(dp[bitmask][i]!=-1) return dp[bitmask][i];

    int cur=1;

    for(int j=0;j<n;j++){
       if(j!=i && check(bitmask,j)==true) cur=max(cur,(int)(bullet[j][i]-'0'));
    }

    int sht=life[i]/cur,temp=inf;
    if(life[i]%cur!=0) sht++;


    for(int j=0;j<n;j++){
        if(check(bitmask,j)==false){
            temp=min(temp,calc(sets(bitmask,j),j));
        }
    }

    if(temp!=inf) sht+=temp;
    
    return dp[bitmask][i]=sht;
}










int main()
{
//      ios::sync_with_stdio(false);
//      freopen("in.txt","r",stdin);

    int cases;
    int caseno=1;


    scan(cases);

    while( cases--){
        ms(dp,-1);
        scan(n);
        for (int  i = 0; i < n; i++) {
            scan(life[i]);
        }

        for (int  i = 0; i < n; i++) {
            scanf("%s",bullet[i]);
        }

        int shot=calc(1,0);

        for(int i=1;i<n;i++){
            shot=min(shot,calc((1<<i),i));
        }
        printf("Case %d: %d\n",caseno++,shot);
    }



    return 0;
}
