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

iii fact[10000009],sum[10000009],num[100009];

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    iii n,m;
    cin>>n>>m;

    fact[0]=1;
    sum[0]=0;
    for(iii i=1;i<m;i++){
        fact[i]=fact[i-1]*i;
        fact[i]%=m;
    }

    for(iii i=1;i<m;i++){
        fact[i]*=i;
        fact[i]%=m;
//        cout<<fact[i]<<' ';
        sum[i]=sum[i-1]+fact[i];
        sum[i]%=m;
    }
    sum[m]=sum[m-1];

    for (int  i = 0; i < n; i++) {
        scanf("%lld",num+i);
    }

    iii ans=0,x,ANS=0;
    for(int i=0;i<n;i++){
        x=num[i];
        ans=x%m;
        if(x%2==0){
            ans*=(x>>1)%m;
            ans%=m;
            ans*=((x+1)%m);
            ans%=m;
        }
        else{
            ans*=((x+1)/2)%m;
            ans%=m;
            ans*=(x%m);
            ans%=m;
        }
        
        ANS+=(ans+sum[min(m,x)])%m;
        ANS%=m;
//        cout<<ans<<' '<<ans+sum[min(m,x)]<<endl;
    }
    cout<<ANS%m<<endl;






    return 0;
}
