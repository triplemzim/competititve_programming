#include<bits/stdc++.h>

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


int main()
{
    iii n,k,d;
    bool flag=true;
    cin>>n>>k>>d;
    iii temp=k;
    for(int i=0;i<d && temp<n; i++)
    {
        temp*=k;
    }
    if(temp<n) flag=false;

    if(flag==false) {
        cout<<"-1"<<endl;
        return 0;
    }

    



    return 0;
}
