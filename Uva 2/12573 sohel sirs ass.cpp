//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#define set(n,pos) (n|(1<<pos))
//#define check(n,pos) bool(n & (1<<pos))
//#define size 100000000
//#define lim 10000
//
//using namespace std;
//
//unsigned status[size>>6];
//
//int main()
//{
//	unsigned i,j,k;
//
//	for(i=3;i<lim;i+=2)
//	{
//		if(check(status[i>>6],((i>>1)&31))==0)
//		{
////			if(i<100) cout<< i<<endl;
//			k=i<<1;
//			for(j=i*i;j<=size;j+=k)
//			{
//				status[j>>6]=set(status[j>>6],((j>>1)&31));
//			}
//		}
//	}
//
//	int cases;
//	long long n,y,x,div,st;
//	bool prime,flag,posib;
//
//	scanf("%d",&cases);
//	while(cases--)
//	{
//		scanf("%lld%lld",&n,&y);
//		y-=2;
//		posib=true;
//		flag=true;
//		if(n==y)
//		{
//			div=n+1;
//		}
//		else if(n-y<y) posib=false;
//		else
//		{
//			n-=y;
//			if((y&1)==1) st=y;
//			else st=y+1;
////			cout<<n<<" "<<y<<endl;
//			if((n&1)==1)
//			{
//				if(n<size && check(status[(unsigned)n>>6],((unsigned)(n)>>1)&31)==0)
//				{
//					if(1>y) div=1;
//					else div=n;
//				}
//				else
//				{
//					div=1;
//					for(i=3;div<=y;i+=2)
//					{
//
//						if(i<size && check(status[(unsigned)(i)>>6],((unsigned)(i)>>1)&31)==0)
//						{
//
//							while(n%(div*i)==0 && div<=y)
//								div*=i;
//
//						}
//						else
//							while(n%(div*i)==0 && div<=y)
//								div*=i;
//
//					}
//				}
//			}
//			else
//			{
//				div=1;
//				while(n%(div<<1)==0 && div<=y)
//					div=div<<1;
//
//				for(i=3;div<=y;i+=2)
//				{
//					if(i<size && check(status[(unsigned)(i)>>6],((unsigned)(i)>>1)&31)==0)
//					{
//
//						while(n%(div*i)==0 && div<=y)
//							div*=i;
//
//					}
//					else
//						while(n%(div*i)==0 && div<=y)
//							div*=i;
//
//
//				}
//			}
//		}
//		if(posib)
//		{
//			printf("%lld\n",div);
//		}
//		else printf("Impossible\n");
//	}
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	int cases;
	long long n,y,div,s;
	bool posib,flag;
	scanf("%d",&cases);
	while(cases--)
	{
		posib=true;
		scanf("%lld%lld",&n,&y);
		y-=2;
		if(n==y)
		{
			div=n+1;
		}
		else if(n-y<y) posib=false;
		else
		{
			n-=y;
			div=1;
			int sq=n/2;
			for(s=y+1;div<=y && s<=sq;s++)
			{
				if(n%s==0 && s>y)
				{
					div=s;
					break;
				}
			}
			if(div<=y && div==1) div=n;
		}
		if(posib) printf("%lld\n",div);
		else printf("Impossible\n");
	}
	return 0;
}
