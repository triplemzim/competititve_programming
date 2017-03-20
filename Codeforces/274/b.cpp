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

    pair<int,int> p[1000];

    int n,k;
    cin>>n>>k;

    int temp;
    for (int  i = 0; i < n; i++) {
        cin>>temp;
        p[i]=MP(temp,i+1);
    }
    
    vector<pair<int,int> > v;

    for(int i=0;i<k;i++)
    {
        sort(p,p+n);
        pair<int,int> a,b;
        a=p[0];
        b=p[n-1];

        if(b.first-a.first<=1)
        {
            break;
        }
        
        a.first+=1;
        b.first-=1;
        p[0]=a;
        p[n-1]=b;
        v.pb(MP(b.second,a.second));
    }
    sort(p,p+n);
    cout<<p[n-1].first-p[0].first<<' ';
    cout<<v.size()<<endl;
    for(int i=0;i<(int)v.size();i++)
    {
        cout<<v[i].first<<' '<<v[i].second<<endl;
    }


    


        



    return 0;
}
