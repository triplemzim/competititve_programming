/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *    Description:  cf 251 b.cpp
 *
 *        Version:  1.0
 *        Created:  রবিবার 08 জুন 2014 06:27:30  BDT
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
    iii n,x,chapter[100009];
    cin>>n>>x;
    for (int  i = 0; i < n; i++) {
        cin>>chapter[i];
    }

    sort(chapter,chapter+n);

    iii sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=(chapter[i]*x);
        if(x>1) x--;
    }
    cout<<sum<<endl;




    return 0;
}
