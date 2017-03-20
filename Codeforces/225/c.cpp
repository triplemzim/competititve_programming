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
	int cow[200000+9];
	int n;
	cin>>n;
	int r=0;
	for(int i=0;i<n;i++)
	{
		cin>>cow[i];
		if(cow[i]==1) r++;
	}
	long long sum=0;
//	cout<<cow[n-1]<<endl;
	for(int i=n-1;i>=0;i--)
	{
		if(cow[i]==1) r--;
		else
		{
//		cout<<cow[i]<<endl;;
			sum+=r;
		}
	}
	cout<<sum<<endl;


	return 0;
}

