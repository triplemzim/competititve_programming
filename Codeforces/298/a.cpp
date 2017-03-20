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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

   int n;
    scan(n);
    
    if(n==2){
        cout<<1<<endl;
        cout<<1<<endl;
        return 0;
    }
    else if(n==3){
        cout<<2<<endl;
        cout<<1<<' '<<3<<endl;
        return 0;
    }
    else if(n==4) {
        cout<<4<<endl;
        cout<<3<<' '<<1<<' '<<4<<' '<<2<<endl;
        return 0;
    }
    cout<<n<<endl;
     
    int i=1;
    for(;i<=n;i+=2){
        cout<<i<<' ';
    }
    i-=2;
    if(abs(i-2)>1){
        for(i=2;i<=n;i+=2){
            cout<<i<<' ';
        }
    }



    return 0;
}
