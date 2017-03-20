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
    int n,v,item,temp;
    vector<int> status;

    cin>>n>>v;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        int low=100000009;
        for(int j=0;j<temp;j++)
        {
            cin>>item;
            low=min(low,item);
        }
        if(low<v) status.pb(i);
    }
    cout<<status.size()<<endl;
    for(int i=0;i<status.size();i++)
    {
        cout<<status[i]<<' ';
    }




    return 0;
}

