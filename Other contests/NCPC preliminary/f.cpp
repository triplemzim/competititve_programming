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
    double len,wid,rad,sq,ans;
    int cases;
    cin>>cases;
    while(cases--)
    {
        cin>>len>>wid;
        cin>>rad;
        sq=len<wid ? len : wid;
        if(rad*2 -sq <=.0000000001) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }


    return 0;
}

