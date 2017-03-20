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

int main()
{
	int n,m,i,j,a,b;
	cin>>n>>m>>i>>j>>a>>b;

	bool flag=false;
	int pos_j=-1,pos_i=-1,neg_i=-1,neg_j=-1;
	if((n-i)%a==0)
	{
		pos_i=(n-i)/a;
	}
	if(i%a==1)
	{
		neg_i=i/a;
	}
	if((m-j)%b==0)
	{
		pos_j=(m-j)/b;
	}
	if(j%b==1)
	{
		neg_j=j/b;
	}

	long mx=-1,temp=2147483640;
	if((i==1 || i==n) && (j==1 || j==m))
	{
		cout<<0<<endl;
		return 0;
	}
	if(pos_j!=-1)
	{
		if(pos_i!=-1)
		{
			if(pos_j%2==pos_i%2)
			{
				flag=true;
				mx=max(pos_j,pos_i);

			}
		}
		if(mx!=-1) temp=mx;
		if(neg_i!=-1)
		{
			if(pos_j%2==neg_i%2)
			{
				flag=true;
				mx=max(pos_j,neg_i);
			}
		}
	}
	if(mx!=-1) temp=min(temp,mx);
	if(neg_j!=-1)
	{
		if(pos_i!=-1)
		{
			if(neg_j%2==pos_i%2)
			{
				flag=true;
				mx=max(neg_j,pos_i);
			}
		}
		if(mx!=-1)temp=min(temp,mx);
		if(neg_i!=-1)
		{
			if(neg_j%2==neg_i%2)
			{
				flag=true;
				mx=max(neg_j,neg_i);
			}
		}
	}
	if(mx!=-1) temp=min(temp,mx);
if(flag) cout<<temp<<endl;
else cout<<"Poor Inna and pony!"<<endl;



	return 0;
}






