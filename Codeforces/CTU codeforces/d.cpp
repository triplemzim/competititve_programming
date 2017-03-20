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


int r,c,sx,sy,tx,ty;


bool chk(int x,int y)
{
    if(x<1 || x>r || y<1 || y>c ) return false;
    return true;
}




void bfs()
{
    queue<PII >q;
    int dist[101][101]={0};

    bool color[101][101]={false};

    PII top;

    int fx[]={-2,-1,1,2,2,1,-1,-2};
    int fy[]={1,2,2,1,-1,-2,-2,-1};

    q.push(MP(sx,sy));
    color[sx][sy]=true;

    while(!q.empty()){
        top=q.front();
        q.pop();
        int u=top.first,v=top.second,tempx,tempy;


        if(tx==u && ty==v){
            printf("%d\n",dist[u][v]);
            return;
        }
        for(int i=0;i<8;i++){
            tempx=u+fx[i];
            tempy=v+fy[i];

            if(chk(tempx,tempy)==true){
                if(color[tempx][tempy]==false){
                    color[tempx][tempy]=true;
                    q.push(MP(tempx,tempy));
                    dist[tempx][tempy]=dist[u][v]+1;
                }
            }
        }
    }
    cout<<"impossible"<<endl;
}












int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

        
    while(scanf("%d %d %d %d %d %d",&r,&c,&sx,&sy,&tx,&ty)!=EOF){
        bfs();
    }



    return 0;
}

