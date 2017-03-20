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

iii tree[1000009],maxval;

int read(int idx)
{
    iii sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(-idx & idx);
    }
    return sum;
}

void update(int idx,iii val)
{
    while(idx<=maxval)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}


iii f[1000009]={0},l[1000009]={0};
int main()
{
   iii sum=0;
    int n;long long array[1000009];
    map<iii,int> mp;
    scanf("%d",&n);
    maxval=n;
    int in=1; 
     for (int  i = 0; i <n ; i++) {
         scanf("%I64d",&array[i]);
         if(mp.find(array[i])==mp.end()) mp[array[i]]=in++;
     }

     iii temp;
     for(int i=n-1;i>=0;i--)
     {
         temp=mp[array[i]];
        f[temp]++;
         
         update(f[temp],1);
     }
     for(int i=0;i<n;i++)
     {

         temp=mp[array[i]];
         if( f[temp]>0)
             update(f[temp]--,-1);
         l[temp]++;
         sum+=read(l[temp]-1);
     }
     cout<<sum<<endl;








    return 0;
}
