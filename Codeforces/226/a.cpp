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
int n,c,x[110];
	cin>>n>>c;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	int total=0,temp=0;
	for(int i=1;i<n;i++)
	{
		if(x[i]+c<x[i-1])
		{
			total=(x[i-1]-x[i]-c);
			if(total>temp) temp=total;
		}
	}
	cout<<temp<<endl;



	return 0;
}
