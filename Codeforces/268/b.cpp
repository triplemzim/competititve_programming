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


int main()
{
//    freopen("in.txt","r",stdin);
    
    
    int P,q,l,r,a,b;
    bool sz[1010]={false};
    pair<int,int>  p[1010];
    cin>>P>>q>>l>>r;

    for (int  i = 0; i < P; i++) {
        cin>>a>>b;
        for(int j=a;j<=b;j++) sz[j]=true;
    }
    for (int  i = 0; i < q; i++) {
        cin>>a>>b;
        p[i]=MP(a,b);
    }
    bool flag;
    int count=0;
    for(int i=l;i<=r;i++)
    {
        flag=false;
        for(int j=0;j<q;j++)
        {
            a=p[j].first;b=p[j].second;
            for(int k=a;k<=b;k++)
            {
                if(k+i<1001 && sz[k+i]==true)
                {
                    flag=true;
                    count++;
                    break;
                }
            }
            if(flag) break;
        }
    }
    cout<<count<<endl;

    


    return 0;
}
