/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  শুক্রবার 15 আগ 2014 10:10:08  BDT
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Shadow_Crawler (Zim), triplemzim@gmail.com
 *        Company:  BUET
 *
 * =====================================================================================
 */

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
    int n;
    iii a[1000009];

    cin>>n;
    for (int  i = 0; i < n; i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    iii mx=a[n-1]-a[0];
    iii low=0,high=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[0]) low++;
        if(a[i]==a[n-1]) high++;
    }
    iii ans=0;
    if(a[0]==a[n-1])
    {
        ans=high*(high-1);
        ans/=2;
    }
    else
        ans=high*low;

    cout<<mx<<' '<<ans<<endl;



    return 0;
}
