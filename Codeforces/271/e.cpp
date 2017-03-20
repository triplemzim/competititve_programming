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
#define inf 100000000000000009
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

iii n,d,num[100009],L[100009];
vector<iii>v(100009,inf);
vector<iii>::iterator it;

int idx;
int find_idx(iii val)
{
    int low=0,high=100009,mid=(low+high)/2;
    while(low<=high)
    {
        if(absolute(v[mid]-val)>=d && v[mid]!=inf)
        {
            low=mid+1;
            mid=(high+low)/2;
        }
        else 
        {
            high=mid-1;
            mid=(high+low)/2;
        }
//        else
//        {
//            cout<<"kemne"<<endl;
//            return 0;
//        }
    }
    return low;
}

        

int main()
{
    map<int,int>mp;
    mp[2];
    mp[1];
    mp[4];
    
    itr_all(mp,itr)
    {
        cout<<itr->first<<endl;
    }

    freopen("in.txt","r",stdin);
    
    
    
    iii mx=-1,last=inf;
    cin>>n>>d;
    for (int  i = 0; i < n; i++) {
        cin>>num[i+1];
    }

        

    



    return 0;
}
