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
iii M;
iii mul(iii x)
{
    if(x<1) return 0;
    iii ans=9;
    x--;
    while(x--){
        ans*=10;
        ans%=M;
    }

      return ans;
}
iii numof(int k)
{
    int a=0;
    while(k){
        k/=10;
        a++;
    }
    return a;
}

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    
    iii n,k;
    cin>>n>>k>>M;

    iii ans=0;
    ans=0;
    map<iii,bool> mp;
    iii div,lim;
    if(k<10)
    {
        div=10;
        lim=101;
    }
    else if(k<100)
    {
        div=100;
        lim=1001;
    }
    else if(k==100)
    {
        div=1000;
        lim=10001;
    }

    for(int i=1;i<lim;i++)
    {
        int x=10;
        iii temp=k*i;

        bool flag=false;

        while(x<=div){
            if(mp.find(temp%x)!=mp.end()) 
            {
//                cout<<temp<<' ';
                flag=true;
                break;
            }
            x*=10;
        }
        if(flag) continue;
        temp=k*i;

        ans+=mul(n-numof(temp));
        if(n==numof(temp)) ans++;
//        cout<<temp<<' '<<ans<<endl;
        mp[temp]=true;
    }






    cout<<ans%M<<endl;
    return 0;
}
