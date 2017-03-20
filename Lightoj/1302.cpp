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

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}



char ch[100];
iii dp[100][100];



iii calc(int st,int fin)
{
    if(dp[st][fin]!=-1) return dp[st][fin];
    if(fin-st<2) return dp[st][fin]=(iii)1;
    if(fin-st==2){
        if(ch[st]+ch[st+1]+ch[fin]<'B'+'R'+'R'){
            return dp[st][fin]=(iii)1;
        }
        return dp[st][fin]=0;
    }


    iii sum=0;
    int b=0,r=0;
    for(int i=st;i<=st;i++){
        if(ch[i]=='B') b++;
        else r++;
        for(int j=i+1;j<=fin;j+=3){
            if(ch[j]=='B') b++;
            else r++;
            for(int k=j+1;k<=fin;k+=3){
                if(ch[k]=='B') b++;
                else r++;
                if(r<2){ 
                    sum+=calc(i+1,j-1)*calc(j+1,k-1)*calc(k+1,fin);
                }
                if(ch[k]=='B') b--;
                else r--;
            }
            if(ch[j]=='B') b--;
            else r--;

        }
        if(ch[i]=='B') b--;
        else r--;
    }

    return dp[st][fin]=sum;
}







int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases,caseno=1;

    scan(cases);
    getchar();
    ms(dp,-1);


    while(cases--){
        ms(dp,-1);
        scanf("%s",ch);
        
        printf("Case %d: %lld\n",caseno++,calc(0,strlen(ch)-1));



    }


              





    return 0;
}

