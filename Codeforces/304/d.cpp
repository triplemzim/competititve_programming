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
#define MAXN 5000009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


int sum[MAXN],ult[MAXN],p[MAXN];

void calc(){
    for(int i=2;i<MAXN;i++){
        if(p[i]==0){

            for(int j=i;j<MAXN;j+=i){
                int a=j,c=0;
                while(a>1 && a%i==0){
                    c++;
                    a/=i;
                }
                p[j]+=c;
            }
        }
    }
//    cout<<p[3]<<endl;
    ult[1]=0,ult[2]=1;
    for(int i=2;i<5000001;i++){
        ult[i]=ult[i-1]+p[i];
    }
}

            




int main(){
   int test,a,b;
    calc();
   scan(test);
   while(test--){
       scan(a);
       scan(b);
       printf("%d\n",ult[a]-ult[b]);
   }






    return 0;
}


/*
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


#define sets(n,pos) (n|(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))
#define mx 5555555
#define lim 5555
unsigned prime[mx>>6];
vector<int> p;
bool PRIME[5000009];
void sieve()
{
    unsigned k,i,j;
    prime[2>>6]=sets(prime[2>>6],0);
    for(i=3;i<lim;i+=2)
    {
        if(check(prime[i>>6],((i>>1)&31))==0)
        {
//            if(i<100) cout<<i<<" ";
            k=i<<1;
            for(j=i*i;j<=mx;j+=k)
            {
                prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
            }
        }
    }
    p.pb(2);
    for(int i=3;i<5000009;i+=2){
        if(check(prime[i>>6],((i>>1)&31))==0){
            PRIME[i]=true;
            p.pb(i);
        }
    }
//    cout<<endl;
//    cout<<p.size()<<endl;
//    for(int i=0;i<5001;i++) cout<<p[i]<<' ';
    return;
}

int sum[5000009];
    int ult[5000009];
int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

   sieve(); 
   PRIME[2]=true;
   sum[1]=sum[2]=1;
   ult[1]=0;ult[2]=1;
   ult[0]=0;
    int x;
   for(int i=2;i<5000009;i++){
       x=i;
        if(PRIME[i]==true) sum[i]=1;
        else{
           for(int j=0;j<(int) p.size();j++){
               if(x%p[j]==0){
                   sum[i]=sum[p[j]]+sum[x/p[j]];
                   break;
               }
           }
       }
        
       ult[i]=ult[i-1]+sum[i];
        
//        if(i<10) cout<<i<<' '<<sum[i]<<endl;


//       sum[i]=sum[i-1]+count;
   
   }

   int test,a,b;

   scan(test);
   while(test--){
       scan(a);
       scan(b);
       cout<<ult[a]-ult[b]<<endl;
   }






    return 0;
}
 */
