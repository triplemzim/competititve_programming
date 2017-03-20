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

    scan(cases);
    int q[25],f[25],hisheb[25];
    bool track[25][25];

    while(cases--){
        int n,m;
        scan(n);
        scan(m);

        ms(track,false);
        ms(f,0);
        ms(q,0);
        ms(hisheb,0);

        for(int i=1;i<=n;i++){
            q[i]=i;
        }
        iii time=0;
        int count=n*m;
        int ferry=1,len=n;

        while(count){
            time+=5;
            if(f[ferry]!=0){
                if(hisheb[f[ferry]]<m){
                    q[len+1]=f[ferry];
                    len++;
                }
                f[ferry]=0;

            }
            for(int i=1;i<=len;i++){
                if(track[q[i]][ferry]==false){
                    count--;
                    hisheb[q[i]]++;
                    f[ferry]=q[i];
                    track[q[i]][ferry]=true;
                    for(int j=i;j<len;j++){
                        q[j]=q[j+1];
                    }
                    q[len]=0;
                    len--;
                    break;
                }
            }
            ferry++;
            if(ferry>m) ferry=1;
        }
        printf("Case %d: %lld\n",caseno++,time+m*5);
    }




        








    return 0;
}
                
