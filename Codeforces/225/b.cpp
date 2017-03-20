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

class obj
{
	public:

	int n,index;
	bool operator<(const obj &a)const{ return n<a.n; }
};

int main()
{
	obj num[1001][101];
	int x,i;
	int n,m;
	cin>>n>>m;
	int k;
	cin>>k;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>x;
			num[i][j].n=x;
			num[i][j].index=j+1;
		}
		sort(num[i],num[i]+m);
	}
	vector<PII> v;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{



	return 0;
}

