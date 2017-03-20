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

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long

using namespace std;

long long a[300009]={0};
	long long b[300009],ans[300009];
	vector<long long> v[300009];

int main()
{
	map<long long int,int> mp;
	map<long long int,int> ind;
	int n;

	cin>>n;
	int temp,index=0;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a[i]=temp;
		b[i]=temp;
		ans[i]=temp;
//		mp[temp]++;
		if(ind.find(temp)==ind.end())
		{
			ind[temp]=index++;
		}
		v[ind[temp]].push_back(i);
	}

	sort(b,b+n);
	long long t,last=-1;
	for(int i=0;i<n;i++)
	{
		t=b[i];
//		cout<<t<<endl;
		if(ind[t]!=-1)
		{
//			cout<<ind[t]<<endl;
//			return 0;
			int k=ind[t],x;
			if(t<=last) x=last-t+1;
			else x=0;

			for(int j=0;j<v[k].size();j++)
			{
				ans[v[k][j]]+=x;
				x++;
//				ind[a[v[k][j]]]=-1;
				last=ans[v[k][j]];
			}
			ind[t]=-1;


		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<ans[i]<<" ";
	}


	return 0;
}


//#define sets(n,pos) (n|(1<<pos))
//#define check(n,pos) (bool(n&(1<<pos)))
//#define mx 100000000
//#define lim 10000
//unsigned prime[mx>>6];
//void seive()
//{
//	unsigned k,i,j;
//	prime[2>>6]=sets(prime[2>>6],0);
//	for(i=3;i<lim;i+=2)
//	{
//		if(check(prime[i>>6],((i>>1)&31))==0)
//		{
//			if(i<100) cout<<i<<" ";
//			k=i<<1;
//			for(j=i*i;j<=mx;j+=k)
//			{
//				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
//			}
//		}
//	}
//	return;
//}



