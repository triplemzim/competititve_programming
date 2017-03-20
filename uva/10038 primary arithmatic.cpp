#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int main()
{
	unsigned long long num1,num2;
	
	while(scanf("%llu%llu",&num1,&num2)==2)
	{
		if(!num1 && !num2) break;
		
		int rest=0,count=0,sum=0;
		
		while(num1 || num2)
		{
			sum=rest+num1%10+num2%10;
			rest=sum/10;
			if(rest) count++;
			num1/=10;
			num2/=10;
		}
		if(count>1) printf("%d carry operations.\n",count);
		else if(count) printf("%d carry operation.\n",count);
		else printf("No carry operation.\n");
	}
	return 0;
}

