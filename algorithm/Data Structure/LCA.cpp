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

#define lg 23
int n,edge,x,y;
vector<int> v[MAXN];
bool color[MAXN];
int parent[MAXN],STable[MAXN][25],depth[MAXN];



void dfs(int u)
{
    if(color[u]==true) return;
    color[u]=true;
    for(int i=0;i<(int)v[u].size();i++){
        if(color[v[u][i]]==false){
            parent[v[u][i]]=u;
            depth[v[u][i]]=depth[u]+1;
            dfs(v[u][i]);
        }
    }
}


void LCA_init()
{
    parent[1]=-1;
    ms(color,false);
    ms(STable,-1);
    depth[0]=depth[1]=0;
    dfs(1);

    for (int  i = 0; i < n; i++) {
        STable[i+1][0]=parent[i+1];
    }

    for(int j=1;(1<<j)<n;j++){
        for(int i=1;i<=n;i++){
            if(STable[i][j-1]!=-1) STable[i][j]=STable[STable[i][j-1]][j-1];
        }
    }

}


int LCA(int p,int q)
{
    if(depth[p]<depth[q]) swap(p,q);

    for(int i=lg;i>=0;i--){
        if(depth[p]-(1<<i)>=depth[q]){
            p=STable[p][i];
        }
    }

    for(int i=lg;i>=0;i--){
        if(STable[p][i]!=-1 && STable[p][i]!=STable[q][i]){
            p=STable[p][i];
            q=STable[q][i];
        }
    }
    return parent[p];
}



int main()
{
//      ios::sync_with_stdio(false);
//      freopen("in.txt","r",stdin);

    scan(n);
    scan(edge);

    for (int  i = 0; i < edge; i++) {
        scan(x);
        scan(y);
        v[x].pb(y);
        v[y].pb(x);
    }

    LCA_init();




    return 0;
}
