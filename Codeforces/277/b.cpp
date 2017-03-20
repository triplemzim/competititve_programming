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

    int mat[110][110];
    int n,m;
    bool used[110][110]={false};
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }

    bool flag=true;
    for(int i=0;i<n;i++)
    {
        
        for(int j=0;j<m;j++)
        {
//            int temp=mat[i][j];
            if(!mat[i][j]){
            for (int  a = 0; a < n; a++) {
                used[a][j]=true;
            }
            for (int  a = 0; a < m; a++) {
                used[i][a]=true;
            }
            }
        }
    }
    for (int  i = 0; i < n; i++) {
        for (int  j = 0; j < m; j++) {
            int temp=mat[i][j];            
            if(temp)
            {
                bool ff=false;
                for(int a=0;a<n;a++)
                {
                    if(used[a][j]==false)
                    {
                        ff=true;
                        break;
                    }
                }
                for(int a=0;a<m;a++)
                {
                    if(used[i][a]==false)
                    {
                        ff=true;
                        break;
                    }
                }
                if(ff==false)
                {
                    flag=false;
                    break;
                }
            }
          
            
        }
    }

    if(flag)
    {
        cout<<"YES"<<endl;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(used[i][j]) cout<<0<<' ';
                else cout<<'1'<<' ';
            }
            cout<<endl;
        }
    }
    else cout<<"NO"<<endl;










    return 0;
}
