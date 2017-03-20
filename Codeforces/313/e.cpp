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

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}

template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

#define clim 200002
iii fact[clim],inv[clim];
iii MOD= 1000000007; // 10^9 + 7

void Combinations()
{
	fact[0]=1;
	for(iii i=1;i<clim;i++){
		fact[i]=(i*fact[i-1])%MOD;
	}
}

void modInverses()
{
	inv[0]=1;
	
	for(iii i=1;i<clim;i++){
		inv[i]=(inv[i-1]*modinverse(i,MOD))%MOD;
	}
}

iii Calculate(int x, int y)
{
	return ((fact[x+y]*inv[x])%MOD*inv[y])%MOD;
}


iii path_from_base[2009];

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    Combinations();
    modInverses();

    int h,w,n;
    pair<int,int> p[2009];
   
    scan(h);
    scan(w);
    scan(n);

    for(int i=0;i<n;i++){
        scan(p[i].first);
        scan(p[i].second);
    }

    sort(p,p+n);

    for(int i=0;i<n;i++){
        path_from_base[i]=Calculate(p[i].first-1,p[i].second-1);
    }
    iii temp,x,y,exclude=0;

    for (int  i = 0; i < n; i++) {
        for (int  j = i+1; j < n; j++) {
            x=p[j].first-p[i].first;
            y=p[j].second-p[i].second;

            if(x>-1 && y>-1){
                temp=Calculate(x,y);
                path_from_base[j]-= (path_from_base[i]*temp)%MOD;
                while(path_from_base[j]<0){
                    path_from_base[j]+=MOD;
                }
                path_from_base[j]%=MOD;
            }
        }
        exclude+=(path_from_base[i]*Calculate(h-p[i].first,w-p[i].second))%MOD;
        exclude%=MOD;
    }


    iii ans=Calculate(h-1,w-1);
    ans-=exclude;
    while(ans<0){
        ans+=MOD;
    }
    cout<<ans%MOD<<endl;





            

    

    



    return 0;
}               
