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

int n,q,num[MAXN],tree[MAXN*3];

void build(int cur,int b,int e)
{
    if(b==e) 
    {
        tree[cur]=num[b];
        return;
    }
    int left=cur*2,right=cur*2+1,mid=(b+e)/2;

    build(left,b,mid);
    build(right,mid+1,e);
    tree[cur]=min(tree[left],tree[right]);
}

int query(int l,int r,int b,int e,int cur)
{
    if(b<=l && r<=e) return tree[cur];
    if( b>r || l>e) return inf;

    int left=cur*2,right=cur*2+1,mid=(l+r)/2;

    int a=query(l,mid,b,e,left),B=query(mid+1,r,b,e,right);
    
    return min(a,B);
}
    


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases,caseno=1,a,b;
    scan(cases);

    while(cases--)
    {
        scan(n);
        scan(q);


        for (int  i = 1; i < n+1; i++) {
            scan(num[i]);
        }
        build(1,1,n);


        printf("Case %d:\n",caseno++);
        for (int  i = 0; i < q; i++) {
            scan(a);
            scan(b);
            print(query(1,n,a,b,1));
        }
    }

    return 0;
}
