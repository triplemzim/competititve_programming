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

class SCC
{
    public:

    int V;
    vector<int> *g;
    SCC(int V)
    {
        this->V=V;
        g=new vector<int>[V+9];
    }
    SCC(vector<int>graph[])
    {
        g=graph;
    }
    void addedge(int u,int v)
    {
        g[u].pb(v);
    }
    void dfsVisit(vector<int> &temp,int u,bool visited[])       // temp vector: for storing SCC
    {
        visited[u]=true;
        temp.pb(u);
//        cout<<u<<' ';
        itr_all(g[u], it)
        {
            if(!visited[*it])
            {
                dfsVisit(temp,*it,visited);
            }
        }
    }

    SCC getTranspose()
    {
        SCC gT(V);
        for(int i=1;i<=V;i++)
        {
            itr_all(g[i],it)
            {
                gT.addedge(*it,i);
            }
        }
        return gT;
    }

    void getOrder(stack<int> &st,int u,bool visited[])
    {
        visited[u]=true;

        itr_all(g[u],it)
        {
            if(visited[*it]==false)
            {
                getOrder(st,*it,visited);
            }
        }
        st.push(u);
    }

    vector<vector<int> > generateSCC()
    {
        bool *visited;
        stack<int> st;

        visited=new bool[V+9];

        ms(visited,false);

        for(int i=1;i<=V;i++)
        {
            if(visited[i]==false)
            {
                getOrder(st,i,visited);
            }
        }
        SCC gT=getTranspose();

        vector<vector<int> >ret;
        vector<int> temp;
        
        int v;
        ms(visited,false);

        while(!st.empty())
        {
            v=st.top();
            st.pop();
            if(visited[v]==false)
            {
                temp.clear();
                gT.dfsVisit(temp,v,visited);
                ret.pb(temp);
//                cout<<endl;
            }
        }

        return ret;
    }



};

int main()
{
    ios::sync_with_stdio(false);
    int n;
//    cin>>n;
    n=4;
    SCC g(n);
    
    g.addedge(2,3); 
    g.addedge(1,2);
    g.addedge(3,1);
    g.addedge(1,4);
    g.addedge(4,5);

    vector<vector<int> > v;
    v=g.generateSCC();
    cout<<"There are "<<v.size()<<" strongly connected component(s)."<<endl;

    for(int i=0;i<(int)v.size();i++)
    {
        for(int j=0;j<(int)v[i].size();j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }





    return 0;
}
