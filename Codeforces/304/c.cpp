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



vector<int>one,two;
queue<int>q1,q2;
int n,k1,k2;

void init(){
    for(int i=0;i<k1;i++) q1.push(one[i]);
    for(int i=0;i<k2;i++) q2.push(two[i]);
}

bool check(){
    queue<int> a,b;
    a=q1;
    b=q2;

    for(int i=0;i<k1;i++){
        if(a.front() != one[i]) return false;
        a.pop();
    }
    for(int i=0;i<k2;i++){
        if(b.front() != two[i]) return false;
        b.pop();
    }
    return true;
}

void calc(){
    int f=k1,s=k2;
    bool flag=true;
    int mov=0;

    while(f>0 && s>0){
        int x=q1.front(),y=q2.front();
        q1.pop();
        q2.pop();

        if(x>y){
            q1.push(y);
            q1.push(x);
            f++;
            s--;
        }
        else {
            q2.push(x);
            q2.push(y);
            s++;
            f--;
        }
        mov++;
        if(f==k1 && s==k2){
            if(check()) {
                flag=false;
                break;
            }
        }
    }
    if(flag==false) cout<<-1<<endl;
    else{
        if(f>0){
            cout<<mov<<' '<<1<<endl;
        }
        else {
            cout<<mov<<' '<<2<<endl;
        }
    }
}

            




int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    cin>>n;
    cin>>k1;
    int temp;
    for (int  i = 0; i < k1; i++) {
        cin>>temp;
        one.pb(temp);
    }
    cin>>k2;
    for (int  i = 0; i < k2; i++) {
        cin>>temp;
        two.pb(temp);
    }
    init();
    calc();



    return 0;
}
