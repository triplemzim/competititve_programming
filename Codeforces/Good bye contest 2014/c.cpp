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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n,m;
    cin>>n>>m;
    int w[510],s[1010];
    for (int  i = 0; i < n; i++) {
        cin>>w[i];
    }
    for (int  i = 0; i < m; i++) {
        cin>>s[i];
    }

    stack<int> a,b;

    a.push(s[0]);
    int sum=0;
    for(int i=1;i<m;i++)
    {

        bool flag=false;
        while(!a.empty())
        {
            int top=a.top();
//            cout<<top<<' ';
            a.pop();
            if(top==s[i]) flag=true;
            if(!flag) sum+=w[top-1];
            if(top!=s[i]) b.push(top);
        }
//        cout<<endl;
        while(!b.empty())
        {
            a.push(b.top());
            b.pop();
        }
        a.push(s[i]);
//        cout<<sum<<endl;
    }


    cout<<sum<<endl;





    return 0;
}
