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

int len;
int fnd(char ch[],int idx)
{
    for(int i=idx;i<len;i++)
    {
       if(ch[i]=='#') return i;
    }
   return -1;
} 

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    char ch[100009];


    scanf("%s",ch);

    len=strlen(ch);

    int f=0,l=0;
    vector<int> v;
    bool flag=true;

    for(int i=0;i<len;i++)
    {
        if(ch[i]=='(') f++;
        else if(ch[i]==')') l++;
        else
        {
            int idx=fnd(ch,i+1);
            if(idx==-1)
            {
                int temp=0;
                for(int j=i+1;j<len;j++)
                {
                    if(ch[j]=='(') temp--;
                    else if(ch[j]==')') temp++;
                }
                if(temp<0) temp=0;
                if(f==l || f-l<=temp) 
                {
                    flag=false;
                    break;
                }
                else if(f>l)
                {
                    v.pb(f-l-temp);
//                    cout<<temp<<endl;
//                    cout<<f-l-temp<<endl;
                    l+=f-l-temp;
                }
            }
            else 
            {
                if(f==l)
                {
                    flag=false;
                    break;
                }
                else if(f>l)
                {
                    v.pb(1);
                    l++;
                }
            }
        }

        if(f<l){
            flag=false;
//            cout<<"index"<<i<<endl;
//            cout<<"outside"<<endl;
        }
    }
    if(l!=f) flag=false;

    if(flag==false)
    {
        cout<<-1<<endl;
    }
    else
    {
        for(int i=0;i<(int)v.size();i++)
        {
            cout<<v[i]<<endl;
        }
    }
    






    return 0;
}
