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
int arr[21],dp[21];
int n;
int student[21],track[21],dir[21];

int lis(int x)
{
	if(dp[x]!=-1) return dp[x];
	int temp=0,mx=0;
	for(int i=x+1;i<n;i++)
	{
		if(track[student[x]]<track[student[i]])
		{
			temp=1+lis(i);
			if(temp>mx)
			{
				dir[x]=i;
				mx=temp;
			}
		}
	}
	return dp[x]=temp;
}

int main()
{
	cin>>n;
	bool mark[21];
	for(int i=0;i<n;i++) cin>>arr[i];
	for(int i=0;i<n;i++) track[arr[i]]=i;
	while(cin>>student[0])
	{
		ms(dp,-1);
		ms(mark,false);
		ms(dir,-1);
		for(int i=1;i<n;i++) cin>>student[i];


		int temp=0,mx=0;
		for(int i=0;i<n;i++)
		{
			mx=max(mx,lis(i));
		}
		for(int i=0;i<n;i++)
		{

			if(mx==lis(i))
			{
				int start=i;
				while(start!=-1)
				{
					mark[start]=true;
					start=dir[start];
				}
			}
		}
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(mark[i]==true) count++;
		}
		cout<<count<<endl;
	}



	return 0;
}

