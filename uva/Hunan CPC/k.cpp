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

double teamA[6],teamB[6],pA,pB;
char waste;
double dp[6][6][6][2];

double cal_p(int pos,int A,int B,bool team)
{
    if(pos==5)
    {
        if(A==pA && B==pB) return 1;
        else return 0;
    }
    double &ret=dp[pos][A][B][team];
    int shot=5-pos;

    if(ret!=-1) return ret;

    if(team==false)
    {
        if(shot+A<B || shot+B<A)
        {
            if(A==pA && B==pB) return 1;
            return 0;
        }
    }
    else
    {
        if(shot+A-1<B || shot+B<A)
        {
            if(A==pA && B==pB) return 1;
            return 0;
        }
    }   
             
        

    if(team==false)
    {
        ret=teamA[pos]*cal_p(pos,A+1,B,!team);
        ret+=(1.0-teamA[pos])*cal_p(pos,A,B,!team);
    }
    else
    {
        ret=teamB[pos]*cal_p(pos+1,A,B+1,!team);
        ret+=(1.0-teamB[pos])*cal_p(pos+1,A,B,!team);
    }
    return ret;

}



int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);
    int caseno=1;
    
    while(scanf("%lf",&teamA[0])!=EOF)
    {
        for(int i=0;i<6;i++)
        {
            for (int  j = 0; j < 6; j++) {
                for (int  k = 0; k < 6; k++) {
                    dp[i][j][k][0]=dp[i][j][k][1]=-1;
                }
            }
        }
                   
        
        for (int  i = 1; i < 5; i++) {
            cin>>teamA[i];
        }
        for (int  i = 0; i < 5; i++) {
            cin>>teamB[i];
        }
        cin>>pA>>waste>>pB;

        double ans=cal_p(0,0,0,false)*100.0;
        printf("Case %d: %.2lf",caseno++,ans);
        cout<<"%"<<endl;
    }



    return 0;
}      
