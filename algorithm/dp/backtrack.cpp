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


int taken[10]={0};
vector<int> v;
int n;

int backtrack(int i)
{
	if(v.size()==4)
	{
		for(int j=0;j<4;j++)	cout<<v[j]<<' ';
		cout<<endl;

	}

	for(int j=0;j<4;j++)
	{
		if(taken[j]==0)
		{
			 v.pb(j);
//			taken[j]=1;
			backtrack(j);
			taken[j]=0;
			v.pop_back();
		}
	}
	return 0;
}


int main()
{
	backtrack(0);



	return 0;
}
