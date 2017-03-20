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

int target,m[11],n;
int len[1000009];

int calc(int sum)
{
	len[0]=0;

	for(int i=0;i<n;i++)
	{
		len[m[i]]=1;
	}
	int count=0;
	for(int i=1;i<=sum;i++)
	{
		count=0;
		for(int j=0;j<n;j++)
		{
			int temp=i-m[j];
			if(temp>=0)
			{
				if(len[temp]==0) count++;
			}
		}
		len[i]=count ? 1:0;
	}

	return len[sum];
}
int main()
{

//	freopen("in.txt","r",stdin);
	while(scanf("%d",&target)!=EOF)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",m+i);
		}


		if(calc(target)==1) cout<<"Stan wins"<<endl;
		else cout<<"Ollie wins"<<endl;

	}

	return 0;
}

