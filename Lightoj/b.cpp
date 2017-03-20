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

struct point{
    int x, y;
};

int orientation(point p,point q, point r)
{
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    if(val==0) return 0;
    return (val>0)?1:2;
}

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);
//
//    point a,b,c;
//    while(1){
//        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
//        cout<<orientation(a,b,c)<<endl;
//    }

    int cases,caseno=1;
    int n,q;
    point P[110];
    scan(cases);
    while(cases--){
        scan(n);
        int a,b;
        for (int  i = 0; i < n; i++) {
            scan(a);
            scan(b);
            P[i].x=a;
            P[i].y=b;
        }
        scan(q);
        point temp;
        printf("Case %d:\n",caseno++);
        while(q--){
            scan(a);
            scan(b);
            temp.x=a;
            temp.y=b;
            bool flag=true;

            for(int i=1;i<n;i++)
            {
                if(orientation(P[i-1],P[i],temp)==1)
                {
                    flag=false;
                    break;
                }
            }
            if(orientation(P[n-1],P[0],temp)==1) flag=false;
            if(flag) cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }

    }
    



    return 0;
}
