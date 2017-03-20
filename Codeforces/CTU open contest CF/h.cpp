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



string code[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

string underscore="..--",comma=".-.-",period="---.",qmark="----";


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    
//    for(int i=0;i<26;i++){
//        cout<<(char)('A'+i)<<' '<<code[i]<<endl;
//    }
    string input,ans,temp;

    while(cin>>input){
        int len=input.length();
        vector<int> num;
        char ch;
        ans="";

        for(int i=0;i<len;i++){
            ch=input[i];
            if(ch>='A' && ch<='Z'){
                num.pb(code[ch-'A'].length());
                ans+=code[ch-'A'];
            }
            else{
                num.pb(4);
                if(ch=='_'){
                    ans+=underscore;
                }
                else if(ch==','){
                    ans+=comma;
                }
                else if(ch=='.'){
                    ans+=period;
                }
                else ans+=qmark;
            }
        }

        int cur=0;
        for(int i=num.size()-1;i>=0;i--){
            temp="";
            for(int j=0;j<num[i];j++){
                temp+=ans[cur];
                cur++;
            }
            for(int j=0;j<26;j++){
                if(temp==code[j]){
                    cout<<(char)(j+'A');
                }
            }
            if(temp==underscore){
                cout<<'_';
            }
            else if(temp==comma){
                cout<<',';
            }
            else if(temp==period){
                cout<<'.';
            }
            else if(temp==qmark){
                cout<<"?";
            }
            
        }
        cout<<endl;





    }






    return 0;
}

