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

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


char calc(char c,char d){
    for(char x='a';x<='z';x++){
        if(x!=c && x!=d) return x;
    }
    return 'a';
}




int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int len,t;
    string a,b,c;

    cin>>len>>t;
    cin>>a>>b;

    for(int i=0;i<len;i++){
        c+=calc(a[i],b[i]);
    }

    int count=0;
    for(int i=0;i<len;i++){
        if(a[i]!=b[i]){
            count++;
        }
    }

    if(count%2 && t<count/2+1){
        cout<<-1<<endl;
        return 0;
    }
    else if(count%2==0 && t<count/2){
        cout<<-1<<endl;
        return 0;
    }


    int tar_match=len-t;
    if(count%2==0){

        bool flag=true;

        for(int i=0;i<len;i++){
            if(tar_match==0) break;

            if(a[i]!=b[i]){
                if(flag) c[i]=a[i];
                else c[i]=b[i];

                if(flag==false) tar_match--;
                flag=!flag;
            }
        }


        for(int i=0;i<len;i++){
            if(tar_match==0) break;

            if(a[i]==b[i]){
                c[i]=a[i];
                tar_match--;
            }
        }
        cout<<c<<endl;
        return 0;

    }

    bool flag=true;
    for(int i=0;i<len;i++){
        if(tar_match==0) break;

        if(a[i]==b[i]){
            c[i]=a[i];
            tar_match--;
        }
    }
    for(int i=0;i<len;i++){
        if(tar_match==0) break;

        if(a[i]!=b[i]){
            if(flag) c[i]=a[i];
            else c[i]=b[i];
            if(flag==false) tar_match--;
            flag=!flag;
        }
    }

    cout<<c<<endl;






    return 0;
}

