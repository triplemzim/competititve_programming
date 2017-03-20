#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

using namespace std;

#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define printL(x) printf("%I64d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
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
#define MOD 1000000007 // 10^9 +7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

using namespace std ;

char s[2100], p[510] ;
int A[2100] ;
int D[2100][2100] ;

int main(void)
{
    freopen("in.txt","r",stdin);
    
    
    gets(s) ;
    gets(p) ;

    int Len_s = strlen(s) ;
    int Len_p = strlen(p) ;

    for(int i=0;i<Len_s;i++)
    {
        int ps = i ;
        int pp ;
        for(pp=0;pp<Len_p;pp++)
        {
            while(ps<Len_s && p[pp]!=s[ps])
                ps++ ;
            if(ps==Len_s)
                break ;
            else
                ps++ ;
        }
        if(pp==Len_p)
            A[i] = ps-i ;
        else
            A[i] = -1 ;
    }
    for(int i=0;i<Len_s;i++)
    {
        cout<<A[i]<<' ';
    }
    cout<<endl;

    for(int i=0;i<Len_s;i++)
    {
        for(int r=0;r<=i;r++)
        {
            D[i+1][r] = max(D[i+1][r], D[i][r]) ;
            D[i+1][r+1] = max(D[i+1][r+1], D[i][r]) ;
            if(A[i]>=0)
            {
                D[i+A[i]][r+A[i]-Len_p] = max(D[i+A[i]][r+A[i]-Len_p], D[i][r]+1) ;
            }
        }
    }

    printf("%d", D[Len_s][0]) ;
    for(int i=1;i<=Len_s;i++)
        printf(" %d", D[Len_s][i]) ;
    putchar('\n') ;

    return 0 ;
}
