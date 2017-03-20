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
#define MAXN 1001
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}





int n,m,a,b,c,edge[MAXN][MAXN],cost[MAXN][MAXN],parent[MAXN][MAXN];


int war[MAXN][MAXN];

void calc_floyd_warshall()
{
    int i,j,k;

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            if(i==j) war[i][j]=0;
            else if(cost[i][j]>-1) war[i][j]=cost[i][j];
            else war[i][j]=inf;
        }
    }

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(war[i][j]>war[i][k]+war[k][j]){
                    war[i][j]=war[i][k]+war[k][j];
                }
            }
        }
    }

}




int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    ms(cost,-1);
    cin>>n>>m;

    for (int  i = 0; i < m; i++) {
        cin>>a>>b>>c;
        edge[a][b]=edge[b][a]=1;
        cost[a][b]=cost[b][a]=c;
    }

    calc_floyd_warshall();


    while(1){
        cin>>a>>b;
        cout<<war[a][b]<<endl;
    }




    return 0;
}
