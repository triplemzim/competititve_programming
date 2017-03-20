#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define printc(x) printf("x\n")
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
inline iii power(iii base,iii p) { iii answer=1; while(p>0) answer*=base,p-=1; return answer;}


iii coin[20];
vector<iii> perm1,perm2;


bool bsearch(int a,int b,int val)
{
    if(a>=b) return false;

    int mid=(a+b)/2;
    if(perm1[mid]>val)
    {
        bsearch(mid,b,val);
    }
    else if( perm1[mid]<val)
    {
        bsearch(a,mid,val);
    }
    else return true;
}



int main()
{
//    freopen("in.txt","r",stdin);
    
    
    map<iii,bool> mp;
    iii cases,caseno=1,n,k,lim,f1,f2;
    scan(cases);
    while(cases--)
    {
        scanf("%lld %lld",&n,&k);
        perm1.pb(0);
        perm2.pb(0);
        mp[0]=true;

        for (int  i = 0; i < n; i++) {
            scanf("%lld",&coin[i]);
        }
                    
        
//        printc(perm1);
        lim=1;
        for (int  i = 0; i < n/2; i++) {
            for (int  j = 0; j < lim; j++) {
                perm1.pb(perm1[j]+coin[i]);
                perm1.pb(perm1[j]+2*coin[i]);
//                debug(perm1[j]+coin[i]);
            }
            lim*=3;
//            for (int  j = 0; j < lim; j++) {
//                perm1.pb(perm1[j]+coin[i]);
////                debug(perm1[j]+coin[i]);
//            }
//            lim<<=1;
        }
        lim=1;
        for(int i=n/2;i<n;i++)
        {
            for (int  j = 0; j < lim; j++) {
                perm2.pb(perm2[j]+coin[i]);
                perm2.pb(perm2[j]+2*coin[i]);
                mp[perm2[j]+coin[i]]=true;
                mp[perm2[j]+2*coin[i]]=true;
            }
            lim*=3;
//            for (int  j = 0; j < lim; j++) {
//                perm2.pb(perm2[j]+coin[i]);
//                mp[perm2[j]+coin[i]]=true;
//            }
//            lim<<=1;
        }
//        sort(perm1.begin(),perm1.end());

        lim=perm1.size();
        bool flag=false;
        for(int i=0;i<lim;i++)
        {
            if(mp.find(k-perm1[i])!=mp.end()) 
            {
                flag=true;
                break;
            }
        }



        if(flag)
        {
            printf("Case %d: Yes\n",caseno++);
        }
        else
            printf("Case %d: No\n",caseno++);


        perm1.clear();
        mp.clear();
        perm2.clear();


       

    }
    
    return 0;
}
