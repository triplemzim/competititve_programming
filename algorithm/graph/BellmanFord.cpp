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
#define MAXN 10009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}




class BellmanFord
{
    public:
        int n,m,a,b,c,src,dst;
        vector<int> G[MAXN],cost[MAXN];
        int parent[MAXN],bell[MAXN];
        bool neg_cycle,color[MAXN];

        void take_input()
        {
            neg_cycle=false;
            
            scan(n);
            scan(m);


            for (int  i = 0; i < n+11; i++) {
                G[i].clear();
                cost[i].clear();
            }


            for(int i=0;i<m;i++){
                scanf("%d%d%d",&a,&b,&c);
                G[a].pb(b);
//                G[b].pb(a);
                cost[a].pb(c);
//                cost[b].pb(c);
            }
        }

        void find_neg_cycle()
        {
            src=1;
            ms(color,false); 
            queue<int>q;
            for(int i=0;i<=n;i++) bell[i]=inf;
            bell[src]=0;

            for (int  cyc = 0; cyc < n; cyc++) {
                while(!q.empty()) q.pop();
                q.push(src);
                ms(color,false);
                color[src]=true;

                while(!q.empty()){
                    int top=q.front();
                    q.pop();
                    for(int i=0;i<(int)G[top].size();i++){
                        int node=G[top][i];

                        if(color[node]==false){
                            color[node]=true;
                            q.push(node);

                        }
                        if(bell[node]>bell[top]+cost[top][i]){
                            bell[node]=bell[top]+cost[top][i];
                            parent[node]=top;
                            if(cyc==n-1) neg_cycle=true;
                            cout<<top<<' '<<node<<' '<<bell[node]<<endl;
                        }
                    }
                }
            }

            if(neg_cycle) cout<<"Found"<<endl;
            else cout<<"Not Found"<<endl;


        }
};


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    BellmanFord graph;
    graph.take_input();

    graph.find_neg_cycle();
    



    return 0;
}                                                                                                                                                                                                                                           
