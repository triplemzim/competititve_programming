/*
 * =====================================================================================
 *
 *       Filename:  ternary_d.cpp
 *
 *    Description:  cf 251 d
 *
 *        Version:  1.0
 *        Created:  শনিবার 07 জুন 2014 02:39:42  BDT
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

iii n,m,k,a[100009],b[100009];
iii calc(iii x)
{
    iii sum=0;
    for(int i=0;a[i]<x && i<n;i++)
    {
       sum+=x-a[i];
    }
    for(int i=m-1;b[i]>x && i>=0;i--)
    {
        sum+=b[i]-x;
    }
    return sum;
}


int main()
{
    cin>>n>>m;
    
    for (int  i = 0; i < n; i++) {
        cin>>a[i];
    }
    for (int  i = 0; i < m; i++) {
       cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    double mn,mx,g,h;
    mn=min(a[0],b[8]);
    mx=max(a[n-1],b[m-1]);
    int count=100;
    while(mx-mn>=.00000000001 && count--)
    {
        g=(mx-mn)/3.0+mn;

        h=mn+2*(mx-mn)/3.0;

        if(calc(g)<calc(h))
        {
            mx=h;
        }
        else mn=g;
    }

    cout<<min(calc(mx),calc(mn))<<endl;


    return 0;
}
