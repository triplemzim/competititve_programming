//AC
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
#define mx 1000000

int main()
{
    vector<int>store;
    int temp,n,num[1000001]={0},used[1000001]={0};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        num[temp]=1;
        store.pb(temp);
    }

    int in=1;
    vector<int>ans;
    for(int i=0;i<store.size();i++)
    {
        if(!used[store[i]])
            if(num[mx-store[i]+1]==0)
            {
                ans.pb(mx-store[i]+1);
            }
            else
            {
                for(in=in;in<mx+1;in++)
                {
                    if(!num[in] && !num[mx-in+1])
                    {
                        ans.pb(in);
                        ans.pb(mx-in+1);
//                        num[in]=num[mx-in+1]=1;
                        used[mx-store[i]+1]=1;
                        in++;
                        break;
                    }
                }
            }
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i]);
    }



    return 0;
}

