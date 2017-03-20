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


struct edge
{
    int u,v,w;
    bool operator<(const edge &x)const{
        if(w>x.w) return false;
        return true;
    }
};



struct kruskal
{
    
    vector<edge> G;
    int n,m,dis[MAXN];
    edge X;
    

    void take_input(){
        int a,b,c;
        scan(n);
        scan(m);
        for (int  i = 0; i < m; i++) {
            scanf("%d %d %d",&a,&b,&c);
            X.u=a,X.v=b,X.w=c;
            G.pb(X);
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
    ans=kk.find_kruskal();

    cout<<"\nMST edges are as follows: "<<endl;
    cout<<endl;

    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i].u<<' '<<ans[i].v<<' '<<"Cost: "<<ans[i].w<<endl;
    }
    


    return 0;
}
