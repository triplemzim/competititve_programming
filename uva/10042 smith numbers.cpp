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

	long n,m,temp,div,factor,sum,num,cases,sq;
	bool flag=true;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%ld",&n);

		flag=true;
		while(flag)
		{
			sum=m=factor=0;

			temp=++n;
			sq=sqrt(n);
			while(temp)
			{
				m+=(temp%10);
				temp/=10;
			}
			temp=n;
			if(n==2) factor--;
			while(temp%2==0)
			{
				factor++;
				sum+=2;
				temp/=2;
			}

			div=3;
			while(temp>1 && div<=sq)
			{
				while(temp%div==0)
				{
					num=div;
					factor++;
					while(num)
					{
						sum+=(num%10);
						num/=10;
					}
					temp/=div;

				}
				div+=2;
			}
			if(temp>1)
			while(temp)
			{
				sum+=(temp%10);
				temp/=10;
			}
//			cout<<sum<<endl;
			if(sum==m && factor>0)
			{
				printf("%ld\n",n);
				flag=false;
			}
//			else printf("It is not\n");
		}
	}








	return 0;
}






