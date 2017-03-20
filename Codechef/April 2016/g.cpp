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
#define printv(vec) for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';cout<<endl;
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



int n;
vector<int> g[100009];
vector<int> cost[100009];

iii dfs(int u,int p)
{
	int v,val;
	vector<pair<iii,iii> > temp;
	pair<iii,iii> mn,pr,root,ans;
	for(int i = 0; i<g[u].size();i++){
		v = v[u][i];
		if(v==p) continue;
		val = dfs(v,u);
		temp.pb(val,cost[u][i]);

	}
	sort(temp.begin(),temp.end());
	int len = temp.size();
	iii mx=0;

	for(int i=1;i<temp.size();i++){
		pr = temp[i];











int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

	int t;
	
	scan(n);

	for(int i=1;i<n;i++){
		scanf("%d %d %d",&a,&b,&w);
		g[a].pb(b);
		g[b].pb(a);
		cost[a].pb(w);
		cost[b].pb(w);
	}

	dfs(1,0);



		



	return 0;
}

