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
	cin>>n;
	if(n%2==1)
	{
		cout<<(n*n)/2+1<<endl;
	}
	else cout<<(n*n)/2<<endl;

	bool flag;
	for(int i=1;i<=n;i++)
	{
		if(i%2==1) flag=false;
		else flag=true;
		for(int j=1;j<=n;j++)
		{
			if(flag)
			{
				flag=false;
				cout<<'.';
			}
			else
			{
				flag=true;
				cout<<'C';
			}
		}
		cout<<endl;
	}




	return 0;
}

