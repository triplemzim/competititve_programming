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

vi kmp_table(vi elephant)
{
    int len=elephant.size();
    vi table(len+1,0);
    int k=0;
    for(int i=2;i<len;i++)
    {
        while(k>0 && elephant[i]!=elephant[k+1]) k=table[k];
        if(elephant[i]==elephant[k+1]) k++;
        table[i]=k;
    }
    return table;
}


int kmp(vi bear,vi elephant)
{
    int len=bear.size(),len2=elephant.size(),k=0,count=0;
    vi table=kmp_table(elephant);
//    for(int i=0;i<(int) table.size();i++)
//    {
//        cout<<table[i]<<' ';
//    }
//    cout<<endl;
    for(int i=1;i<len;i++)
    {
        while(k>0 && bear[i]!=elephant[k+1]) k=table[k];

        if(bear[i]==elephant[k+1]) k++;
        if(k==len2-1) 
        {
            count++;
            k=table[k];
        }
    }
    return count;
}

int main()
{
//    freopen("in.txt","r",stdin);
    
    
    int b,e;
    vi bear,elephant;
    int B[1000000],E[1000000];
    scan(b);
    scan(e);
     for (int  i = 0; i <b ; i++) {
         scan(B[i]);
//         cout<<B[i]<<' ';
     }
//     cout<<endl;
     for (int  i = 0; i < e; i++) {
         scan(E[i]);
//         cout<<E[i]<<' ';

     }
//     cout<<endl;

     int count=0;
     bear.pb(0);
     elephant.pb(0);
     if(e==1) count++;
//     bear.pb(B[0]);
//     elephant.pb(B[0]);
     

     

     for(int i=1;i<b;i++)
         bear.pb(B[i]-B[i-1]);
     for(int i=1;i<e;i++)
         elephant.pb(E[i]-E[i-1]);
         
//      for(int i=0;i<(int)elephant.size();i++)
//      {
//          cout<<elephant[i]<<' ';
//      }
//      cout<<endl;
//      cout<<elephant.size()<<endl;
          
     count+=kmp(bear,elephant);
     cout<<count<<endl;




    return 0;
}
