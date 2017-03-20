
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

vector<int> fail_fun(string st)
{
    int k=-1;
    vi table(st.length()+1,0);
    int len=st.length();
    table[0]=-1;
    for(int i=1;i<len;i++)
    {
        while(k>-1 && st[k+1]!=st[i]) k=table[k];
        if(st[k+1]==st[i]) k++;
        table[i]=k;
    }
    return table;
}

int kmp(string a,string b)
{
//    int count=0;
    vector<int> table;
    table=fail_fun(b);
    int k=-1;
    int len1=a.length();
    int mx=1;
    for(int i=0;i<len1;i++)
    {
        while(k>-1 && a[i]!=b[k+1]) k=table[k];
        if(a[i]==b[k+1]) k++;
        mx=max(mx,k);
//        if(k==len2-1 )
//        {
//            k=table[k];
//        }
    }
    return k+1;
}

int main()
{
//    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    
    
    vector<int> table; 
    int cases,caseno=1;
    scan(cases);
    while(cases--)
    {
        string a,b;
        cin>>a;
//        cout<<a<<endl;
        iii len1=a.length();
//        cout<<len1<<endl;
        for(int i=len1-1;i>=0;i--)
        {
            b+=a[i];
        }
//        cout<<b<<endl;
        iii count=kmp(a,b);

        count=len1-count+len1;


        printf("Case %d: %lld\n",caseno++,count);
    }




    return 0;
}
