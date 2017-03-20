//AC
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
#define inf 999999

iii n,m,dpdr[1002][1002],dplu[1002][1002],dpdrd[1002][1002],dpulu[1002][1002],a[1002][1002];
int main()
{
//    ms(dprd,0);
//    ms(dplu,0);
//    ms(dpdrd,0);
//    ms(dpulu,0);



    cin>>n>>m;


    n>m?n++:0;
    cout<<n<<endl;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {

            dpdr[i][j]=a[i][j]+ max(i-1>=0? dpdr[i-1][j]:0 ,j-1>=0?dpdr[i][j-1]:0);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=0;j<m;j++)
        {
            dplu[i][j]=a[i][j]+max(i+1<n?dplu[i+1][j]:0,j-1>=0?dplu[i][j-1]:0);
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        for(int j=m-1;j>=0;j--)
        {
            dpdrd[i][j]=a[i][j]+max(i+1<n?dpdrd[i+1][j]:0,j+1<m?dpdrd[i][j+1]:0);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=m-1;j>=0;j--)
        {
            dpulu[i][j]=a[i][j]+max(i-1>=0?dpulu[i-1][j]:0,j+1<m?dpulu[i][j+1]:0);
        }
    }

    iii mx=0,temp1,temp2;
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<m-1;j++)
        {
//            temp1=((j-1)>=0?dpdr[i][j-1]:-inf)+((j+1)<m?dpdrd[i][j+1]:-inf)+((i+1)<n?dplu[i+1][j]:-inf)+(i-1>=0?dpulu[i-1][j]:-inf);
//            temp2=(i-1>=0?dpdr[i-1][j]:-inf)+(i+1<n?dpdrd[i+1][j]:-inf)+(j-1>=0?dplu[i][j-1]:-inf)+(j+1<m?dpulu[i][j+1]:-inf);
            temp1=dpdr[i][j-1]+dpdrd[i][j+1]+dplu[i+1][j]+dpulu[i-1][j];
            temp2=dpdr[i-1][j]+dpdrd[i+1][j]+dplu[i][j-1]+dpulu[i][j+1];

            temp1=max(temp1,temp2);

            mx=max(mx,temp1);
        }
    }



    cout<<mx<<endl;
    return 0;
}


