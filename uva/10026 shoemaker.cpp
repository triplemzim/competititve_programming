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

class cl
{
	public:
	int index;
	double time,fine;
	double frac;
	void inp(int i,double a,double b)
	{
		index=i;
		time=a;
		fine=b;
		frac=b/a;
	}
	bool operator<(const cl &x) const
	{
		return frac>x.frac;
	}
};


int main()
{
	int n,cases,t,f;
	cl sh[1009];
	cin>>cases;
	while(cases--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>t>>f;
			sh[i].inp(i+1,t,f);
		}
		sort(sh,sh+n);
		for(int i=0;i<n;i++)
		{
			cout<<sh[i].index;
			if(i!=n-1) cout<<' ';
		}
		cout<<endl;
		if(cases!=0) cout<<endl;
	}

	return 0;
}























