#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef pair<int,int> pii;

#define eps 1e-9
#define MP make_pair
#define SORT(a) sort(a.begin(),a.end())
#define REVERSE(a) reverse(a.begin(),a.end())
#define PI acos(-1)
#define ms(x,y) memset(x,y,sizeof(x))
#define INF 2000000000
#define pb push_back
#define debug cout<<"A"<<endl
#define prnt(a) cout<<a<<endl
#define mod 1000000007
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n & ~(1<<pos))
#define check(n,pos) bool (n&(1<<pos))

//int fx[]={1,-1,0,0};
//int fy[]={0,0,1,-1};
//int fx[]={0,0,1,-1,-1,1,-1,1};
//int fy[]={-1,1,0,0,1,1,-1,-1};

int d[102][102];
int match[102];
int n,m,s,v;
vector<int> graph[102];

bool bpm(int u,bool seen[])
{
    for(int i=0;i<graph[u].size();i++)
    {
        if(seen[graph[u][i]]==false)
        {
            seen[graph[u][i]]=true;
            if(match[graph[u][i]]<0 || bpm(match[graph[u][i]],seen)==true)
            {
                match[graph[u][i]]=u;
                return true;
            }
        }
    }
    return false;
}







int maxBPM()
{
    ms(match,-1);
//    cout<<"match: "<<match[50]<<endl;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        bool seen[102]={false};
        if(bpm(i,seen)==true)
        {
            ans++;
        }
    }
    return ans;
}




int main()
{
//    freopen("gopher.in","r",stdin);
//   freopen("out.txt","w",stdout); 
    
    double gx[102], gy[102], hx[102], hy[102];

    while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
    {
        double x=((double)v*(double)s);
        x*=x;
        for(int i=0; i<n; i++)
            cin>>gx[i]>>gy[i];
        for(int i=0; i<m; i++)
            cin>>hx[i]>>hy[i];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                double temp=(gx[i]-hx[j])*(gx[i]-hx[j])+(gy[i]-hy[j])*(gy[i]-hy[j]);
                if(x-temp>=0.000000000)
                    graph[i].pb(j);
                }
            }
       cout<<n-maxBPM() <<endl;

       for(int i=0;i<n;i++) graph[i].clear();
    }
    return 0;
}
