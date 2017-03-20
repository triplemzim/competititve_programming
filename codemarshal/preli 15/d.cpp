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

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

vector<int>v;
int len;

int* half(int num[])
{
    v.clear();


    int div=0;

    bool flag=false;
    for(int i=0;i<len;i++){
        div*=10;
        div+=num[i];
        if(div/2) flag=true;
        if(flag==false) continue;

        v.pb(div/2);
        div=div%2;
    }

    len=v.size();

    for(int i=v.size()-1;i>=0;i--){
        num[i]=v[i];
    }
    return num;
}





iii divide(int num[])
{

    iii div=0;
    iii dd=MOD-1;

    bool flag=false;
    for(int i=0;i<len;i++){
        div*=10;
        div+=num[i];
        if(div/dd) flag=true;
        if(flag==false) continue;

        div=div%dd;
    }

    return div;
}







iii bigMod(int pwr[])
{
    if(len==0 || (len==1 && pwr[0]==0)){
//    if(chk(pwr)==true){
        return 1;
    }


    iii ret=0;
    if(((pwr[len-1])&1) ==1){
//    if(chk_odd(pwr)==true){
        if(len>0) pwr[len-1]-=1;

        half(pwr);
        ret=bigMod(pwr);
        ret=ret*ret*(iii)3;
        
        
    }
    else{
        half(pwr);
        ret=bigMod(pwr);
        ret=ret*ret;
    }


    return ret%MOD;
}






int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    
    string st;

    int cases,caseno=1,num[100009];

    scan(cases);
    while(cases--){
        cin>>st;

        len=st.length();

        for(int i=0;i<len;i++){
            num[i]=st[i]-'0';
        }
        iii res=divide(num);


        iii ans=bigmod((iii)3,res,(iii)MOD);

        ans++;
        iii inv=modinverse((iii)2,(iii)MOD);
        ans*=inv;
        ans%=MOD;

        printf("Case %d: %lld\n",caseno++,ans);
    }









    return 0;
}
    
