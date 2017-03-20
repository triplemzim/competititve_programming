/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  cf 251 a.cpp
 *
 *        Version:  1.0
 *        Created:  রবিবার 08 জুন 2014 06:33:24  BDT
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
    int n,d,time[109];
    cin>>n>>d;
    for (int  i = 0; i < n; i++) {
        cin>>time[i];
    }
    int joke=0;
    bool flag=true;
    d-=time[0];
    for(int i=1;i<n;i++)
    {
        d-=10;
        joke+=2;
        d-=time[i];
        if(d<0) flag=false;
        
    }

    if(d<0) 
    {
        flag=false;
        d=0;
    }
    joke+=(d/5);

    if(flag) cout<<joke<<endl;
    else cout<<-1<<endl;


    return 0;
}
