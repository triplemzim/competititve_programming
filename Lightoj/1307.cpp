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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases,caseno=1;

    int n;
    iii temp;

    vector<iii> num;
    
    scan(cases);

    while(cases--){
        scan(n);
        num.clear();

        for(int i=0;i<n;i++){
            scanf("%lld",&temp);
            num.pb(temp);
        }

        sort(num.begin(),num.end());

//        for(int i=0;i<n;i++){
//            cout<<num[i]<<' ';
//        }
//        cout<<endl;

        iii count=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
//                cout<<num[i]<<' '<<num[j]<<' ';
                iii val=num[i]+num[j];
                int pos=lower_bound(num.begin(),num.end(),val)-num.begin();
//                cout<<pos<<' '<<j<<endl;
//                if(pos<n){
                    if(pos-j-1>0){
                        count+=pos-j-1;
                    }
//                }
            }
        }

        printf("Case %d: %lld\n",caseno++,count);
    }
                





    return 0;
}

