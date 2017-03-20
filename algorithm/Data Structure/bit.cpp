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
#define MAXN 1000
int tree[MAXN],maxval;

void update(int idx,int val)
{
    while(idx<=maxval)
    {
        tree[idx]+=val;
        idx+= (-idx & idx);
    }
}

int read(int idx)
{
    int sum=0;
    while(idx!=0)
    {
        sum+=tree[idx];
        idx-=(idx & -idx);
    }
    return sum;
}

int main()
{
     
    int n;
    int freq[MAXN];

    cin>>n;
    maxval=n;
    for (int  i = 0; i < n; i++) {
        cin>>freq[i];
    }

    for(int i=0;i<n;i++){
        update(i+1,freq[i]);
    }

    for(int i=0;i<n;i++)
    {
        cout<<read(i+1)<<endl;
    }


    return 0;
}
