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



int n;
int val[100009];

    map<int,bool>mp;


int chk(int x,int y)
{
    int mov=0;

    while(x<y){
        y/=2;
        mov++;
        
    }
    if(x==y) return mov;

    while(y>1){
        if(x%y==0){
            if(mp.find(x/y)!=mp.end()){
                    while(x!=y){
                        y*=2;
                        mov++;
                    }
                    return mov;
            }
        }
        y/=2;
        mov++;
    }

    if(mp.find(x)==mp.end()) return -1;
    else {
        while(x!=y){
            y*=2;
            mov++;
        }
        return mov;
    }
    return -1;
}



        



int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    scan(n);
    int mn=100009;
    for (int  i = 0; i < n; i++) {
        scan(val[i]);
        mn=min(mn,val[i]);
    }

    int temp=mn;
    vector<int>v;


    while(mn>1){
        v.pb(mn);
        mn/=2;
        int a=mn;
        while(a<200000){
            a*=2;
            v.pb(a);
        }
    }
    v.pb(mn);
    mn=temp;
    temp=1;

    mp[1]=true;

    while(temp<200000){
        temp*=2;
        v.pb(temp);
        mp[temp]=true;
    }
    temp=mn;

    while(temp<200000){
        temp*=2;
        v.pb(temp);
    }

    int sz=v.size();
//    cout<<"size: "<<sz<<endl;
    int mov=10000000,cur=0;


    for(int i=0;i<sz;i++){
        bool flag=true;
        cur=0;
        for(int j=0;j<n;j++){
            temp=chk(v[i],val[j]);
            if(temp==-1){
                flag=false;
                break;
            }
            cur+=temp;
        }
//        cout<<v[i]<<' '<<cur<<endl;
        if(flag) mov=min(mov,cur);
    }

    cout<<mov<<endl;



    return 0;
}
