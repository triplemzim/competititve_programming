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
//    freopen("in.txt","r",stdin);
    int n,m,count=0;
    cin>>n>>m;
    int day=1;
    while(n>0)
    {
        count++;
        n--;
        if(day%m==0) n++;
        day++;
    }

    cout<<count<<endl;

    



    return 0;
}
