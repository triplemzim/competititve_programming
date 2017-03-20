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
    int n[10],c[20]={0};
    for (int  i = 0; i < 6; i++) {
        cin>>n[i];
        c[n[i]]++;
    }

    bool leg=false;

    int l,h,b;
    for(int i=1;i<10;i++)
    {
        if(c[i]>=4)
        {
            leg=true;
            l=i;
            break;
        }
    }
    int count=0;
    for(int i=0;count<4 && i<6;i++)
    {
        if(n[i]==l)
        {
            n[i]=0;
            count++;
        }
    }
    l=0;

    bool head=false,body=false;
    for(int i=0;i<6;i++)
    {
        if(head==false)
        {
            if(l!=n[i])
            {
                h=n[i];
                head=true;
            }
        }
        else
        {
            if(l!=n[i])
            {
                b=n[i];
                body=true;
                
            }
        }
                
    }

    if(leg==true && body==true && head==true)
    {
        if(b!=h)
        {
            cout<<"Bear"<<endl;
        }
        else
        {
            cout<<"Elephant"<<endl;
        }
    }
    else 
    {
        cout<<"Alien"<<endl;
    }






    return 0;
}
