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

struct data{
    int a,b;
    bool operator<(const data &x)const
    {
        if(a<x.a) return true;
        else if(a==x.a && b<x.b) return true;
        return false;
    }
};

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    data d[5010];

    int n;
    cin>>n;
    for (int  i = 0; i < n; i++) {
        cin>>d[i].a>>d[i].b;
    }

    sort(d,d+n);

    int mn=-1;

    for(int i=0;i<n;i++)
    {
        if(d[i].b>=mn)
        {
            mn=d[i].b;
        }
        else mn=d[i].a;
    }

    cout<<mn<<endl;
    



    return 0;
}
