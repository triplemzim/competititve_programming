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

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

    
int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n;
    vector<iii>table,taken;
    map<iii,int> mp;

    scan(n);
    iii temp;

    for (int  i = 0; i < n*n; i++) {
//        scanf("%I64d",&temp);
        cin>>temp;
        mp[temp]++;
//        cout<<endl<<temp<<' '<<mp[temp]<<endl;
        table.pb(temp);
    }

    sort(table.begin(),table.end());
//    for(int i=0;i<(int)table.size();i++){
//        cout<<table[i]<<' ';
//    }
//    cout<<endl;
//    cout<<mp[6]<<endl;

    for(int i=table.size()-1;i>=0;i--){
        if(mp[table[i]]>0){
            mp[table[i]]--;
            taken.pb(table[i]);
            int sz=taken.size()-1;
            for(int j=0;j<sz;j++){
                mp[gcd(taken[j],table[i])]-=2;
            }
        }
    }


    int sz=taken.size();

    for(int i=0;i<sz;i++){
        cout<<taken[i]<<' ';
    }
    cout<<endl;





    




    return 0;
}

