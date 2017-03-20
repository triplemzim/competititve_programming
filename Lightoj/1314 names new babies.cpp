
/*
 * =====================================================================================
 *
 *       Filename:  sa.cpp
 *
 *    Description:  suffix array
 *
 *        Version:  1.0
 *        Created:  রবিবার 17 আগ 2014 02:19:26  BDT
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

#define MAXN 100000
#define MAXLG 65

struct entry
{
    int nr[2],p;
    bool operator<(const entry a)const
    {
        return a.nr[0]==nr[0] ? (nr[1]<a.nr[1]?1:0):((nr[0]<a.nr[0])?1:0);
    }

}L[MAXN];



char ch[MAXN];
int rank[MAXLG][MAXN];
int len,step;

int suffix_array();
int lcp(int x,int y);

int main()
{
    freopen("in.txt","r",stdin);
    

    int cases,caseno=1,LCP[MAXN];
    cin>>cases;
    int sidx[10009],a,b;
    while(cases--)
    {
        getchar();
        scanf("%s",ch);
        cin>>a>>b;
        suffix_array();
        for(int i=0;i<len;i++)
        {
            sidx[rank[step-1][i]]=i;
        }
        LCP[0]=0;
        for(int i=1;i<len;i++)
        {
            LCP[i]=lcp(sidx[i],sidx[i-1]);
//            cout<<LCP[i]<<' ';
        }
//        cout<<endl;

        int count=len-sidx[0];
        if(count>b) count=b;
        if(count>=a) count-=a-1;
//        cout<<count<<endl;

        for(int i=1;i<len;i++)
        {
            int temp=len-sidx[i];
            int start=LCP[i];
            if(start<a) start=a-1;
            if(temp>b) temp=b;
            if(temp>start) count+=temp-start;
        }
        printf("Case %d: %d\n",caseno++,count);
            
    }
    return 0;
}

int lcp(int x, int y)
{
    int cp=0;

    for(int i=step-1;i>=0 && x<len && y<len;i--)
    {
        if(rank[i][x]==rank[i][y])
        {
            cp+=1<<i;
            x+=1<<i;
            y+=1<<i;
        }
    }
    return cp;
}


int suffix_array()
{
    len=strlen(ch);

    for(int i=0;i<len;i++)
    {
        rank[0][i]=ch[i]-'a';
    }

    int cnt;

    for(cnt=1,step=1;cnt<len;step++,cnt*=2)
    {
        for(int i=0;i<len;i++)
        {
            L[i].nr[0]=rank[step-1][i];
            L[i].nr[1]=i+cnt<len?rank[step-1][i+cnt]:-1;
            L[i].p=i;
        }
        sort(L,L+len);
       

        for(int i=0;i<len;i++)
        {
            rank[step][L[i].p]= i>0 && L[i].nr[0]==L[i-1].nr[0] && L[i].nr[1]==L[i-1].nr[1] ? rank[step][L[i-1].p]:i;
        }
    }
    return step;

}
