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


    int knw[4444][4444]={0};
int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n,m;

    vector<int> v[4444];

    scan(n);
    scan(m);

    int a,b,count,c,x,y,z;
    int cn[500000]={0};

    for(int i=0;i<m;i++){
        scan(a);
        scan(b);
        v[a].pb(b);
        cn[a]++;
        cn[b]++;
        knw[a][b]=1;
        knw[b][a]=1;
    }

    count=500000000;
    c=-1;

    for(x=1;x<=n;x++){
        for(int j=0;j<(int)v[x].size();j++){
            y=v[x][j];
            for(int k=0;k<(int)v[y].size();k++){
                z=v[y][k];
                if(knw[z][x]){

                    int sz=cn[x]+cn[y]+cn[z]-6;

                    if(knw[x][y] && knw[y][z] && knw[z][x] && sz<count){
                        a=x;
                        b=y;
                        c=z;
    //                    tripb=y;
    //                    tripc=z;
                        count=sz;
                    }
                }

            }
        }
    }

//    cout<<endl;
//    cout<<a<<' '<<b<<' '<<c<<endl;

    if(c==-1){
        cout<<-1<<endl;
    }
    else cout<<count<<endl;
                



    



    return 0;
}

