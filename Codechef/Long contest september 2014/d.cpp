#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
#define printL(x) printf("%lld\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vector<int>
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

void convert(iii &num,string ch)
{
    num=0;
    for (int  i = 0; i < (signed)ch.length(); i++) {
        num=num*10+ ch[i]-'0';
    }
}

#define sets(n,pos) (n|(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))
#define mx 1000000
#define lim 1000
unsigned prime[mx>>6];
void sieve()
{
    unsigned k,i,j;
    prime[2>>6]=sets(prime[2>>6],0);
    for(i=3;i<lim;i+=2)
    {
        if(check(prime[i>>6],((i>>1)&31))==0)
        {
            if(i<100) cout<<i<<' '<<endl;
            k=i<<1;
            for(j=i*i;j<=mx;j+=k)
            {
                prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
            }
        }
    }
    return;
}

int main()
{
    vector<iii> v;
    iii n;
    string ch;
    int cases,len;
    scan(cases);
    while(cases--)
    {
        v.clear();
        cin>>ch;
        len=ch.length();
        if(len<20)
        {
            convert(n,ch);
        

            iii sq=sqrt(n);
            int l=min(100000,(int)sq);

            for (int  i = 2; i < l+1 && i<n; i++) {
                if(n%i==0) {
                    v.pb(i);
                    n/=i;
                    i--;
                }
            }
            v.pb(n);
            l=v.size();
            print(l);
            for (int  i = 0; i < l; i++) {
                printL(v[i]);
            }

        }
        else
        {
            if((ch[len-1]-'0')%2==1)
            {
                print(1);
                cout<<ch<<endl;
            }
            else
            {
                print(2);
                print(2);
                bool flag=false;
                int carry=0,div=0,bit;
                for (int  i = 0; i < len; i++) {
                    bit=ch[i]-'0';
                    bit=carry*10+bit;
                    carry=bit&1;
                    div=bit>>1;
                    if(div>0)
                    {
                        flag=true;
                    }
                    if(flag) printf("%d",div);
                }
                printf("\n");
            }
        }
                    
    }


        



    return 0;
}
