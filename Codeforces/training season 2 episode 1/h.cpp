/*
 * =====================================================================================
 *
 *       Filename:  h.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  বৃহস্পতিবার 11 সেপ্টে 2014 10:17:55  BDT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shadow_Crawler (Zim), triplemzim@gmail.com
 *        Company:  BUET
 *
 * =====================================================================================
 */

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


int main()
{
    freopen("in.txt","r",stdin);
    
    
    int n,k;

    PII temp,store[1010];
    cin>>k>>n;
    int a,b;
    for (int  i = 0; i < n; i++) {
        cin>>a>>b;
        if(a>b) store[i]=MP(b,a);
        else store[i]=MP(a,b);

    }

    sort(store,store+n);
//    for (int  i = 0; i < n; i++) {
//        cout<<store[i].first<<' '<<store[i].second<<endl;
//    }
//    cout<<"shesh";

    map<int,bool> mp;
    vi v;

    for(int i=0;i<n;i++)
    {
        int start=store[i].second,finish=store[i].first;
        int count=0,idx=finish;
        for(int i=start;i<finish+1;i++)
        {
            if(mp.find(i)!=mp.end()) count++;
        }
        for(int i=count;i<k+1;i++)
        {

    }

    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for (int  i = 0; i < (signed)v.size(); i++) {
//        cout<<v[i]<<endl;
    }







    return 0;
}
