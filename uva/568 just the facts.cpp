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
	int digit[10001],last,n,fact;
	iii temp;
	last=1;
	for(int i=1;i<10001;i++)
	{
		temp=i;
//		while(temp%10==0) temp/=10;


		temp=(last*temp);
		while(temp%10==0) temp/=10;

		temp%=1000000;

		n=temp%10;
//		if(!n) cout<<n;
//		cout<<i<<" "<<temp<<endl;

//		cout<<" "<<last<<endl;
//		while(!n)
//		{
//			temp/=10;
//			n=temp%10;
//		}
		last=temp;
		digit[i]=n;
	}
//		cout<<n<<endl;

	while(scanf("%d",&n)!=EOF)
	{
		printf("%5d -> %d\n",n,digit[n]);
	}










	return 0;
}






