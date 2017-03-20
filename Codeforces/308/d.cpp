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


pair<int,int> points[MAXN],slopes[1000009];

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);


    iii n;
    cin>>n;


    for (int  i = 0; i < n; i++) {
        scanf("%d %d",&points[i].first,&points[i].second);
    };

    int cnt=0;
    iii total=0;
    for (int  i = 0; i < n; i++) {
        cnt=0;
        for (int  j = i+1; j < n; j++) {
            slopes[cnt].first=points[j].first-points[i].first;
            slopes[cnt].second=points[j].second-points[i].second;
            int div=gcd(slopes[cnt].first,slopes[cnt].second);
            if(div) {
                slopes[cnt].first/=div;
                slopes[cnt].second/=div;
            }
            cnt++;

        }
        sort(slopes,slopes+cnt);
        iii temp=2;

        for(int j=1;j<=cnt;j++){
            if(j<cnt && slopes[j]==slopes[j-1]){
                temp++;
            }
            else{
                if(temp>2) total+=((temp-1)*(temp-2))/(iii)2;
                temp=2;
            }
        }


    }

    iii triangle;
    if(n>2){
        triangle=(n*(n-1)*(n-2))/(iii)6;
    }
    else triangle =0;

    triangle-=total;

    if(triangle<0) triangle=0;
    cout<<triangle<<endl;



            



    return 0;
}
