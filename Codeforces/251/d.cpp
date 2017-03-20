/*
 * =====================================================================================
 *
 *       Filename:  d.cpp
 *
 *    Description:  cf_251 d.cpp
 *
 *        Version:  1.0
 *        Created:  বৃহস্পতিবার 05 জুন 2014 12:18:21  BDT
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

int bsrch(int len,iii element,iii arr[])
{
    int low=0,high=len-1,mid=(low+high)/2;
    while(low<high)
    {
        if(element>=arr[mid])
        {
            low=mid;
            mid=(low+high)%2?(low+high)/2 +1:(low+high)/2;
        }
        else
        {
            high=mid-1;
            mid=(low+high)/2;
        }
    }
    return mid;
}
iii n,m,a[100009],b[100009];
iii avg[2*100009];
iii summation1[100009],summation2[100009];

int main()
{
    cin>>n>>m;
    for (int  i = 0; i <n ; i++) {
       cin>>a[i];
     }
     sort(a,a+n);
     for (int  i = 0; i < n; i++) {
         
       summation1[i]+=i>0?summation1[i-1]+a[i]:a[i];
    }
    for (int  i = 0; i < m; i++) {
       cin>>b[i];
    }
    sort(b,b+m);
    for (int  i = 0; i < m; i++) {
        
       summation2[i]=i>0?summation2[i-1]+b[i]:b[i];
    }
    iii temp,count=10000000000000000;
    for (int  i = 0; i < n; i++) {
       temp=(a[i]*i)- (i>0?summation1[i-1]:0);
       int index=bsrch(m,a[i],b);
       if(b[index]<a[i]) index++;
        iii dif=0;
        if(a[i]<b[m-1])
        {
            dif=summation2[m-1]-(index>0?summation2[index-1]:0);
            temp+=dif-(a[i]*(m-index));
        }
        
       count=min(temp,count);
    }
    for(int i=0;i<m;i++)
    {
        temp=summation2[m-1]-(i>0?summation2[i-1]:0)-(b[i]*(m-i));
        int index=bsrch(n,b[i],a);
        if(b[i]<a[index]) index--;

        temp+=(b[i]*(index+1)-(index>-1?summation1[index]:0));
        count=min(count,temp);
    }
    cout<<count<<endl;

    return 0;
}
