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
#define scan(i) scanf("%d",&i)
#define MOD 1000000007
iii tree[1000009],maxval;

iii read(int idx)
{
    iii sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(-idx &idx);
    }
    return sum%MOD;
}
void update(int idx,int val)
{
    val%=MOD;
    while(idx<=maxval)
    {
        tree[idx]+=val;
        tree[idx]%=MOD;
        idx+=(-idx &idx);
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    int n,num[100009],in=1,a[100009];
    map<int,int> mp;
    int cases,caseno=1;
    scan(cases);
//    cout<<cases<<endl;
    while(cases--)
    {
        in=1;
        scan(n);
        maxval=n;
        for (int  i = 0; i < n; i++) {
            scan(num[i]);
            a[i]=num[i];
        }
        sort(num,num+n);
        for (int  i = 0; i <n ; i++) {
            if(mp.find(num[i])==mp.end()) mp[num[i]]=in++;
//            cout<<mp[num[i]]<<' ';
        }
//        cout<<endl;

        for(int i=0;i<n;i++)
        {
            update(mp[a[i]],read(mp[a[i]]-1)+1 );
//            cout<<"read: "<<read(mp[a[i]])<<endl;
//            cout<<"index: "<<mp[a[i]]<<endl;
        }
        printf("Case %d: %lld\n",caseno++,read(in-1));
        for (int  i = 0; i < maxval+1; i++) {
            tree[i]=0;
        }
        mp.clear();

    }


    return 0;
}
