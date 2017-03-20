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
int fnd(int num[],int n)
{
    int mn=num[0],pos=0;

    for (int  i = 0; i < n; i++) {
        if(mn>num[i])
        {
            pos=i;
            mn=num[i];
        }
    }
    return pos;
}
        
    

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    char ch[1009];
    int len,n,num[1009];

    cin>>n;
    getchar();
    scanf("%s",ch);
    len=strlen(ch);

    int temp[1009];
    for(int i=0;i<len;i++)
    {
        num[i]=ch[i]-'0';
        temp[i]=num[i];
    }

    int tempo[1009];
    for(int i=0;i<n;i++)
    {
        int dif=10-num[i];
        for(int j=i;j<i+n;j++)
        {
            tempo[j-i]=(num[j%n]+dif)%10;
//            cout<<tempo[j-i];
        }
//        cout<<endl;
        for(int j=0;j<n;j++)
        {
            if(temp[j]>tempo[j])
            {
                for(int k=0;k<n;k++)
                {
                    temp[k]=tempo[k];
                }
                break;
            }
            else if(temp[j]<tempo[j]) break;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<temp[i];
    }
    cout<<endl;




    

        





    return 0;
}
