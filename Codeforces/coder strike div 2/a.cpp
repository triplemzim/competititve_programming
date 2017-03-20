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
	int apple[110],a[110],b[110];
	ms(a,-1);ms(b,-1);
	int temp,n,x,y;
	cin>>n>>x>>y;
	for(int i=0;i<x;i++)
	{

		cin>>temp;
		apple[temp]=1;
	}

	for(int i=0;i<y;i++)
	{
		cin>>temp;
		apple[temp]=2;
	}
	for(int i=0;i<n;i++)
	{
		if(apple[i+1]<0) cout<<1<<' ';
		else cout<<apple[i+1]<<' ';
	}


	return 0;
}

