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

long long bigMod(long long b, long long p, long long m)
{
    long long tmp = b, r = 1;
    while(p > 0)
    {
        if(p%2==1)
        {
            r = (r*tmp)%m;
        }   
        p/=2;
        tmp  = (tmp*tmp)%m;
    }
    return r;
}
 
bool rabin(long long p, int iteration)
{
    if(p<2)
        return false;
        
    if(p!=2 && p%2==0)
        return false;
    
    long long s = p-1;
    int cnt = 0;
    
    while(s%2==0)
    {
        cnt++;
        s/=2;
    }
    for(int i = 0; i < iteration; ++i)
    {
        long long a = rand()%(p-1)+1;   
        unsigned long long mod;
    
        mod = bigMod(a,s,p);
        
        if(mod==1 || mod==p-1)
            continue;
    
        for(int j = 1; j < cnt; ++j)
        {
            mod = (mod*mod)%p;
            if(mod==p-1)
                break;   
        }
    
        if(mod!=p-1)
            return false;
    }
    return true;
}

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n;
    cin>>n;
    vector<int>ans;


    if(n==3){
        cout<<1<<endl<<3<<endl;
        return 0;
    }
    

    n-=3;
    ans.pb(3);
    if(n<3) ans.pb(2);
    if(n==4){
        ans.pb(2);
        ans.pb(2);
    }

    for(int i=n-1;i>1;i-=2){
        if(rabin(i,10)==true && ( rabin(n-i,10))==true){
            ans.pb(i);
            if(n-i) ans.pb(n-i);
            break;
        }
    }
    


    




    cout<<ans.size()<<endl;
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<' ';
    }
    cout<<endl;
    



    return 0;
}

