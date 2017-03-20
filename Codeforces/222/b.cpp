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



int main()
{
	long s1[100009],s2[100009],n,a,b;
	int counta,countb;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s1[i]>>s2[i];
	}
	long lasta=s1[0],lastb=s2[0],ia=0,ib=0;
	for(int i=0;counta+countb<n && i<n;i++)
	{
		if(lasta<lastb)
		{
			counta++;
			lasta=s1[++ia];
		}
		else
		{
			countb++;
			lastb=s2[++ib];
		}
	}
//	cout<<countb<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i<=counta || i<=n/2) cout<<1;
		else cout<<0;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		if(i<=countb || i<=n/2) cout<<1;
		else cout<<0;
	}
	cout<<endl;




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





