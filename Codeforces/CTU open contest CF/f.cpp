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
#define MOD 10000000000 // 10^10

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


int n;
unsigned long long dp[1001][1001];
string st;

void calc()
{
    if(st[n]=='(') {
        cout<<0<<endl;
        return;
    }
    ms(dp,0);
    int five=0;
    dp[n][1]=1;
    int lim=(n+1)/2;
    int count=0;

    
    for(int i=n-1;i>=0;i--){
        if(st[i]!='.'){
            count++;
            if(st[i]=='('){
                for(int j=0;j<=n-i;j++){
                    five=n-i-j;
                    if(five<lim && five>-1 && five<j){ 
                        dp[i][j]=dp[i+1][j];
                        dp[i][j]%=MOD;
                    }
                }
            }
            else{
                for(int j=0;j<=n-i;j++){
                    if(j<lim){
                        dp[i][j+1]=dp[i+1][j];
                        dp[i][j+1]%=MOD;
                    }
                }
            }
            continue;
        }
        for(int j=0;j<=n-i;j++){
            five=n-i-j;
                
            if(five<j && five<=lim && five>-1){
                dp[i][j]+=dp[i+1][j];
            }
            if(j<lim && j>=five){
                dp[i][j+1]+=dp[i+1][j];
            }
            dp[i][j]%=MOD;
            dp[i][j+1]%=MOD;
        }
    }
//    for(int i=0;i<=n;i++){
//        for(int j=0;j<=n;j++){
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//    }

    unsigned long long ans=0;

    for(int i=0;i<=lim;i++){
        ans+=dp[0][i];
        ans%=MOD;
    }
    if(count>=n && ans==1){
        cout<<0<<endl;
        return;
    }
    cout<<ans%1000000<<endl;

}



int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    

    while(cin>>st){
        n=st.length()-1;
            
        calc();
    }



    return 0;
}

