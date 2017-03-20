//#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>


using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

iii cal(iii n)
{
    iii sum=0;
    while(n)
    {
        sum+=(n%10);
        n/=10;
    }
    return sum;
}
int main()
{
//    freopen("in.txt","r",stdin);
    iii a,b,c;
    vector<iii> v; 
//    scanf("%I64d %I64d %I64d",&a,&b,&c);
    cin>>a>>b>>c;
    for(int i=0;i<82;i++)
    {
        
        iii temp=b;
        for (int  j = 0; j < a; j++) {
            temp*=i;
        }
        temp+=c;
        if(cal(temp)==i && temp>0 && temp<1000000000) v.pb(temp);
    }
    printf("%d\n",v.size());
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
//        printf("%I64d ",v[i]); 
        cout<<v[i]<<' ';
    }


    



    return 0;
}
