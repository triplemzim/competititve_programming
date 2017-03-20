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
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))



int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);
	  freopen("out.txt","w",stdout);

    int cases,caseno=1;
    int n,gp,gc,gf,p[25],c[25],f[25];
    scan(cases);
    while(cases--)
    {
        scan(gp);
        scan(gc);
        scan(gf);
        scan(n);
        for (int  i = 0; i < n; i++) {
            scan(p[i]);
            scan(c[i]);
            scan(f[i]);
        }
        int bitmask=0;
        int temp_p,temp_c,temp_f;
        bool flag=false;

        while(bitmask<=(1<<20))
        {
            temp_p=temp_c=temp_f=0;
            for(int i=0;i<20;i++){
                if(check(bitmask,i)==true)
                {
                    temp_p+=p[i];
                    temp_c+=c[i];
                    temp_f+=f[i];
                }
            }
            if(temp_p==gp && temp_c==gc && temp_f==gf){
                flag=true;
                break;
            }
            bitmask+=1;
        }
        if(flag) printf("Case #%d: yes\n",caseno++);
        else printf("Case #%d: no\n",caseno++);
    }




    return 0;
}
