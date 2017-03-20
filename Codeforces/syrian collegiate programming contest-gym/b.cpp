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

iii n, lock[5][10009];
iii a[1000009],b[1000009];
map<iii,int> mp;

int main()
{
    freopen("in.txt","r",stdin);
    
    iii sum; 
//    ios::sync_with_stdio(false);
    int cases,caseno=1;

    scan(cases);
    while(cases--)
    {
        cin>>n;
        sum=0;
        for(int i=0;i<4;i++)
        {
            for (int  j = 0; j < n; j++) {
                cin>>lock[i][j];
                sum+=lock[i][j];

            }
        }
        bool flag=true;
        cout<<sum<<endl;
        if(4*(sum/4)!=sum) flag=false;
        else sum/=4;
        cout<<sum<<endl;
        int idx=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                a[idx]=(lock[0][j]+lock[1][(j+i)%n]);
                cout<<a[idx]<<' ';
                b[idx]=lock[2][j]+lock[3][(j+i)%n];
                mp[b[idx]]++;
                idx++;
            }
        }
        cout<<endl;
        iii fnd;
        for(int i=0;i<idx;i++)
        {
            fnd=sum-a[i]; 
            if(mp[fnd]>0) mp[fnd]--;
            else 
            {
                flag=false;
                break;
            }
        }

        if(flag)
        {
            printf("Case %d: Yes\n",caseno++);
        }
        else
        {
            printf("Case %d: No\n",caseno++);
        }
        mp.clear();
    }








    return 0;
}
