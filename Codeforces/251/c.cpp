/*
 * =====================================================================================
 *
 *       Filename:  c.cpp
 *
 *    Description:  cf_251 c.cpp
 *
 *        Version:  1.0
 *        Created:  শুক্রবার 06 জুন 2014 04:18:25  BDT
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
    int n,k,even,odd;
    cin>>n>>k>>even;
    odd=k-even;


    vector<int> evn;
    vector<int> od;
    for (int  i = 0; i < n; i++) {
        int temp;
        cin>>temp;
        if(temp&1) od.pb(temp);
        else evn.pb(temp);
    }

    bool flag=true;
    if(odd>od.size()) flag=false;
    bool odd_flag=true;
    int cut;
    if((od.size()-odd)%2) flag=false;
    else cut=odd;

    if((od.size()-cut)/2 + evn.size()<even) flag=false;

    if(flag)
    {
        cout<<"YES"<<endl;
        int x=0;
        for (int  i = 0; i < cut-1; i++) {
            printf("1 %d\n",od[i]);
        }
        if(even && cut-1>=0) cout<<1<<' '<<od[cut-1]<<endl;
        else if(even==0)
        {
            cout<<od.size()-cut+1+evn.size();
            for(int i=cut-1;i<od.size();i++) cout<<' '<<od[i];
            for(int i=0;i<evn.size();i++) cout<<' '<<evn[i];
            cout<<endl;
            cut=od.size();
            x=evn.size();
        }
//
//        
//        for(int i=1;cut<od.size() && even;i++)
//        {
//            even--;
//            printf("2 %d %d\n",od[cut++],od[cut++]);     
//        }
        int num;
        num=od.size()-cut+evn.size()-(odd_flag==false?1:0);
        for(int i=1;i<even;i++)
        {
            
            if(cut<od.size())
                printf("2 %d %d\n",od[cut++],od[cut++]);
            else
                printf("1 %d\n",evn[x++]);
        }
        
        num=od.size()-cut+evn.size()-x;
        if(num) {
            cout<<num;
            for(int i=x;i<evn.size();i++)
            {
                cout<<' '<<evn[i];
            }
            for(int i=cut;i<od.size();i++)
                cout<<' '<<od[i];
        }
    }
    else cout<<"NO"<<endl;

    return 0;
}
