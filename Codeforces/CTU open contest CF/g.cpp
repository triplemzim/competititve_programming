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

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}



int n,c,cost[1001][1001];
int dist[1001];
vector<int> g[1001];


int calc(int par,int node)
{
    
    int temp_cost=0;

    bool flag=false;
    for(int i=0;i<(int)g[node].size();i++){
        int x=g[node][i];
        if(x==par) continue;
        flag=true;

        int tc=calc(node,x);
        if(tc>cost[node][x]){
            temp_cost+=cost[node][x];
        }
        else {
            temp_cost+=tc;
        }
    }
    if(flag==false){
        return cost[par][node];
    }
    return temp_cost;
}

   





int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int u,v,w;
    
    while(scanf("%d %d",&n,&c)!=EOF){
        for(int i=0;i<1001;i++){
            g[i].clear();
        }
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].pb(v);
            g[v].pb(u);
            cost[u][v]=cost[v][u]=w;
        }
        cout<<calc(-1,c)<<endl;
    }
    



    return 0;
}

