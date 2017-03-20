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
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))


int guest;
double box[6];
double p[13][6];
double dp[13][13][13][13][13];
bool chk[13][13][13][13][13];

double prob(int a,int b,int c,int d,int e)
{
    int x=a+b+c+d+e;
    x=guest-x;
    if(x==guest) return 1;
    double &ret=dp[a][b][c][d][e];
    if(chk[a][b][c][d][e]) return ret;
    double temp=0;
    x++;
    if(a)
    {
        temp=p[x][1] * prob(a-1,b,c,d,e)*a;
    }
    if(b)
    {
        temp+=p[x][2] * prob(a,b-1,c,d,e)*b;
    }
    if(c)
    {
        temp+=p[x][3] * prob(a,b,c-1,d,e)*c;
    }
    if(d)
    {
        temp+=p[x][4] * prob(a,b,c,d-1,e)*d;
    }
    if(e)
    {
        temp+=p[x][5] * prob(a,b,c,d,e-1)*e;
    }
    chk[a][b][c][d][e]=true;
    return ret=temp;
}
    


int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);

    int kase;
    scan(kase);
    while(kase--){
        ms(chk,false);
        scan(guest);
        for (int  i = 1; i < 6; i++) {
            scanf("%lf",&box[i]);
        }
        for (int  i = 0; i < guest; i++) {
            for (int  j = 0; j < 5; j++) {
                scanf("%lf",&p[i+1][j+1]);
            }
        }

        int boxno=1;
        double mxp=-1,prev=-1;

        double total_prob=prob(box[1],box[2],box[3],box[4],box[5]);
        if(box[1])mxp=max(mxp,p[1][1]*prob(box[1]-1,box[2],box[3],box[4],box[5])/total_prob);

        if(mxp!=prev)
        {
            prev=mxp;
            boxno=1;
        }
        if(box[2])mxp=max(mxp,p[1][2]*prob(box[1],box[2]-1,box[3],box[4],box[5])/total_prob);
        if(mxp!=prev)
        {
            prev=mxp;
            boxno=2;
        }
        if(box[3])mxp=max(mxp,p[1][3]*prob(box[1],box[2],box[3]-1,box[4],box[5])/total_prob);
        if(mxp!=prev)
        {
            prev=mxp;
            boxno=3;
        }
        if(box[4])mxp=max(mxp,p[1][4]*prob(box[1],box[2],box[3],box[4]-1,box[5])/total_prob);
        if(mxp!=prev)
        {
            prev=mxp;
            boxno=4;
        }
        if(box[5]) mxp=max(mxp,p[1][5]*prob(box[1],box[2],box[3],box[4],box[5]-1)/total_prob);
        if(mxp!=prev)
        {
            prev=mxp;
            boxno=5;
        }



        cout<<boxno<<' ';
        printf("%.3lf\n",mxp);
    }
                


    return 0;
}
