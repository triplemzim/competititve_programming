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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    pair<int,int> left[100009],right[100009];

    int l=0,r=0;

    int n;

    scan(n);

    int a,b;

    for (int  i = 0; i < n; i++) {
        scan(a);
        scan(b);
        if(a<0){
            left[l++]=MP(a,b);
        }
        else right[r++]=MP(a,-b);
    }

    sort(left,left+l);
    sort(right,right+r);
    int takeL,takeR;

    if(l==r){
        takeL=l;
        takeR=r;
    }
    else if(l<r){
        takeL=l;
        takeR=l+1;
    }
    else{
        takeL=r+1;
        takeR=r;
    }


    iii val=0;
    for(int i=0;i<takeR;i++){
        val+=-right[i].second;
    }
    for(int i=l-1;takeL-- && i>=0;i--){
        val+=left[i].second;
    }

    cout<<val<<endl;




    return 0;
}
