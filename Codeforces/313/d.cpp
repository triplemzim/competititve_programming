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


char a[200009],b[200009];

int chk(int s1,int e1,int s2,int e2)
{
    int len=e1-s1+1;

    if(len%2==1){
        for(int i=s1;i<=e1;i++){
            if(a[i]!=b[s2]) return false;
            s2++;
        }
        return true;

    }

    int mid1,mid2;
    mid1=(s1+e1)/2;
    mid2=(s2+e2)/2;

    if(chk(s1,mid1,s2,mid2)==true && chk(mid1+1,e1,mid2+1,e2)==true) return true;

    if(chk(s1,mid1,mid2+1,e2)==true && chk(mid1+1,e1,s2,mid2)==true) return true;

    return false;


}





int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    scanf("%s",a);
    scanf("%s",b);

    
    if(chk(0,strlen(a)-1,0,strlen(a)-1)==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;




    return 0;
}
