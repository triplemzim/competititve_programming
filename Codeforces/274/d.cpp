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

iii p[100009];
iii n,l,x,y;


bool bsrch(iii val)
{
    int low=0,high=n-1,mid;
    
    while(low<=high)
    {
        mid=(low+high)/2;
        if(p[mid]==val) return true;
        if(p[mid]<val)
        {
            low=mid+1;
        }
        else if(p[mid]>val)
        {
            high=mid-1;
        }
    }
    return false;
}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);


    cin>>n>>l>>x>>y;

    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }

    int answer,point;
    answer=2;
    bool flag_x=false,flag_y=false;

    for(int i=0;i<n;i++)
    {
        if(flag_x==false)
        {
            flag_x=bsrch(p[i]+x);
        }
        if(flag_y==false)
        {
            flag_y=bsrch(p[i]+y);
        }

        if(flag_x ==false && flag_y==false)
        {
            if(p[i]+x<=l && bsrch(p[i]+x+y))
            {
                answer=1;
                point=p[i]+x;
            }
            else if(p[i]+x<=l && bsrch(p[i]+x-y))
            {
                answer=1;
                point=p[i]+x;
            }
            else if(p[i]+y<=l && bsrch(p[i]+y-x))
            {
                answer=1;
                point=p[i]+y;
            }
            else if(p[i]-y>=0 && bsrch(p[i]-y+x))
            {
                answer=1;
                point=p[i]-y;
            }
            else if(p[i]-y >=0 && bsrch(p[i]-y-x))
            {
                answer=1;
                point=p[i]-y;
            }

            else if(p[i]-x >=0 && bsrch(p[i]-x-y))
            {
                answer=1;
                point=p[i]-x;
            }
        }
    }
    if(flag_x && flag_y) 
    {
        cout<<0<<endl;
    }
    else if(flag_x)
    {
        cout<<1<<endl;
        cout<<y<<endl;
    }
    else if(flag_y)
    {
        cout<<1<<endl;
        cout<<x<<endl;
    }
    else if(answer==1)
    {
        cout<<1<<endl;
        cout<<point<<endl;
    }
    else
    {
        cout<<2<<endl;
        cout<<x<<' '<<y<<endl;
    }

                    
    return 0;
}
