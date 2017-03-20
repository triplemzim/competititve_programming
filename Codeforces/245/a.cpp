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
	int n,cordinate,x,y,dist[102];
	cin>>n>>cordinate;
	for(int i=0;i<n;i++)
	{
		cin>>dist[i];
	}
	for(int i=0;i<cordinate;i++)
	{
		cin>>x>>y;
	}
	cout<<'0'<<' ';
	bool flag=true;
	for(int i=1;i<n;i++)
	{
		if(abs(dist[i]-dist[i-1])<=1)
		{
			if(flag==true)
			{
				cout<<'1'<<' ';
				flag=false;
			}
			else
			{
				cout<<'0'<<' ';
				flag=true;
			}
		}
		else {cout<<'0'<<' ';flag=false;}
	}



	return 0;
}

