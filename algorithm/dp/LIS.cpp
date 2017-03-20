#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

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

string s1,s2,s3;
int dir[100],dp[100],start;


int lis(int x)
{
	if(dp[x]!=-1) return dp[x];
	if(x>=s1.length()) return 0;
	int temp=0,MX=1
	;
	for(int i=x+1;i<s1.length();i++)
	{
//		lis(i);
		if(s1[i]>s1[x])
		{
			temp=1+lis(i);
			if(temp>MX)
			{
				MX=temp;
				dir[x]=i;
//				cout<<'a'<<x<<endl;
			}

		}

//		else
//		{
//			temp=lis(i);
//		}
//		if(temp>MX)
//		{
//			MX=temp;
//			dir[x]=i;
//			start=x;
//			cout<<'a'<<x<<endl;
//		}

	}
	return dp[x]=MX;
}


int main()
{

	int LIS=1;
	memset(dp,-1,sizeof(dp));
	memset(dir,-1,sizeof(dir));
	cin>>s1;
int c=1;
	for(int i=0;i<s1.length();i++)
	{
		if(LIS<lis(i))
		{
			LIS=lis(i);
			start=i;
		}
	}

	cout<<LIS<<endl;

//cout<<s1[start]-48<<endl;
	while(start!=-1)
	{
		cout<<s1[start]-48<<' ';
		start=dir[start];
	}


	return 0;
}


















