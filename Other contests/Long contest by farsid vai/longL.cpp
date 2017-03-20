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

iii comb(iii x)
{
    if(x<=2) return 0;
    return (x*(x-1)*(x-2))/6;
}


iii calc(iii m,iii n)
{
    cout<<"calc starts"<<endl;
    iii count=0,temp;
    iii ax=0,bx=0;
    cout<<m<<endl;

    for(iii i=1;i<=(m+1)/2;i++){
        cout<<i<<": ";
        ax=1;bx=i;
        temp=0;
        while(ax<m+n && bx >0)
        {
            iii sq=(bx)/i;
            if(bx<=m) sq++;
            cout<<sq<<' ';
            temp+=comb(sq);
            ax++;
            if(bx<m && ax<=n) bx+=i;
            if(ax>n) bx-=i;
        }
        if(m%i==0) count+=temp*2;
        else count+=temp*4;
        cout<<endl;
    }
    cout<<"count: "<<count<<endl;
    temp=(n+1)*comb(m+1)+(m+1)*comb(n+1);
    cout<<"temp: "<<temp<<endl;


            
    cout<<"calc ends"<<endl;
    return count+temp;
}
        


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases=1;
    iii m,n;
    while(scanf("%lld%lld",&n,&m)!=EOF){
        if(!m && !n) return 0;

        cout<<comb((m+1)*(n+1))<<endl;
        calc(m,n);
        
        iii count=0;
        iii temp=0;
        iii point=((m+1)*(n+1))-1;

        for(iii i=0;i<m;i++){
            temp=0;
            iii t=0;
            for(iii j=0;j<=n;j++){
                temp=0;
                temp+=comb(point);
//                cout<<temp<<endl;
                if(m-i>1) temp-=comb(m-i);
                if(n-j>1) temp-=comb(n-j);
                int mn=min(m-i,n-j);
                if(mn>1) temp-=comb(mn);
                mn=min(j,m-i);
                if(mn>1) temp-=comb(mn);
                point--;
//                cout<<temp<<endl;
                t+=temp;
            }
            count+=t;
        }
        printf("Case %d: ",cases++);
        cout<<count<<endl;

    }
        
    return 0;
}   
