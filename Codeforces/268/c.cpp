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

void prnt4()
{
    cout<<"1 * 2 = 2\n3 * 4 = 12\n12 * 2 = 24\n";
}
void prnt5()
{
    cout<<"5 + 4 = 9\n9 + 3 = 12\n2 * 1 = 2\n12 * 2 = 24\n";
}

int main()
{
    int n;
    cin>>n;

    if(n<4)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    int count=0;
    if(n%2)
    {
        
        for(int i=n;i>=6;i-=2)
        {
            printf("%d - %d = %d\n",i,i-1,1);
            count++;
        }
        for(int i=0;i<count;i++)
        {
            printf("1 * 1 = 1\n");
        }
        prnt5();
    }
    else 
    {
        for(int i=n;i>=5;i-=2)
        {
            printf("%d - %d = 1\n",i,i-1);
            count++;
        }
        for(int i=0;i<count;i++)
        {
            printf("1 * 1 = 1\n");
        }
        prnt4();
    }


    



    return 0;
}
