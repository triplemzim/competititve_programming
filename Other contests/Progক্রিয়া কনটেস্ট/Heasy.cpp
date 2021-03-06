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

iii node,cap,capacity[55][55],a,b;
vector<int>v[55];

iii cal(int src,int target){
    bool color[55]={false};
    queue<int>q;
    int top;
    iii temp_c[55]={0};
    q.push(src);
    temp_c[src]=10000009;
    color[src]=true;
    while(!q.empty()){
        top=q.front();
        q.pop();
        for(int i=0;i<(int)v[top].size();i++){
            int go=v[top][i];
            if(color[go]==true) continue;
            color[go]=true;
            temp_c[go]=min(capacity[top][go],temp_c[top]);
            q.push(go);
            if(go==target) return temp_c[target];
        }
    }
    return temp_c[target];
}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases;
    

    scan(cases);
    while(cases--){
        for(int i=0;i<55;i++) v[i].clear();
        cin>>node;
        for (int  i = 0; i < node-1; i++) {
            cin>>a>>b>>cap;
            v[a].pb(b);
            v[b].pb(a);
            capacity[a][b]=capacity[b][a]=cap;
        }

        iii sum=0;
        for(int i=1;i<=node;i++){
            for(int j=i+1;j<=node;j++){
                sum+=cal(i,j);
            }
        }
        cout<<sum*(iii)2<<endl;
    }



    return 0;
}
