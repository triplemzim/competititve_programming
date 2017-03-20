#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

using namespace std;

#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define printL(x) printf("%I64d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
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
#define MOD 1000000007 // 10^9 +7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

#define MAXLG 20 





char ch[MAXN];
int len,step,n;
int table[1000009];
void fail_fun(char* st)
{
    int k=-1;
//   ms(table,0); 
    
    table[0]=-1;
    for(int i=1;i<len;i++)
    {
        while(k>-1 && st[k+1]!=st[i]) k=table[k];
        if(st[k+1]==st[i]) k++;
        table[i]=k;
    }
    
}
int main()
{
//	  ios::sync_with_stdio(false);
	  freopen("in.txt","r",stdin);

    int count=0;
//    while(scanf("%d%s",&n,ch)!=EOF)
    while(scanf("%d",&n) && n+1)
    {
        scanf("%s",ch);
        len=strlen(ch);
        if(n==-1 ) return 0;
        count=0;
        
        fail_fun(ch);

        count=table[len-1]+1;
        if(n<len) 
        {
            cout<<"0"<<endl;
            continue;
        }
//        cout<<"count: "<<count<<endl;
//        cout<<count<<endl;
        if(count<0) count=0;
        

        count=len-count;

        n=(n-len)/count +1;
        if(n<0) n=0;
        cout<<n<<endl;
    }



    return 0;
}


