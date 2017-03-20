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

vector< int > v[5050];


bool compare( int a, int b)
{
    return a<b? false: true;
}
int main()
{
  //  freopen("in.txt","r",stdin);
    
    
    int n,m,k;
    cin>>n>>m>>k;
    int num[5010],total=0;

    for (int  i = 0; i < n; i++) {
        cin>>num[i];
    }

    for(int i=0;i<m-1;i++)
    {
        total+=num[i];
    }
    for(int i=m-1;i<n;i++)
    {
        total+=num[i];
        v[i%m].pb(total);
        total-=num[i-m+1];
    }
    for(int i=0;i<m;i++)
    {
        sort(v[i].begin(),v[i].end(),compare);
        for(int j=0;j<(int)v[i].size();j++)
        {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
    total=0;
    for(int i=0;i<m;i++)
    {
        int temp=0;
        for(int j=0;j<k && j<(signed)v[i].size();j++)
        {
            temp+=v[i][j];
//            cout<<v[i][j]<<' '<<j<<' ';
        }
//        cout<<endl;
        total=max(total,temp);
    }



  
    

    cout<<total<<endl;





    return 0;
}
