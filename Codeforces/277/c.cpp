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

    char ch[1000009];
    int n,pos;
    cin>>n>>pos;
    getchar();

    scanf("%s",ch+1);

    vector<int> v;
    int count=0;
    for(int i=1;i<=n/2;i++)
    {
        if(ch[i]!=ch[n-i+1])
        {
            v.pb(i);
            int ab=absolute((int)ch[i]-(int)ch[n-i+1]);
            count+=min(ab,26-ab);

        }
    }
        int m1=0,m2=0;
    
    if(v.size())
    {
        int mn=v[0];
        int mx=max(mn,n-mn+1);
        int md=v[v.size()-1];
        int highmid=n-md+1;
        if(pos>=md)
        {
            m2=absolute(mx-highmid);
            m2+=min(absolute(pos-highmid),absolute(mx-pos));
        }
        else 
        {
            m2=mx-pos;
        }
        m1=m2;
        if(pos<=md)
        {
            m2=md-mn;
            m2+=min(absolute(pos-md),pos-mn);
        }
        else m2=pos-mn;
        m1=min(m1,m2);

    }
                    
//        cout<<mn<<' '<<md<<' '<<mx<<endl;
//        
//        m1=absolute(mx-pos)+(pos>md && n-md+1<pos ?mx-md:0);
//        m2=pos<md? mx-pos : pos-md+mx-md;
//        cout<<"boro age: "<<m1<<' '<<"majhe boro: "<<m2<<endl;
//        m1=min(m1,m2);
//        m2=pos>md? pos-mn: pos-mn+md-mn;
////        cout<<"coto age: "<<m2<<' ';
//        m1=min(m1,m2);
//        m2=pos>md? pos-mn : md-pos+md-mn;
////        cout<<"majhe coto: "<<m2<<' '<<endl;
//        m1=min(m1,m2);
    cout<<m1+count<<endl;
        
      






    return 0;
}
