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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    string dir,name,shef;

    int goat_x,goat_y,s_x,s_y;

    int n;

    scan(goat_x);
    scan(goat_y);
    cin>>dir;

    bool flag=false;
    if(dir=="UP" || dir=="DOWN"){
        if(dir=="UP") dir="RIGHT";
        else dir="LEFT";
        swap(goat_x,goat_y);
        flag=true;
    }
    scan(n);
    int mn=100000000;
    int a=goat_x;
    int b=goat_y;
    int dif;
    for(int i=0;i<n;i++){
        cin>>name;

        scan(s_x);
        scan(s_y);
        goat_x=a;
        goat_y=b;

        int mov=0;
        if(flag){

            swap(s_x,s_y);
        }


        if(dir=="LEFT" || dir=="RIGHT"){
            mov+=abs(s_y-goat_y)/2+abs(s_y-goat_y)%2;

            


            if(dir=="LEFT"){
                goat_x-=mov;
                if(s_x>goat_x){
                    mov+=s_x-goat_x;
                }
                else{
                    dif=-s_x+goat_x;

                    mov+=dif/3;
                    dif%=3;
                    if(dif==1) mov+=1;
                    if(dif==2) mov+=1;
                }
            }
            else{
                
                goat_x+=mov;
                if(s_x<goat_x){
                    mov+=goat_x-s_x;
                }
                else{
                    dif=abs(s_x-goat_x);

                    mov+=dif/3;
                    dif%=3;
                    if(dif==1) mov+=1;
                    else if(dif==2) mov+=1;

                }
            }
        }
        if(mov<mn){
            mn=mov;
            shef=name;
        }
    }

    cout<<shef<<endl;

               
            



    return 0;
}

