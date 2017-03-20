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
inline iii power(iii base,iii p) { while(--p>1) base*=base; return base;}

int first_match,table[35][35];

int LCS(string s1,string s2)
{
    int len1=s1.length(),len2=s2.length();
    for (int  i = 0; i < 31; i++) {
        table[0][i]=table[i][0]=0;
    }

    for(int i=0;i<len1;i++)
    {
        for (int  j = 0; j < len2; j++) {
            if(s1[i]==s2[j])
            {
                table[i+1][j+1]=table[i][j]+1;
            }
            else table[i+1][j+1]=max(table[i+1][j],table[i][j+1]);
        }
    }
    int ck=table[len1][len2];
//    cout<<s1<<'\n'<<s2<<endl;
//
//    for (int  i = 0; i <= len1; i++) {
//        for (int  j = 0; j <= len2; j++) {
//            cout<<table[i][j]<<' ';
//        }
//        cout<<endl;
//    }
//    cout<<endl;
    int i=len1,j=len2,pos1,pos2;
    while(ck==table[i][j])
    {
        if(i-1>0 && j>0 && table[i-1][j]==ck) i--;
        else if(i>0 && j-1>0 && table [i][j-1]==ck) j--;
        else
        {
            pos1=i;
            pos2=j;
            break;
        }
    }

    return ck;
}
    
iii dp[35][35];

iii comb(int n,int r)
{
    if(n==r || r==0) return 1;
    if(dp[n][r]!=-1) return dp[n][r];
    return dp[n][r]=comb(n-1,r-1)+comb(n-1,r);
}



int main()
{
    freopen("in.txt","r",stdin);
    
    
    string s1,s2;
    int cases,caseno=1;
    cin>>cases;
    iii lcs,len1,len2,perm,mx,length;
    ms(dp,-1);
    while(cases--)
    {
        cin>>s1>>s2;
        len1=s1.length();
        len2=s2.length();

        lcs=LCS(s1,s2);


        mx=max(len1,len2);

        length=mx+min(len1,len2)-lcs;
        if(len1>len2)
        {
            prev=pos2-lcs;

        

        perm=comb(mx-first_match+1,min(len1,len2)-lcs);

        printf("Case %d: %lld %lld\n",caseno++,length,perm);
    }
        



    return 0;
}
