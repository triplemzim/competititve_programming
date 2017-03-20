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

#define sets(n,pos) (n|(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))
#define mx 2000
#define lim 45
unsigned prime[mx>>6+10];
void seive()
{
	unsigned k,i,j;
	prime[2>>6]=sets(prime[2>>6],0);
	for(i=3;i<mx;i+=2)
	{
		if(check(prime[i>>6],((i>>1)&31))==0)
		{

			k=i<<1;
//			cout<<i<<" ";
			for(j=i*i;j<=mx;j+=k)
			{
				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
			}
		}
	}
	return;
}

int main()
{
	seive();
	char word[25];
	int sum,len;
	while(scanf("%s",word)!=EOF)
	{
		sum=0;
		len=strlen(word);
		for(int i=0;i<len;i++)
		{
			if(word[i]>='a') sum+=(int)word[i]-96;
			else sum+=(int)word[i]-38;
		}

		if(sum>2 && (sum&1)==0)	printf("It is not a prime word.\n");
		else if((sum<4 || check(prime[sum>>6],((sum>>1)&31))==0))	printf("It is a prime word.\n");
		else printf("It is not a prime word.\n");

	}




	return 0;
}





