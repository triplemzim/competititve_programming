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

    iii num[25];
    num[0]=0;
    num[1]=1;
    num[2]=2;
    num[3]=3;
    num[4]=3;
    num[5]=4;
    num[6]=5;
    num[7]=6;
    num[8]=num[9]=6;
    num[10]=7;
    num[11]=8;
    num[12]=num[13]=8;
    num[14]=9;
    num[15]=10;
    num[16]=num[17]=num[18]=10;
    num[19]=11;
    num[20]=num[21]=num[22]=11;
    num[23]=12;

    int cases;
    iii a,b;
    scan(cases);
    while(cases--){
        cin>>a>>b;
        if(a>23)
        {
            cout<<b-a+1<<endl;
        }
        else if(a<24 && b>23) 
        {
            cout<<b-a+1-(12-num[a-1])<<endl;
        }
        else 
        {
            cout<<b-a+1-(num[b]-num[a-1])<<endl;
        }
    }




    return 0;
}
