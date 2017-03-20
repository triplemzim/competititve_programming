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
	int n,m,mat[101][101];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>mat[i][j];
		}
	}

	bool flag=true;

	if(n%2==1) flag=false;

	int a=0,b=n,ans=n;

	while(flag)
	{
		for(int i=0;i<=b/2;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(mat[i][j]!=mat[b-i-1][j])
				{
					flag=false;
					break;
				}
			}
			if(!flag) break;
		}
		b=b/2;
		if(flag)
		{
			ans=b;
		}
		if(b%2==1) flag=false;
	}

	cout<<ans<<endl;

	return 0;
}

