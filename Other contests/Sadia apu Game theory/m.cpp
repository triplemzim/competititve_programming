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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    string bin;
    int len;
    getline(cin,bin);
    len=bin.length();

    int zero=0,count=0,one=0;

    for(int i=0;i<len;i++){
        if(bin[i]=='1') one++;
        else zero++;

        if(one==0){
            zero=0;
            continue;
        }

        if(bin[i]=='0'){
            if(bin[i-1]=='0'){
                count+=min(one,zero);
//                if(one==1) count--;
                zero=0;
                one=0;
            }
        }
    }
    if(len==1){
        if(bin[len-1]=='0') count=0;
        else count=1;
    }
    else{
        if(!(bin[len-1]=='0' && bin[len-2]=='0')){
            count+=min(one,zero+2);
            if(one>=zero+2 && bin[len-1]=='0') count--;
//            cout<<count<<endl;
//            if(bin[len-1]=='0') count--;
//            if(one==1) count--;
        }
    }



    cout<<count<<endl;
            



    return 0;
}
