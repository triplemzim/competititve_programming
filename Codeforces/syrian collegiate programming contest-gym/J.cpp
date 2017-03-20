#include<bits/stdc++.h>

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


int main()
{
    int test, a, b, c, d;
    int cases=1;
    cin>>test;
    while(test--)
    {
        cin>>a>>b>>c>>d;
        printf("Case %d: ", cases++);
        cout<<c*60+d-a*60-b<<endl;
    }

    return 0;
}
