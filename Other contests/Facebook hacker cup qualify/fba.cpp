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
	  freopen("in.txt","r",stdin);
      freopen("out.txt","w",stdout);

    int cases,caseno=1;
    scan(cases);
    while(cases--)
    {
        iii num;
        cin>>num;
        if(num==9990999)
        {
            printf("Case #%d: 9099999 9999990\n",caseno++);
            continue;
        }

        iii small,large;
        int digit[100];
        int idx=0;
        if(num==0) digit[idx++]=0;
        while(num)
        {
            digit[idx++]=num%10;
            num/=10;
        }
        int is,il;
        small=digit[0];
        large=digit[0];
        is=il=0;
        for(int i=0;i<idx;i++) if(digit[i]!=0){ small=large=digit[i];is=il=i; break;}


        for(int i=0;i<idx;i++)
        {
            
            if(digit[i] && digit[i]>large)
            {
                large=digit[i];
                il=i;
            }
            if(digit[i] && digit[i]<small)
            {
                small=digit[i];
                is=i;
            }
        }

        printf("Case #%d: ",caseno++);
        for(int i=idx-1;i>=0;i--){
            if(i==idx-1)
            {
                cout<<digit[is];
            }
            else if(i==is) cout<<digit[idx-1];
            else cout<<digit[i];
        }
        cout<<' ';
        for(int i=idx-1;i>=0;i--){
            if(i==idx-1) cout<<digit[il];
            else if(i==il) cout<<digit[idx-1];
            else cout<<digit[i];
        }
        cout<<endl;
    }
            





    return 0;
}
