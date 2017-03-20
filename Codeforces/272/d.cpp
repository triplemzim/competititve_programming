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

string st,p;
int A[2010];

int find_p(int start)
{
    int len1=st.length(),len2=p.length();
    for(int i=0;i<len2;i++)
    {
        while(start<len1 && st[start]!=p[i])
        {
            start++;
        }
        if(start==len1)
        {
            start=-1;
            break;
        }
        if(st[start]==p[i]) start++;
    }
    return start;
}
int dp[2009][2009];
int main()
{
//    ios::sync_with_stdio(false);
//freopen("in.txt","r",stdin);
    cin>>st;
    cin>>p;

    int len1=st.length(),len2=p.length();

    for(int i=0;i<len1;i++)
    {
        A[i]=find_p(i);
        if(A[i]>=0) A[i]=A[i]-i;
//        cout<<A[i]<<' ';
    }
//    cout<<endl;
    

    for(int i=0;i<len1;i++)
    {
        for(int j=0;j<=i;j++)
        {
            dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);

            if(A[i]>=0)
            {
                dp[i+A[i]][j+A[i]-len2]=max(dp[i+A[i]][j+A[i]-len2],dp[i][j]+1);
//                cout<<dp[i+A[i]-1][j+A[i]-len2]<<' ';

            }

        }
       
    }
//    for(int i=0;i<len1;i++)
//    {
//        for(int j=0;j<len1;j++)
//        {
//            cout<<dp[i][j]<<' ';
//        }
//        cout<<endl;
//
//    }
    for(int i=0;i<=len1;i++)
    {
        cout<<dp[len1][i]<<' ';
    }
    cout<<endl;

    return 0;
}
