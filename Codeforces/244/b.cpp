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
#define inf 1<<32


iii n,t,c,crime[1000009];
int main()
{
	cin>>n>>t>>c;
	for(int i=0;i<n;i++)
	{
		cin>>crime[i];
	}
//	sort(crime,crime+n);
//	iii r=0, last=-1;
//
//	for(int i=0;i<n;i++)
//	{
//		if(crime[i]!=last && crime[i]<=t)
//		{
//			r++;
//			last=crime[i];
//		}
//	}

	iii ans=0;
	int count=0,last=0;
	for(int i=0;i<n;i++)
	{
		if(crime[i]<=t)
		{
			count++;
		}
		else
		{
			count=0;
		}
		if(count>=c) ans++;
	}
	cout<<ans<<endl;





	return 0;
}

