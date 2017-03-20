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
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))

int dp[1<<11][3][27];
int mask[2];
int n[2];
int a[2][20][2];
int t;

int rec(int msk, int plr, int prev)
{
    if(msk== 1<<(n[plr]-1)) return 0;
    if(dp[msk][plr][prev]!=-1) return dp[msk][plr][prev];

    int &rt= dp[msk][plr][prev];

    for(int i=0; i<n[plr]; i++)
    {
        if(!check(mask[plr], i))
        {
            if(a[plr][i][0]== prev)
            {
                mask[plr]= sets(mask[plr], i);
                int last= a[plr][i][1];

                int r= rec(mask[(plr+1)%2], (plr+1)%2, last);

                mask[plr]= reset(mask[plr], i);

                if(r==0) return rt=1;
            }
        }
    }

    return rt=0;
}


int main()
{

//    freopen("in.txt","r",stdin);

    scanf("%d",&t);
    char s[100002];

    for(int xx=0; xx<t; xx++)
    {
        mask[0]=0;
        mask[1]=0;
        memset(dp ,-1, sizeof(dp));
        scanf("%d",&n[0]);
        getchar();

        for(int i=0; i<n[0]; i++)
        {
//            scanf("\n");
            gets(s);

            a[0][i][0]= s[0]-'a';
            a[0][i][1]= s[strlen(s)-1]-'a';
        }
        scanf("%d",&n[1]);
        getchar();

        for(int i=0; i<n[1]; i++)
        {
//            scanf("\n");
            gets(s);


            a[1][i][0]= s[0]-'a';
            a[1][i][1]= s[strlen(s)-1]-'a';
        }

        int plr=0;
        int fl=0;
        for(int i=0; i<n[plr]; i++)
        {
            if(!check(mask[plr], i))
            {
                if(true)
                {
                    mask[plr]= sets(mask[plr], i);
                    int last= a[plr][i][1];

                    int r= rec(mask[(plr+1)%2], (plr+1)%2, last);

                    mask[plr]= reset(mask[plr], i);

                    if(r==0)
                    {
                        //printf("%d\n", i);
                        printf("Game %d: player1\n", xx+1);
                        fl=1;
                        break;
                    }
                }
            }
        }

        if(fl) continue;

        printf("Game %d: player2\n", xx+1);
    }


    return 0;
}


