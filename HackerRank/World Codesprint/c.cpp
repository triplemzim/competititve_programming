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



int n,m;
vector<string> v;

bool chk(int a,int b,int c,int d,int len){
    if(a<0 || b<0 || a>=n || b>=m) return false;    
    if(v[a][b]=='B') return false;
    if(b==d){
        if(a>=c-len && a<=c+len) return false;
    }
    if(a==c){
        if(b>=d-len && b<=d+len) return false;
    }
    return true;
}



int calc(int x,int y,int tx,int ty,int len)
{
    int count=0;
    int i=1;

    while(true){
        if(chk(x+i,y,tx,ty,len) && chk(x-i,y,tx,ty,len) && chk(x,y+i,tx,ty,len) && chk(x,y-i,tx,ty,len)){
           i++;
          count++; 
        }
        else break;
    }
    return count;
}
            


        




int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    string st;
    
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>st;
        v.pb(st);
    }

    int len;
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j]=='G'){
                len=calc(i,j,-1,-1,0);
                for(int l=0;l<=len;l++){
                    for(int a=0;a<n;a++){
                        for(int b=0;b<m;b++){
                            if(v[a][b]=='G' && (i!=a && j!=b)){
                                int temp=calc(a,b,i,j,l);
//                                cout<<i<<' '<<j<<' '<<a<<' '<<b<<' '<<l<<' '<<temp<<endl;
                                ans=max(ans,(4*l+1)*(4*temp+1));
                            }
                        }
                    }
                }
            }
        }
    }


    cout<<ans<<endl;



    


    







    



    return 0;
}

