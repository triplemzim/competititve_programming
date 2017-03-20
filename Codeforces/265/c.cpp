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

bool check(string ch,int len,int i,char c)
{
    if(i>0 && ch[i-1]==c) return false;
    if(i>1 && ch[i-2]==c) return false;
//    if(i<len-1 && ch[i+1]==c) return false;
//    if(i<len-2 && ch[i+2]==c) return false;
    return true;
}



int main()
{
    int n,p;
    string ch,store;
    scan(n);
    scan(p);
    cin>>ch;
    store=ch;

    int len=ch.length();

    bool flag=false,notpossible=false,possible=false;

    for(int i=len-1;i>=0;i--){
        for(char j=ch[i]+1;j<p+'a';j++)
        {
//            char c=j;
            if(check(ch,len,i,j)==true){
                ch[i]=j;
                for(int s=i+1;s<len;s++)
                {
                    flag=false;
                    for(char k='a';k<p+'a';k++)
                    {
                        if(check(ch,len,s,k)==true)
                        {
                            ch[s]=k;
                            flag=true;
//                            if(ch[0]=='b') cout<<ch<<endl;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        notpossible=true;
                        break;
                    }
                }
                if(notpossible==false)
                {
                    possible=true;
                    break;
                }
            }
            if(possible) break;
        }
        if(possible) break;
    }

    if(store==ch) ch="NO";


    cout<<ch<<endl;

    /*
    a b c d
    a b d d
    a b d a
    */
                                    
            


            

            
             


    return 0;
}
