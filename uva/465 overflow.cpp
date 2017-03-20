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
long double n1,n2;
int main()
{
//	long long n1,n2;
	long mx=2147483647,mn=-2147483648;
//	cout<<mx;
	char ch,a[10000],b[10000];
	bool num1,num2,num3;
	while(scanf("%s %c %s",a,&ch,b)!=EOF)
	{
		num1=num2=num3=false;
		n1=n2=1;

		int len=strlen(a);
		if(len>10) num1=true;
		sscanf("%Lf",&n1);
		len=strlen(b);
		if(len>10)
		{
			num2=true;
		}
		sscanf("%Lf",&n2);

		if(n1>mx || n1<mn) num1=true;
		if(n2>mx || n2<mn) num2=true;

		if(ch=='+')
		{
			if(n1+n2-mx>0.01 || n1+n2-mn<0.01) num3=true;
		}
		else if(n1*n2-mx>.01 || n1*n2-mn<.01) num3=true;

		printf("%s %c %s\n",a,ch,b);
		if(num1) printf("first number too big\n");
		if(num2) printf("second number too big\n");
		if(num3) printf("result too big\n");



	}
	return 0;
}






