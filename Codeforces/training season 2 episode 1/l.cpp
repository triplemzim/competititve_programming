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

struct cow{
    iii total,idx;
    iii we;
    bool operator<(const cow a)const {return total<a.total; }
};

int main()
{
//    freopen("in.txt","r",stdin);
    
    
    iii n,w[50009],s[50009];
    cin>>n;
    cow c[50009];
    iii sumW=0;
    for (int  i = 0; i < n; i++) {
        cin>>w[i]>>s[i];
        sumW+=w[i];
    }
    for (int  i = 0; i < n; i++) {
        c[i].total=sumW-w[i]-s[i];
        c[i].idx=i;
        c[i].we=w[i];
    }
    sort(c,c+n);

//    for (int  i = 0; i < n; i++) {
//        cout<<c[i].total<<endl;
//    }
    iii mx=-100000000000;

    iii val=0;
    for(int i=0;i<n;i++)
    {
        iii temp=c[i].total-val;
        val+=(c[i].we); 
        mx=max(mx,temp);
//        cout<<"temp: "<<temp<<endl;
    }

    cout<<mx<<endl;

    



    return 0;
}
