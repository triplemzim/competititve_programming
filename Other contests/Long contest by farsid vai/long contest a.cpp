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
	  freopen("in.txt","r",stdin);

    int test,cases=1;
    int n;
    iii x,y;
    pair<iii,iii> p[1009],temp;
    map< pair<iii,iii>, int> mp;
    vector< pair<iii,iii> > v;

    cin>>test;

    while(test--){
        mp.clear();
        v.clear();
        cin>>n;
        iii count,c;
        count=0;
        for (int  i = 0; i < n; i++) {
            scanf("%lld%lld",&x,&y);
            p[i]=MP(x,y);
        }

        for (int  i = 0; i < n; i++) {
            for (int  j = i+1; j < n; j++) {
                temp=MP(p[i].first+p[j].first,p[i].second+p[j].second);
                v.pb(temp);
            }
        }
        sort(v.begin(),v.end());

        for(int i=0;i<(int)v.size()-1;){
            c=0;
            for(int j=i+1;j<(int)v.size();j++){
                if(v[i]==v[j]) i=j,c+=1;
                else
                {
                    i=j;
                    break;
                }
            }
            count+=(c*(c+1))/2;
        }

                
        printf("Case %d: %lld\n",cases++,count);
    }


    return 0;
}
