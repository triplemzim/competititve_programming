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
#define MAXN 100009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


    vector<int> v[300009];
    vector<int> cost[300009];
map< pair<int,int> , int > mp;
struct edge
{
    int u,v,w,index;
    bool operator<(const edge &x)const{
        if(w>x.w) return false;
        return true;
    }
};



struct kruskal
{
    
    vector<edge> G,g;
    int n,m,dis[MAXN];
    edge X;
    int src;
    

    void take_input(){
        int a,b,c;
        scan(n);
        scan(m);
        for (int  i = 0; i < m; i++) {
            scanf("%d %d %d",&a,&b,&c);
            v[a].pb(b);
            v[b].pb(a);
            cost[a].pb(c);
            cost[b].pb(c);
            mp[MP(min(a,b),max(a,b))]=i+1;
//            X.u=a,X.v=b,X.w=c;
//            X.index=i+1;
//            g.pb(X);
        }
        cin>>src;
        
    }
    void bfs()
    {
        edge temp;
        queue<int>q;
        q.push(src);
        bool color[300009]={false};
        color[src]=true;

        while(!q.empty()){
            int top=q.front();
            q.pop();

            for(int i=0;i<(int)v[top].size();i++){
                int p=v[top][i];
                
                if(color[p]==false){
                    color[p]=true;
                    q.push(p);
                    temp.u=top;
                    temp.v=p;
                    temp.w=cost[top][i];
                    G.pb(temp);
                }
            }
        }
    }
                    





    int find_p(int u){
        if(dis[u]==u) return u;
        return dis[u]=find_p(dis[u]);
    }
    void make_union(int u,int v){
        dis[find_p(u)]=find_p(v);
    }
                

    vector<edge> find_kruskal(){

        for (int  i = 0; i < n+1; i++) {
            dis[i]=i;
        }

        edge temp;
        vector<edge>ans;

        sort(G.begin(),G.end());

        for(int i=0;i<(int)G.size();i++){
            temp=G[i];
            if(find_p(temp.u)!=find_p(temp.v)){
                make_union(temp.u,temp.v);
                ans.pb(temp);
            }
        }
        return ans;
    }

};
        


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    vector<edge> ans; 
    kruskal kk;
    kk.take_input();
    kk.bfs();
    ans=kk.find_kruskal();

    iii cost=0;
    

    for(int i=0;i<(int)ans.size();i++){
        cost+=ans[i].w;
    }
    cout<<cost<<endl;
    
    for(int i=0;i<(int)ans.size();i++){
        cout<<mp[MP(min(ans[i].u,ans[i].v),max(ans[i].u,ans[i].v))]<<' ';
    }


    return 0;
}

