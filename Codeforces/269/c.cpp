#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanl(x) scanf("%i64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("debug: %d\n",x)
#define printl(x) printf("%i64d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define mapl map<long long, int > 
#define mapi map<int,int> 
#define mapp map< pair<int,int> , int>
#define mp make_pair
#define eps 1e-9
#define inf 999999999
#define maxn 1000009
#define mod 1000000007 // 10^9 + 7

template < class t > t gcd(t a , t b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class t > t lcm(t a , t b ) { return  a*b / gcd(a, b);}
template < class t > t absolute(t a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


int main()
{
    iii n;
    cin>>n;

    iii room,cardno=2;
    int count=0;

    for(iii f=1;cardno<=n;f++)
    {
        room=(f*(f+1))/2;
        cardno=f*2 + (room-f)*3;
//        cout<<"cardno: "<<cardno<<endl;

        if(cardno<=n &&  (n-f*2)%3==0) count++;
    }
//    cout<<"Step: "<<step<<endl;
    cout<<count<<endl;

    return 0;
}
