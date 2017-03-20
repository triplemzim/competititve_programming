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

int rem,n,m;
bool grid[1002][1002];
bool chk(int x,int y){
    if(x<1|| y<1 || x>n || y>m ) return false;
    return true;
}

bool check(int x,int y){
    if(chk(x-1,y) && grid[x-1][y]){
        if(chk(x-1,y-1) && chk(x,y-1))
        {
            if(grid[x-1][y-1]==true && grid[x][y-1]==true) return true;
        }
        if(chk(x-1,y+1) && chk(x,y+1)){
            if(grid[x-1][y+1] && grid[x][y+1]) return true;
        }
    }
    if(chk(x+1,y) && grid[x+1][y]){
        if(chk(x+1,y-1) && chk(x,y-1)){
            if(grid[x+1][y-1] && grid[x][y-1]) return true;
        }
        if(chk(x+1,y+1) && chk(x,y+1)){
            if(grid[x+1][y+1] && grid[x][y+1]) return true;
        }
    }
    return false;
}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int k,x,y;
    cin>>n>>m>>k;
    bool flag=false;

    for (int  i = 0; i < k; i++) {
        cin>>x>>y;
        grid[x][y]=true;
        if(check(x,y)==true)
        {
           if(flag==false){ 
               rem=i+1;
           }
            flag=true;
        }
    }
    cout<<rem<<endl;



    return 0;
}
