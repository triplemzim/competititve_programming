/*
 * =====================================================================================
 *
 *       Filename:  1080_binary_simulation.cpp
 *
 *    Description:  lightoj
 *
 *        Version:  1.0
 *        Created:  মঙ্গলবার 19 আগ 2014 12:22:51  BDT
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

int maxval,tree[100009];

void update(int idx,int val)
{
    while(idx<=maxval)
    {
        tree[idx]+=val;
        idx+=(-idx & idx);
    }
}
int read(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(-idx & idx);
    }
    return sum;

}

int main()
{
//    freopen("in.txt","r",stdin);
    int caseno=1;
    int len;
    char bin[100009];
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        ms(tree,0);
        printf("Case %d:\n",caseno++);
        scanf("%s",bin);
        len=strlen(bin);
        maxval=len;
//        for(int i=0;i<len;i++)
//        {
//            if(bin[i]=='1') update(i+1,1);
//        }
        int q,i,j;
        char ch;
        scanf("%d",&q);
        while(q--)
        {
            scanf(" %c",&ch);
            if(ch=='Q')
            {
                scanf("%d",&i);
//                cout<<(read(i)-read(i-1))%2<<endl;
               printf("%d\n",(read(i)+bin[i-1])%2);
            }
            else
            {
                scanf("%d %d",&i,&j);
//                cout<<"original: ";
//                for(int a=1;a<=len;a++)
//                {
//                    cout<<read(a)<<' ';
//                }
//                cout<<endl;

                update(i,1);
//                cout<<"increasing... : ";
//                for(int a=1;a<=len;a++)
//                {
//                    cout<<read(a)<<' ';
//                }
//                cout<<endl;
                update(j+1,-1);
//                cout<<"decreasing... :";
//                for(int a=1;a<=len;a++)
//                {
//                    cout<<read(a)<<' ';
//                }
//                cout<<endl;
            }
        }
    }



    return 0;
}
