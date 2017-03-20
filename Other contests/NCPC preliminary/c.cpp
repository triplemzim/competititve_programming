#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MOD 1000000007

int cases,caseno=1,node,m,reach,p;
iii initial_time[110];//done
vector<int>v[110];//done
//int dist[110][110];//done
//int target;
bool visited[110];//done
int parent[110];//done
vector<int>time_c[110][110];//done

void cal_dist(int src)
{
  queue<int>q;
  int top;
  q.push(src);
  visited[src]=true;
  while(!q.empty())
  {
        top=q.front();
        q.pop();
        for(int i=0;i<v[top].size();i++)
        {
            int x=v[top][i];
            if(visited[x]==false)
            {
                parent[x]=parent[top]+1;
                visited[x]=true;
                if(parent[x]<reach) q.push(x);
            }
        }
  }

}



int main()
{
    freopen("in.txt","r",stdin);
    int x,y;
    cin>>cases;
    iii final_time[110]={0};//done
    while(cases--)
    {
//        ms(dist,0);
//        cin>>node>>m>>reach>>p;
        scanf("%d %d %d %d",&node,&m,&reach,&p);
        for(int i=0;i<node;i++)
        {
            scanf("%lld",&final_time[i]);
            initial_time[i]=final_time[i];
        }

        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            v[x].pb(y);
            v[y].pb(x);
        }

        for(int i=0;i<node;i++)
        {
            ms(parent,0);
            ms(visited,false);
            cal_dist(i);
            for(int j=0;j<node;j++)
            {
                if(i==j) continue;
//                dist[i][j]=parent[j];
                time_c[i][parent[j]].pb(j);
//                cout<<i<<' '<<j<<' '<<dist[i][j]<<endl;
            }
        }
        x=1;
        y=1;
//        cout<<p;
        while(y<=p)
        {
//            cout<<"a";
            if(x==reach+1) x=1;

            for(int i=0;i<node;i++)
            {
//                final_time[i]=initial_time[i];
                for(int j=0;j<time_c[i][x].size();j++)
                {

                    final_time[i]+=initial_time[time_c[i][x][j]];
//                    if(i==1) cout<<'a'<<initial_time[time_c[i][x][j]]<<endl;

                }
                final_time[i]%=MOD;
            }
            for(int i=0;i<node;i++)
                initial_time[i]=final_time[i];
            x++;
            y++;
        }
        printf("Case %d:",caseno++);
        for(int i=0;i<node;i++)
        {
            printf(" %lld",final_time[i]);
        }
        printf("\n");
        for(int i=0;i<node;i++) v[i].clear();
        for(int i=0;i<node;i++) for(int j=0;j<node;j++) time_c[i][j].clear();

    }

    return 0;
}

