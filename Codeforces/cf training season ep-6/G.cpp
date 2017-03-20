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

char G[110][110];
int row,col;
double dp[110][110];

double fun(int r,int c)
{
    if(r>=row || c>=col) return 0;
    char ch=G[r][c];
    double &ret=dp[r][c];
    if(ret!=-1) return ret;
    if(ch=='.') return ret=fun(r+1,c);
    if(ch>='1' && ch<='9') return ret=(double)(ch-'0');

    ret=.5 * fun(r,c-1) + .5 * fun(r,c+1);
    return ret;
}


int main()
{
//    freopen("in.txt","r",stdin);
    int cases;
    cin>>cases;
    while(cases--)
    {
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                dp[i][j]=-1;
            }
        }


        cin>>row>>col;
        for(int i=0;i<row;i++)
        {
            scanf(" %s",G[i]);
        }

        double ans=0;
        for(int i=0;i<col;i++)
        {
            ans=max(ans,fun(0,i));
        }
        printf("%.6lf\n",ans);
    }



    return 0;
}

