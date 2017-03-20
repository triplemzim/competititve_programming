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

string s;
int len;

vi kmp_table()
{
    vi table(len,0);
    int k=0;
    table[0]=-1;
    k=-1;
    for(int i=1;i<len;i++)
    {
        while(k>-1 && s[k+1]!=s[i])
        {
            k=table[k];
        }
        if(s[k+1]==s[i])
        {
            k++;
        }
        table[i]=k;
    }
    return table;
}

vi track[1000009];

int main()
{
//    freopen("in.txt","r",stdin);
    
    
    cin>>s;
    len=s.length();
    vi v=kmp_table();
    for(int i=0;i<(int)v.size();i++)
    {
//        cout<<v[i]<<' ';
        if(v[i]!=-1) track[v[i]].pb(i);
    }
//    cout<<endl;
//    cout<<"only 2"<<endl;
//    for(int i=0;i<track[2].size();i++)
//    {
//        cout<<track[2][i]<<' ';
//    }
//    cout<<endl
    int mx=v[v.size()-1];
    bool flag=false;
//    cout<<mx<<endl;
    for(int i=mx;i>-1;i--)
    {
        for(int j=0;j<(int)track[i].size();j++)
        {
            if(track[i][j]>0 && track[i][j]<len-1)
            {
//                cout<<track[i][j]<<endl;
                mx=i;
                flag=true;
                break;
            }
        }
        if(flag==false)
        {
//            cout<<mx<<endl;
            mx=v[mx];
//            cout<<mx<<endl;
            if(mx!=-1){
                flag=true;
            }
        }
        break;
    }
    if(flag)
    for(int i=0;i<=mx;i++)
    {
        cout<<s[i];
    }
    else
    {
        cout<<"Just a legend";
    }
    cout<<endl;

    


    return 0;
}
