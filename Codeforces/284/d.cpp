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
int n,T;
double p[5002];
int t[5002];
int d=0;
double calc(int sec,int num)
{
    if(sec>=T || num>=n) {
        return (double)num;
    }
    double temp,sum=0,x=1;
    int tt=sec;

    sec++;
    while(sec<=T && sec<=t[num]+tt)
    {
//        cout<<num<<' '; 
        x*=p[num];
        if(sec==t[num]+tt)
        {
            temp=calc(sec,num+1);
//            if(num==0) cout<<"sec: "<<sec<<' '<<num+1<<' '<<temp<<endl;
//            if(num==1) cout<<"sec: "<<sec<<' '<<"temp: "<<temp<<endl;
        }
        else 
        {
//            cout<<"sec: "<<sec<<endl;            
            temp=x*calc(sec,num+1);
            if(num==0) cout<<calc(sec,num+1)<<endl;
        }
//        if(num==0) cout<<"temp: "<<temp<<endl;
        sum+=temp;
        sec++;
    }
    return sum;
    
}

int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);
    cin>>n>>T;

    double a,b;
    for (int  i = 0; i < n; i++) {
        cin>>a>>b;
        p[i]=a/(100.0);
        t[i]=b;
    }
    cout<<calc(0,0)<<endl;




    return 0;
}
