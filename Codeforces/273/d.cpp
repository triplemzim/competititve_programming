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
iii R,G,H,h1,h2,c;
bool flag=false;
iii dp[2*100000+9];

int cal_h(int r,int g,int h)
{
    if(h==0)
    {
        return 1;
    }
    iii &ret=dp[h];
//    if(ret!=-1) return ret;

    iii temp1=0,temp2=0,temp;
    if(r>=h)
    {
        temp1=cal_h(r-h,g,h-1);
    }
    if(g>=h)
    {
        temp2=cal_h(r,g-h,h-1);
    }
    temp=(temp1+temp2)%MOD;


    return ret=temp;
}



int main()
{
    ios::sync_with_stdio(false);
    cin>>R>>G;
    iii ans=0;

   ms(dp,0);
   dp[0]=1;
   
    c=R+G;
    H=(-1+sqrt(1+8*c))/2;
//    cout<<"Hight: "<<H<<endl;
    
//    for(int i=1;i<=H;i++)
//    {
//        for(int j=R;j>=i;j--)
//        {
//             dp[j]=(dp[j]+dp[j-i])%MOD;
//        }
//    }
    for(int i=1;i<=H;i++)
    {
        for(int j=R;j>=0;j--)
        {
            if(i+j<=R && dp[j]) dp[i+j]=(dp[i+j]+dp[j])%MOD;
        }
    }
    iii extra=(R+G)-((H*(H+1))/2);
    for(int i=R;i>=max((iii)0,R-extra);i--)
    {
        ans+=dp[i];
    }
    ans%=MOD;
    cout<<ans<<endl;


    return 0;
}
