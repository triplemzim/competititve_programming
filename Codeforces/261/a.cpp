/*
 * =====================================================================================
 *
 *       Filename:  a.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  শুক্রবার 15 আগ 2014 09:34:04  BDT
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
    int a,b,c,d,A,B,C,D;
    bool flag=true;
    cin>>a>>b>>c>>d;
//    if(abs(a-c)!=abs(b-d) ) flag=false;
    if(a!=c && b!=d)
    {
        
        if(abs(a-c)!=abs(b-d) ) flag=false;
        A=a;
        B=d;
        C=c;
        D=b;
    }
    else if(a==c)
    {
        int dist=abs(b-d);
        B=b;
        D=d;
        if(abs(a+dist)<=1000 && abs(c+dist)<=1000)
        {
            A=a+dist;
            C=c+dist;
        }
        else if(abs(a-dist)<=1000 && abs(c-dist)<=1000)
        {
            A=a-dist;
            C=c-dist;
        }
        else
        {
            flag=false;
        }

    }
    else if(b==d)
    {
        int dist=abs(a-c);
        A=a;
        C=c;
        if(abs(b+dist)<=1000 && abs(d+dist)<=1000)
        {
            B=b+dist;
            D=d+dist;
        }
        else if(abs(b-dist)<=1000 && abs(d-dist)<=1000)
        {
            B=b-dist;
            D=d-dist;
        }
        else flag=false;
    }
    if(flag==false) cout<<-1<<endl;
    else cout<<A<<' '<<B<<' '<<C<<' '<<D<<endl;


    return 0;
}
