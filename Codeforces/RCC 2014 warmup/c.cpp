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
	int n,k;
	cin>>n>>k;
	if(n-k-1<k) cout<<-1<<endl;
	else
	{
		int t;

		cout<<n*k<<endl;

		for(int i=1;i<=n;i++)
		{


			t=i+1;
			for(int j=0;j<k;j++)
			{
				if(t>n) t=1;
				cout<<i<<' '<<t++<<endl;

			}
		}
	}


	return 0;
}

