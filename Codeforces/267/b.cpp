/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:  cf b
 *
 *        Version:  1.0
 *        Created:  বৃহস্পতিবার 18 সেপ্টে 2014 09:38:36  BDT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shadow_Crawler (Zim), triplemzim@gmail.com
 *        Company:  BUET
 *
 * =====================================================================================
 */

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
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))



int main()
{
    freopen("in.txt","r",stdin);
    
    
    int n,m,k;
    int x[1010];
    cin>>n>>m>>k;
    for (int  i = 0; i < m; i++) {
        cin>>x[i];
    }
    int f,count=0,ans=0;
    cin>>f;

    for (int  i = 0; i < m; i++) {
        count=0;
        for (int  j = 0; j < n; j++) {
            if(check(x[i],j)!=check(f,j))
            {
                count++;
            }

        }
        if(count<=k) ans++;
    }

    cout<<ans<<endl;


    return 0;
}
