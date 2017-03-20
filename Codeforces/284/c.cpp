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

    double homex,homey,varx,vary;
    int n;
    cin>>homex>>homey>>varx>>vary;

    double a1,b1,c1,a2,b2,c2;
    a1=homey-vary;
    b1=varx-homex;
    c1=(homey*(homex-varx)-homex*(homey-vary));

//    cout<<a1<<' '<<b1<<' '<<c1<<endl;
//
//    cout<<endl;

    cin>>n;
    int count=0;
    while(n--){
       cin>>a2>>b2>>c2;

       double div=a1*b2-b1*a2;
       if(div==0) continue;

       double x,y;
       x=b1*c2-b2*c1;
       y=a1*c2-a2*c1;

       x/=(double(div));
       y/=-(double(div));


       if(absolute(x-homex)<=.0001 && absolute(x-varx)<=.0001)
       {
           if(y<homey && y<vary) continue;
           if(y>homey && y>vary) continue;
           count++;
           
       }
       else if(absolute(y-homey) <=.0001 && absolute(y-vary)<=.0001)
       {
           if(x<homex && x<varx) continue;
           if(x>homex && x>varx) continue;
           count++;
       }
       else if(x>homex && x>varx) continue;
       else if(x<homex && x<varx) continue;
       else count++;
    }
    cout<<count<<endl;


      
        



    return 0;
}
