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
#define MAXN 100009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n;
    vector<int> edge[MAXN];
 
    int XOR[MAXN],degree[MAXN];

    scan(n);
    queue<int>q;
    int a,b;


    for (int  i = 0; i < n; i++) {
        cin>>a>>b;
        XOR[i]=b;
        degree[i]=a;
        if(a==1){
            q.push(i);
        }
    }

    map<pair<int,int>, bool> mp;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        if(degree[top]<1) continue;
        degree[XOR[top]]-=1;
        XOR[XOR[top]]^=top;
        if(degree[XOR[top]]==1) {
            q.push(XOR[top]);
        }
        if(top!=XOR[top]&& degree[top]>0) edge[top].pb(XOR[top]);
    }
    vector<PII > v;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<(int)edge[i].size();j++)
        {
            if(mp.find(MP(i,edge[i][j]))==mp.end()) {
                v.pb(MP(i,edge[i][j]));
            }
            mp[MP(i,edge[i][j])]=mp[MP(edge[i][j],i)]=true;
        }
        
    }
    cout<<v.size()<<endl;
    for(int i=0;i<(int)v.size();i++){
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }
     




    return 0;
}
