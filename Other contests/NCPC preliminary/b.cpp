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
#define MOD 100009

iii cal_mod(int len)
{
    iii c=1;
    for(int i=1;i<=len;i++)
    {
        c=c<<1;
        c%=MOD;
    }
    return c;
}


int main()
{
    int n;
    int caseno=1;
//    cout<<cal_mod(1000);
    char ch[1009];
    iii ans=0;
    int len;
    int cases;
    scanf("%d",&cases);
    getchar();
    while(cases--)
    {
        ans=0;
        gets(ch);
        len=strlen(ch);
        iii total_c=cal_mod(len);

        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                if(ch[i]==ch[j])
                {
                    ans+=(1<<(len-j-1));
                    ans%=MOD;
                }
            }
        }

        ans=total_c-ans;
        if(ans<0) ans+=MOD;
        else ans%=MOD;
        printf("Case %d: %lld\n",caseno++,ans);



    }
    return 0;
}

