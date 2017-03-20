#include <bits/stdc++.h>

using namespace std;

//pair<long long, long long> dp[100005];

int  p[100005], T[100005][30], L[100005];
long long ds[100004];
int taken[100005];
vector<int>v[100005];
vector<long long> val[100005];

//pair<long long, long long> dfs(int node)
//{
//
//    pair<long long, long long> p, &rt= dp[node];
//
//    if(rt.first!=-1) return rt;
//
//    long long x,y,z,ans=0, road=0;
//
//    for(int i=0; i<v[node].size(); i++)
//    {
//        long long u= v[node][i];
//        if(!taken[v[node][i]])
//        {
//
//            printf("%lld   %lld\n",node,u);
//            taken[u]=1;
//            z= val[node][i];
//
//            p= dfs(u);
//            x= p.first;
//            y= p.second;
//            road+=y;
//
//            if(y==0) road+=1;
//
//            z= (z*y)+z;
//
//            ans+=(z+(2*x));
//
//            printf("%lld\n",ans);
//        }
//    }
//
//    printf("   %lld   %lld %lld\n",node, ans, road);
//    rt= make_pair(ans, road);
//
//    return rt;
//}

int dist(int x, int y)
{
    int  tmp, log, i;

      if (L[x] < L[y])
          tmp = x, x = y, y = tmp;

        log=1;
      while(1) {
        int next=log+1;
        if((1<<next)>L[x])break;
        log++;

      }

        for (i = log; i >= 0; i--)
          if (L[x] - (1 << i) >= L[y])
              x = T[x][i];

      if (x == y)
      {
          //printf("hoise %d\n",x);
          return x;
      }

        for (i = log; i >= 0; i--)
          if (T[x][i] != -1 && T[x][i] != T[y][i])
              x = T[x][i], y = T[y][i];

      return p[x];
}


int main()
{
    int t, n, a,b;
    long long c;
    scanf("%d",&t);

    while(t--)
    {
        memset( taken, 0, sizeof(taken));

//        for(int i=0; i<100004; i++)
//            dp[i].first=-1;


        scanf("%d",&n);

        for(int i=0; i<n-1; i++)
        {
            scanf("%d %d %lld",&a,&b,&c);

            v[a].push_back(b);
            v[b].push_back(a);

            val[a].push_back(c);
            val[b].push_back(c);
        }

        //tree

        queue<int> q;

        q.push(0);
        p[0]=-1;
        taken[0]=1;
        L[0]=0;
        ds[0]=0;

        while(1)
        {
            if(q.empty()) break;

            int u= q.front();
            q.pop();
            //printf("%d %d\n",u, v[u].size());

            for(int i=0; i<v[u].size(); i++)
            {
                if(taken[v[u][i]]!=1)
                {
                    //printf("%d %d\n",u, v[u][i]);
                    taken[v[u][i]]=1;
                    q.push(v[u][i]);
                    p[v[u][i]]= u;
                    L[v[u][i]]= L[u]+1;
                    ds[v[u][i]]= ds[u]+val[u][i];
                }
            }
        }

        for(int i=0; i<n; i++)
            //printf("%d\n",p[i]);

        for (int i = 0; i < n; i++)
            T[i][0] = p[i];

        for (int j = 1; (1 << j) < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (T[i][j - 1] != -1)
                {
                    T[i][j]= T[T[i][j-1]][j-1];
                    //T[i][j] = T[T[i][j - 1]][j – 1];
                }
            }
        }

//        for(int i=0; i<n; i++)
//        {
//            for(int j=0; j<10; j++)
//                printf("%d,%d ",T[i][j],p[i]);
//            printf("\n");
//        }

        double x,y, num, ans=0;

        //cout<< ans<< endl;

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                int  par= dist(i,j);

                long long head;

                if(par==-1) head=0;
                else head =ds[par];
                ans+= ds[i]+ds[j]-(2*head);

                //cout<<par<<" "<<ans<<" "<<i<<" "<<j<<" "<<ds[i]<<" "<<ds[j]<< endl;
            }
        }

//        pair<long long, long long> p;
//
//        taken[0]=1;
//        p= dfs(0);
//        x=p.first;
//        y=p.second;

        num=(n*(n-1))/2;
        ans= ans/num;

        //printf("%lf %lf\n",num,ans);

//        printf("%lf %lf %lf\n",x,y,num);
        printf("%lf\n",ans);
    }
}
