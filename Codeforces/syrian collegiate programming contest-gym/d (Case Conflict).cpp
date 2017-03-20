#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

using namespace std;

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999



int test, cases=1;
ull tshirts[100006], n, d, c;

int main()
{
    cin>>test;
    while(test--)
    {
        cin>>n>>d>>c;
        for (int i=1; i<=n; i++)
        {
            cin>>tshirts[i];
        }
        sort(tshirts+1,tshirts+n+1);
        ull ans=10000000000000000;
        for (ull i=1; i<=n; i++)
        {
            ull x=(tshirts[i]*c*i);
            x+=((n-i)*d);
            ans=min(ans,x);
        }
        printf("Case %d: ", cases++);
        cout<<ans;
        if(test!=0) cout<<endl;
    }


    return 0;
}

