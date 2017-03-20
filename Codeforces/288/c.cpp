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

    int m,t,r,temp,count=0;
    int ghost[2000]={0};
    cin>>m>>t>>r;
    for (int  i = 0; i < m; i++) {
        cin>>temp;
        ghost[temp+400]=1;
    }

    bool flag=true;

    int lighten[3333]={0};
    int candle=0;

    for(int i=401;i<=710;i++){
        if(ghost[i]==1){
            while(count<r){
//                cout<<"count: "<<count<<endl;
                bool temp_flag=false;
                for(int j=i-1;j>=i-t;j--)
                {
                    if(lighten[j]!=-1){
                        candle++;
                        lighten[j]=-1;
                        lighten[j+t]=1;
                        temp_flag=true;
                        break;
                    }
                }
                if(temp_flag==false) 
                {
                    flag=false;
                    break;
                }
                else count++;
            }
        }
        if(lighten[i]==1) count--;
    }

    if(flag==true) cout<<candle<<endl;
    else cout<<-1<<endl;






    return 0;
}

