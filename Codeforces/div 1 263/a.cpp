#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define print(x) printf("debug= %d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vecotr<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

int n,num[1000009];
iii tree[1000009];


int update(int i)
{
    int temp=num[i];
    while(i<=n)
    {
        tree[i]+=temp;
        i+=(i & -i);
    }
    return 0;
}

iii read(int i)
{
    iii sum=0;
    while(i>0)
    {
        sum+=tree[i];
        i-=(i&-i);
    }
    return sum;
}

iii calc(int a,int b)
{
    if(a==b) return num[a];
    if(a>b) return 0;

    iii sum=0;
    sum=read(b)-read(a-1);
    cout<<sum<<endl;
    int middle=(a+b)/2;
    sum+=calc(a,middle) + calc(a+middle+1,b);

    return sum;
}

int main()
{
    cin>>n;
    iii total=0;
    for (int  i = 0; i < n; i++) {
        cin>>num[i+1];
        total+=num[i+1];
    }

    iii sum=total;
    sort(num+1,num+n+1);
    for(int i=1;i<=n;i++)
    {
        sum+=total;
        total-=num[i];
    }
    sum-=num[n];
    cout<<sum<<endl;

    return 0;
}
