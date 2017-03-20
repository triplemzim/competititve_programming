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
//    ios::sync_with_stdio(false);
//    freopen("in.txt","r",stdin);
    
    
    iii a[5];
    cin>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
//    cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
    iii table=0;
    iii dif;

    dif=a[2]-a[1];

    iii spare=dif/2;
    if(spare>=a[0])
    {
        table+=a[0];
        a[2]-=(a[0]*2);
        a[0]=0;
    }
    else
    {
        a[0]-=spare;
        table+=spare;
        a[2]-=(spare*2);
    }
    sort(a,a+3);

    dif=a[2]-a[1];
    while(a[1] && dif>1)
    {
        spare=dif/2;

        if(spare>=a[1])
        {
            table+=a[1];
            a[2]-=(a[1]*2);
            a[1]=0;
        }
        else
        {
            a[1]-=spare;
            table+=spare;
            a[2]-=spare*2;
        }
        sort(a,a+3);
        dif=a[2]-a[1];
    }
    
//    cout<<a[0]<<' '<<a[1]<<' '<<a[2]<<endl;
//    cout<<table<<endl;

    table+=a[0];
    a[1]-=a[0];
    a[2]-=a[0];
    a[0]=0;

    if(a[1]) table+=(a[1]+a[2])/3;

    a[2]=a[2]-a[1]+(a[1]%3);
    a[1]=a[1]-a[1]+(a[1]%3);

//    if(a[1]+a[2]>2 && a[1] && a[2]) table++;

    cout<<table<<endl;

    return 0;
}
