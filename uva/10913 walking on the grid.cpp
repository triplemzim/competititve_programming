//AC
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
#define inf 99999999

int n,m,k,mx,grid[80][80],dp[77][77][3][6];
bool flag;
int calc(int x,int y,int cost,int cnt,int dir)
{

    if(x==n && y==n )
    {
        if(grid[x][y]<0 && cnt>=k) return -inf;

        if(cnt<=k) return dp[x][y][dir][cnt]=grid[x][y];
        else return -inf;
    }
    if(x>n || y>n || cnt>k || x<1 || y<1)
    {
        return -inf;
    }
    if(dp[x][y][dir][cnt]!=-1) return dp[x][y][dir][cnt];

    int temp=-inf;
    if(dir!=1 && calc(x,y-1,cost+grid[x][y],grid[x][y]<0?cnt+1:cnt,2)!=-inf)
         temp=grid[x][y]+calc(x,y-1,cost+grid[x][y],grid[x][y]<0?cnt+1:cnt,2);

    int temp2=-inf;
    if(dir!=2 && calc(x,y+1,cost+grid[x][y],grid[x][y]<0?cnt+1:cnt,1)!=-inf)
         temp2=grid[x][y]+calc(x,y+1,cost+grid[x][y],grid[x][y]<0?cnt+1:cnt,1);

    temp=max(temp,temp2);

    if(calc(x+1,y,cost+grid[x][y],grid[x][y]<0?cnt+1:cnt,0)!=-inf)
        temp2=grid[x][y]+calc(x+1,y,cost+grid[x][y],grid[x][y]<0?cnt+1:cnt,0);

    temp=max(temp,temp2);


    return dp[x][y][dir][cnt]=temp;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int caseno=1;
    while(scanf("%d %d",&n,&k)==2)
    {
            ms(dp,-1);

        if(!n && !k) break;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&grid[i+1][j+1]);
            }
        }
        mx=-inf;
        mx=calc(1,1,0,0,1);


        if(mx==-inf) printf("Case %d: impossible\n",caseno++);
        else printf("Case %d: %d\n",caseno++,mx);


    }
    return 0;
}

