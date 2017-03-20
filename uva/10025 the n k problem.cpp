#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{

	long long k,n,ans,cases;
	bool flag=true;
	scanf("%d",&cases);
	while(cases--)
	{

		scanf("%lld",&k);
		if(k<0)  k=-k;
		n=(sqrt(1+8*k)-1)/2;
		if(!n) n=1;
		do{
			ans=(n*(n+1))/2;
			n++;
		}while((ans-k) %2!=0 || ans-k<0);
		printf("%lld\n",n-1);
		if(cases!=0) printf("\n");
	}
	return 0;
}

