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



iii c1[1000009],c2[1000009];
iii g1[1000009][2],g2[1000009][2];


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    iii m,h1,a1,x1,y1,h2,a2,x2,y2;

    cin>>m>>h1>>a1>>x1>>y1>>h2>>a2>>x2>>y2;
//    ah=h1;
//    bh=h2;


    int count=0;
    c1[h1]=c2[h2]=1;

    while(1){
        h1=(x1*h1+y1)%m;
        h2=(x2*h2+y2)%m;
        count++;
        if(c2[h2]>=2 && c1[h1]>=2) break;

        if(c1[h1]<2){
            g1[h1][c1[h1]]=count;
            c1[h1]++;
            
        }
        if(c2[h2]<2){
            g2[h2][c2[h2]]=count;
            c2[h2]++;
        }

        if(h1==a1 && h2==a2){
            cout<<count<<endl;
            return 0;
        }

        


    }

//    cout<<g1[2][1]<<' '<<g2[2][1]<<endl;


    if(c1[a1]<2 || c2[a2]<2) {
        cout<<-1<<endl;
        return 0;
    }

    iii a=g1[a1][1],b=g2[a2][1];
    iii x=g1[a1][0],y=g2[a2][0];
    a-=x;
    b-=y;


//    cout<<a<<' '<<b<<' '<<endl;
//    cout<<x<<' '<<y<<' '<<endl;
//
    if(x<y){
        swap(x,y);
        swap(a,b);
    }

    iii dif=x-y;

    for(iii i=1;i<a;i++){
        if((b*i)%a==dif){
            cout<<b*i+y<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    





   



    return 0;
}
