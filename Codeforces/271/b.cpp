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

int bsearch(iii q,iii a[],iii n)
{
    int low=1,high=n,mid=(low+high)/2;
    while(low<=high)
    {
//        cout<<low<<' '<<mid<<' '<<high<<endl;
        if(a[mid]>=q && a[mid-1]<q)
        {
            return mid;
        }
        else if(a[mid]<q)
        {
            low=mid+1;
            mid=(low+high)/2;
        }
        else
        {
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    return -1;
}

int main()
{
    iii n,a[100009],m,q;
    cin>>n;
    iii temp;
    a[0]=0;
    for (int  i = 1; i <= n; i++) {
        cin>>temp;
        a[i]=temp+a[i-1];
    }
    cin>>m;
    for (int  i = 0; i < m; i++) {
        cin>>q;
        cout<<bsearch(q,a,n)<<endl;
    }




    return 0;
}
