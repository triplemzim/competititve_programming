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
    int n,v,fruit[3009],x[3009]={0};
    ms(fruit,0);
    cin>>n>>v;
    int a,b;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        fruit[a]+=b;
    }

    int sum=0;
    int temp=0;
    for(int i=0;i<=3001;i++)
    {
        temp=min(x[i],v);
        x[i+1]=max(fruit[i]+temp-v,0);
        if(fruit[i]+temp>v)
        {
            sum+=v;
        }
        else sum+=fruit[i]+temp;

    }
    cout<<sum<<endl;



    return 0;
}

