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

iii ht(iii h)
{
    iii one=1;
    return (one<<(h+1))-1;
}

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    iii h,n;
    cin>>h>>n;
    iii one=1;

    iii visited=0;
    char ch='R';
    while(n>0){
        iii leaf=(one<<h);
        if(n>leaf/2)
        {
            if(ch=='R') 
            {
                visited+=ht(h-1)+1;
                n-=(one<<(h-1));
            }
            else 
            {
                visited++;
                n-=one<<(h-1);
            }
            ch='R';
        }
        else
        {
            if(ch=='L')
            {
                visited+=ht(h-1)+1;
            }
            else visited++;
            ch='L';
        }
        h--;
    }
    cout<<visited-1<<endl;





    return 0;
}
