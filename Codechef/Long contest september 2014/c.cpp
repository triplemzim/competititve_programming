#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
#define printL(x) printf("%lld\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vector<int>
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

iii bigMod(iii base,iii power)
{
    if(power==1) return base%MOD;
    if(power==0) return 1;

    if(power%2==1) return (bigMod(base,power-1)*(base%MOD))%MOD;
    else{
        iii temp=bigMod(base,power/2)%MOD;
        return (temp*temp)%MOD;
    }
}


int main()
{
    int n;
//    cout<<bigMod(7,(1000000-13)/2)<<endl;
    scan(n);
    iii ans;
    if(n<13) ans=0;
    else
    {
        n-=13;
        int pr=n>>1;
        iii temp=1;
        for (int  i = 1; i < pr+1; i++) {
            temp=(temp*7)%MOD;
        }
        ans=(n<2?1:temp);
    }

    printf("%lld\n",ans);
                          



    return 0;
}
