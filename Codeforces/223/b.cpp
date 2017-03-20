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



int main()
{
	int n,num[100009];
	vector<int> l,r;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>num[i];
	}

	sort(num,num+n);
	int count=1;
	int last=-1;

	int t=0;
	r.pb(num[n-1]);
	t=2;
	last=num[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(last==num[i] && t>0) continue;
		if(last==num[i])
		{
			l.pb(last);
			t++;
			count++;
		}
		else
		{
			r.pb(num[i]);
			last=num[i];
			count++;
			t=0;
		}

	}
	cout<<count<<endl;
	for(int i=l.size()-1;i>=0;i--)
	{
		cout<<l[i]<<' ';
	}
	for(int i=0;i<r.size();i++)
	{
		cout<<r[i]<<' ';
	}







	return 0;
}

