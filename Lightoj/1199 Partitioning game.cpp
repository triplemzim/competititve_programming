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
#define MAXN 10009
#define MOD 1000000007 // 10^9 + 7
 
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}
 
 
int grundy[10009];
bool s[100009];
 

void calc_ite()
{
    int a,b,ret;
    ms(grundy,0); 
    for(int j=3;j<10001;j++){
        ms(s,false);
        for (int  i = 1; i <=j/2; i++) {
            if(i!=j-i){

                a=grundy[i];
                b=grundy[j-i];
                s[a^b]=true;
            }
        }
        ret=0;

        for(int k=0;s[k]==true && k<10009;k++){
            ret++;
        }

        grundy[j]=ret;
    }
}




int calc_grundy(int x)
{
 
    if(grundy[x]!=-1)  return grundy[x];
    int a,b; 
 
    bool s[10009]={false};


    for(int i=1;i<=x/2;i++){
        if(i!=x-i){
            a=calc_grundy(i);
            b=calc_grundy(x-i);
            if((a^b)<10009) s[a^b]=true;
        }
    }


 
  
 
//    for(int i=0;i<(int)move.size();i++){
//        s[calc_grundy(move[i])]=true;
//    }
 
    int ret=0;
 
//    sort(s.begin(),s.end());
 
    for(int i=0;s[i]==true;i++){
        ret++;
    }
    return grundy[x]=ret;
}
 
 
 
 
int cases,pile[MAXN],n;
 
 
int main()
{
//      ios::sync_with_stdio(false);
//      freopen("in.txt","r",stdin);
 
    calc_ite();
    cin>>cases;
    int caseno=1;
 
    int temp,xr;
    while(cases--){
        cin>>n;
        for (int  i = 0; i < n; i++) {
            cin>>pile[i];
        }
        xr=0;
 
        for(int i=0;i<n;i++){
            temp=calc_grundy(pile[i]);
//            cout<<pile[i]<<' '<<calc_grundy(MP(0,pile[i]))<<endl;
            xr=xr^temp;
        }
        if(xr==0) {
            printf("Case %d: Bob\n",caseno++);
        }
        else {
            printf("Case %d: Alice\n",caseno++);
        }
 
    }
 
 
 
    return 0;
}
