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





int main()
{
	int n,a[3],total=0,x,y,z,cur_len;
	cin>>n>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cur_len=x=y=z=0;

	while(cur_len<=n)
	{
		y=z=0;
		if(cur_len==n){ total=max(total,x+y+z);}
		int b=cur_len;
		while(b<=n)
		{
			z=0;

			if(b==n)
			{
				total=max(total,x+y+z);
			}
			else if((n-b)%a[0]==0)
			{
				z=(n-b)/a[0];
				total=max(total,x+y+z);
			}

			b+=a[1];
			y++;
		}

		cur_len+=a[2];
		x++;
	}

	cout<<total<<endl;
	return 0;
}




