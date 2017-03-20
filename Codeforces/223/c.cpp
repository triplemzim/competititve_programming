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

class s
{
	public:
	iii index;
	int val;
	bool type;
}
s seq[100009];
int len;

iii bsrc(iii in)
{
	int r=len,l=0;
	while(1)
	{
		if(seq[r-1].index<=in && seq[r].index>=in) return r;
		if(seq[l+1].index>=in && seq[l].index<=in) return l;

		if(in>seq[r].index)
		{
			l=r;
			r*=2;
		}
		else if(in<seq[l].index)
		{
			r=l;
			l/=2;
		}
		else if

int find_in(iii in)
{
	iii cur=bsrc(in);

int main()
{
	iii x,temp,c,l,t;
	cin>>n;
	iii in=1;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x;
			seq[i].val=x;
			seq[i].index=in++;
			seq.type=false;
		}
		else
		{
			cin>>l>>c;
			seq[i].type=true;
			in+=(in*c);
			seq[i].index=in++;
		}
	}
	len=in-1;
	cin>>x;
	while(x--)
	{
		cin>>temp;
		cout<<find_in(temp)<<endl;
	}




	return 0;
}

