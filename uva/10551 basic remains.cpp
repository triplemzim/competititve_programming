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
	char p[1010];
	int div[10100],len,base,carry;
	long long mul,num,n,temp;
	while(scanf("%d",&base)==1)
	{
		if(!base) break;
		scanf("%s %lld",p,&num);
		len=strlen(p);
		n=0;temp=1;mul=1;

		while(num)
		{
			temp=num%10;
			n+=(temp*mul);
			mul*=base;
			num/=10;
		}
//		cout<<n<<endl;
		carry=0;
		for(int i=0;i<len;i++)
		{
			temp=((int)p[i]-48) +carry*base;
			carry=temp%n;
		}
		len=0;
		if(!carry) printf("0");
		while(carry)
		{
			div[len++]=carry%base;
			carry/=base;
		}
		for(int i=len-1;i>=0;i--) printf("%d",div[i]);

		cout<<endl;
	}





	return 0;
}





