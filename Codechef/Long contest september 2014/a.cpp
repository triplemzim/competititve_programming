#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
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


int main()
{
//    freopen("in.txt","r",stdin);
    
    
    int cases;
    string st;
    scan(cases);
    iii num;
    while(cases--)
    {
        cin>>st;
        int len=st.length();
        num=1;
        bool flag=true;

        for (int  i = 0; i < len; i++) {
            if(st[i]=='l')
            {
                if(flag)
                {
                    num<<=1;
                }
                else
                {
                    num=(num<<1)-1;
                }
                num%=MOD;
            }
            else
            {
                if(flag) num=(num<<1)+2;
                else num=(num<<1)+1;
            }
            num%=MOD;
            flag=!flag;
        }
        printf("%lld\n",num%MOD);
    }






    return 0;
}
