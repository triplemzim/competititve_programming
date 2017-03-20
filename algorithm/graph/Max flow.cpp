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

#define MAX_n 500           //max node 
int node;
vector<int> Graph[MAXN];   // Graph store
int flow[MAX_n][MAX_n];   // adjacency matrix for flow

bool bfs(int rGraph[][MAX_n],int sink,int target,int parent[])
{
    bool visited[MAX_n];
    ms(visited,false);
    queue<int>q;
    visited[sink]=true;
    parent[sink]=-1;

    q.push(sink);
    while(!q.empty()){
        int top=q.front();
        q.pop();
//        cout<<Graph[top].size()<<endl;
        for (int  i = 0; i < (int)Graph[top].size(); i++) {
            int V=Graph[top][i];
            if(rGraph[top][V]>0 && visited[V]==false){       //if there is nonzero flow from u to v
                q.push(V);
                parent[V]=top;
                visited[V]=true;
            }
        }
    }
    return visited[target];    //if there is a path from sink to target
}

iii ford_fulkerson(int sink,int target)
{
    int u,v,parent[node];

    int rGraph[MAX_n][MAX_n];    // temporary storage of flow (residual)
    ms(rGraph,0);

    for(int i=0;i<=node;i++){
        for (int  j = 0; j <=node;j++){
            rGraph[i][j]=flow[i][j];
        }
    }
    iii max_flow=0;

    while(bfs(rGraph,sink,target,parent)==true){    //if there is path
        int path_flow=inf;

        for(v=target;v!=sink;v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);  //calculating min_flow of that path
        }

        for(v=target;v!=sink;v=parent[v]){      //updating that path taking that min_flow
            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }
        max_flow+=path_flow;        //adding that min flow to max_flow
    }
    return max_flow;
}

            

                

int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);

    scan(node);
    int edge;
    scan(edge);
    int cap,u,v;
    for (int  i = 0; i < edge; i++) {
        scan(u);
        scan(v);
        scan(cap);
        Graph[u].pb(v);
        Graph[v].pb(u);
        flow[u][v]=cap;
    }

    cout<<ford_fulkerson(0,5)<<endl;       //answer = 23

    



    return 0;
}
