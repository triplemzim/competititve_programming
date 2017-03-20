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

    int n,k,num[111];
    pair<int,int> p[110];

    scan(n);
    scan(k);
    for (int  i = 0; i < n; i++) {
        scan(p[i].first);
        p[i].second=i;
        num[i]=p[i].first;
    }


    int color[110][110]={0};
    
    for(int i=0;i<n;i++){
        int x=1;
        for(int j=0;j<num[i];j++){
            color[i][x]++;
            x++;
            if(x==k+1) x=1;
        }
    }
    int mn,mx;
    for(int i=1;i<=k;i++){
        mn=120;
        mx=-1;
        for(int j=0;j<n;j++){
            if(mn>color[j][i]) mn=color[j][i];
            if(mx<color[j][i]) mx=color[j][i];
        }
        if(abs(mn-mx) >1) 
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }

    cout<<"YES"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=k;j++){
            for(int a=0;a<color[i][j];a++){
                cout<<j<<' ';
            }
        }
        cout<<endl;
    }







    



    return 0;
}
