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
#define inf 999999999999999


int main()
{
    iii n,m,dist[1000009];
    dist[1]=0;
    scanf("%I64d %I64d",&n,&m);
    int div= n/m;
    div= div%2==0 ? (div/2) * m : ((div+1)/2) * m;

//    cout<<div<<endl;
    iii answer=0,ans_point=inf;
    if(n%m!=0) div++ ;
//    else div+=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&dist[i]);
        if(i==div) ans_point=dist[i];
    }
    if(n<=m)
    {
        answer+=(dist[n]-dist[1])*2;
    }
    else
    {
        for(int i=1;dist[i]<ans_point;i+=m)
        {
            answer+=(-dist[i]+ans_point)*2;
        }
        for(int i=n;dist[i]>ans_point;i-=m)
        {
            answer+=(dist[i]-ans_point)*2;
        }
    }
    printf("%I64d\n",answer);





    return 0;
}
