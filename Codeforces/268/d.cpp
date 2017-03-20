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

iii p[100009],n,a,b;
map<iii,int> mp;
vector<iii> check;

int main(int argc, const char *argv[])
{
    cin>>n>>a>>b;
    for (int  i = 0; i < n; i++) {
        cin>>p[i];
        mp[p[i]]=-1;
    }

    if(a==b)
    {
        for (int  i = 0; i < n; i++) {
            if(mp.find(a-p[i])==mp.end())
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
        cout<<"YES"<<endl;
        for (int  i = 0; i < n; i++) {
            cout<<0<<' ';
        }
        return 0;
    }

    iii temp,check1,check2;
    bool flag=true;
    for (int  i = 0; i < n; i++) {
        if(mp[p[i]]!=-1) continue;

        check1=a-p[i];
        check2=b-p[i];

        flag=true;
        check.clear();
        check.pb(p[i]);
        while(flag)
        {
            if(mp[check1]==-1 && mp[check2]==-1)
            {
                check.pb(check1);
                check.pb(check2);
                temp=b-check1;
                check1=a-check2;
                check2=temp;
            }
            else if(mp[check1]==-1)
            {
                flag=false;
                mp[check1]=1;
                for (int  i = 0; i < (int)check.size(); i++) {
                    mp[check.at(i)]=1;
                }
            }
            else if(mp[check2]==-1)
            {
                flag=false;
                mp[check2]=2;
                for (int  i = 0; i < (int)check.size(); i++) {
                    mp[check.at(i)]=2;
                }
            }
            else
            {
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }

    cout<<"YES"<<endl;
    for (int  i = 0; i < n; i++) {
        if(mp[p[i]]==1) cout<<0<<' ';
        else cout<<1<<' ';
    }

        

    return 0;
}
