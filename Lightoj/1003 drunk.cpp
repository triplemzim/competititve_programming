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

bool top_sort(vector<int> g[],int m,int indegree[],int idx)
{
    int top;
    queue<int>q;
    bool *visited=new bool[idx+9];

    ms(visited,false);
    for(int i=0;i<idx;i++)
    {
        if(indegree[i]==0) 
        {
            q.push(i);
            visited[i]=true;
        }
    }
    while(!q.empty())
    {
        top=q.front();
        q.pop();

        for(int i=0;i<(int)g[top].size();i++)
        {
            int temp=g[top][i];
            if(visited[temp]==false)
            {
                indegree[temp]--;
                if(indegree[temp]<1)
                {
                    q.push(temp);
                    visited[temp]=true;
                }
            }
        }
    }
    for(int i=0;i<idx;i++)
    {
        if(visited[i]==false) return false;
    }
    return true;
}






int main()
{
//    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    
    
    int cases,caseno=1;
    scan(cases);
    int m,indegree[100009];
    vector<int> g[100000];
    map<string,int> mp;
    while(cases--)
    {
        cin>>m;
//        cout<<m<<endl;
        int idx=0;
        ms(indegree,0);
        for(int i=0;i<m;i++)
        {
            string a,b;
            cin>>a>>b;
            if(mp.count(a)<1) mp[a]=idx++;
            if(mp.count(b)<1) mp[b]=idx++;

            g[mp[a]].pb(mp[b]);
//            cout<<mp[a]<<' '<<mp[b]<<endl;
            indegree[mp[b]]++;
           
        }

        bool flag=top_sort(g,m,indegree,idx);
        if(flag) printf("Case %d: Yes\n",caseno++);
        else printf("Case %d: No\n",caseno++);

        mp.clear();
        for(int i=0;i<idx;i++) g[i].clear();
    }
            




    return 0;
}
