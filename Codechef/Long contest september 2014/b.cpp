#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
#define printL(x) printf("%lld\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vector<int>
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

iii modulo(iii n,iii m)
{
    if(n>=0) return n%m;
    else return (n%m+m)%m;
}

int main()
{
//    freopen("in.txt","r",stdin);
    
    
    int n,Q,num[100009];
    scan(n);
    scan(Q);
    for (int  i = 0; i < n; i++) {
        scan(num[i]);
    }

    char ch;
    int d,in=0;
    while(Q--)
    {
        
        scanf(" %c %d",&ch,&d);
        if(ch=='R')
        {
            print(num[modulo((d-in-1),n)]);
        }
        else if(ch=='A')
        {
            in=modulo(in+d,n);
        }
        else in=modulo(in-d,n);
        
//        debug(in);

    }






    return 0;
}
