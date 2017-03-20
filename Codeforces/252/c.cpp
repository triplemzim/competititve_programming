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
    int n,m,k;
    cin>>n>>m>>k;

    int row=1,col=0;
    int r_count=0,c_count=0;
    for(int i=1;i<k;i++)
    {
        cout<<2<<' ';
        for(int k=0;k<2;k++)
        {

        if(row%2) col++;
        else col--;
        if(col==m+1)
        {
            col=m;
            row++;
        }
        else if(col<1)
        {
            col=1;
            row++;
        }

        cout<<row<<' '<<col<<' ';
        }
        cout<<endl;

    }

    int num=0;

    if(row%2==0)
    {
        num+=col-1;
    }
    else
    {
        num+=(m-col);
    }

    num+=((n-row)*m);

    cout<<num<<' ';

    for(int i=0;i<num;i++)
    {
        if(row%2) col++;
        else col--;
        if(col==m+1)
        {
            col=m;
            row++;
        }
        else if(col<1)
        {
            col=1;
            row++;
        }
        cout<<row<<' '<<col<<' ';
    }






    return 0;
}

