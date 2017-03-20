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
#define MAXN 100009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n;
    iii pos[MAXN],h[MAXN];
    bool left[MAXN]={false},right[MAXN]={false};
    left[0]=true;
    right[n-1]=true;

    cin>>n;

    for (int  i = 0; i < n; i++) {
        cin>>pos[i]>>h[i];
    }
    pos[n]=10000000000000000;

    for(int i=1;i<n;i++){
        if(pos[i]-h[i]>pos[i-1]) left[i]=true;
        if(pos[i]+h[i]<pos[i+1]) right[i]=true;
    }
    bool felci[MAXN]={false};


    int count=min(n,2);

    for(int i=1;i<n-1;i++){
        if(felci[i-1]==false){
            if(left[i]==true){
                count++;
            }
            else if(right[i]==true){
                count++;
                felci[i]=true;
            }
        }
        else{
            if(pos[i]-h[i]>pos[i-1]+h[i-1]){
                count++;
            }
            else if(right[i]==true){
                count++;
                felci[i]=true;
            }
        }

    }

    cout<<count<<endl;









    return 0;
}
