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
	int n;
	int count[100009]={0};

	int k,x;
	cin>>n;
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		cin>>x>>k;
		if(count[k]<x)
		{
			flag=false;
		}
		else
		{
			if(count[k]==x) count[k]++;
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

	return 0;
}

