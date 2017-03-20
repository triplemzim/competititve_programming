//AC
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

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

int n,a,b,num[210],interval[210],other[210],k;

void get_array(int i,int j)
{
    int in=0;
    for(int x=i;x<=j;x++)
    {
        interval[in++]=num[x];
    }
    sort(interval,interval+in);
    a=in;
    in=0;
    for(int x=0;x<i;x++)
    {
        other[in++]=num[x];
    }
    for(int x=j+1;x<n;x++)
    {
        other[in++]=num[x];
    }
    sort(other,other+in);
    b=in;
}

int calc()
{
    int count=0,temp=0,in1=0,in2=b-1;
    for(int i=0;i<a;i++)
    {
        if(in2>=0 && count<k && interval[i]<other[in2])
        {
            temp+=other[in2--];
            count++;
        }
        else {
            temp+=interval[i];
        }
    }
    return temp;
}


int main()
{
    int temp=0,mx=-(1<<24);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            get_array(i,j);
            temp=calc();

            mx=max(mx,temp);
        }
    }

    cout<<mx<<endl;



    return 0;
}
