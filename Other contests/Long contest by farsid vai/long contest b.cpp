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

double dp[1001][1001];

double prob(double tiger,double deer)
{
    if(tiger==0) return (double)1;
    double &Ret=dp[(int)tiger][(int)deer];
    if(Ret+.0000000001>=0) return Ret;
    double total=1+tiger;
    total=(total*(total-1))/2;

    double td=tiger*deer,tt=tiger*(tiger-1);
    tt/=2.0;
    td/=total;
    tt/=total;
//    double notEaten=1-deer/total-(deer*(deer-1))/2/total;

    double ret=0;

//    cout<<tiger<<' '<<deer<<"--";
//    if(deer>0)
//    {
//        ret=td*prob(tiger,deer-1);
//        deerkill=(deer/total)*prob(tiger,deer-1);
//        if(deer>1) deernotkill=(deer*(deer-1))/2 /total;
//    }
    if(tiger>1)
    {
        ret+=tt*prob(tiger-2,deer);
    }
    return ret;
    
//    return Ret=ret/(notEaten?notEaten:1);
    
}
    


    




int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);

    int test,cases=1;
    double tiger,deer;
    scan(test);
    while(test--){
        for (int  i = 0; i < 1001; i++) {
            for (int  j = 0; j < 1001; j++) {
                dp[i][j]=-1;
            }
        }
        
        scanf("%lf%lf",&tiger,&deer);
        double p=prob(tiger,deer);
        printf("Case %d: %.10lf\n",cases++,p);
    }





    return 0;
}
