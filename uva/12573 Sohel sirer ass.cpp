#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int main()
{
	int cases,i;
	scanf("%d",&cases);
	long long div[10000],x,y,m;
	while(cases--)
	{
		scanf("%lld%lld",&x,&y);
		y-=2;
		if(x==y)
		{
			printf("%lld\n",x+1);
			continue;
		}
		if(y==0)
		{
			printf("1\n");
			continue;
		}
		x-=y;
		if(x==y)
		{
			printf("%lld\n",x+1);
			continue;
		}

		if(x<y)
		{
			printf("Impossible\n");
			continue;
		}

		int j=0,sq=sqrt(x);bool flag=false,sqr=false;

		for(i=1;i<sq;i++)
		{
			if(x%i==0)
			{
				div[j++]=i;
//				cout<<i<<endl;
				div[j++]=x/i;
			}
		}
		if(sq*sq==x){sqr=true; div[j++]=sq;}
		else if(x%sq==0)
		{
			div[j++]=sq;
			div[j++]=x/sq;
		}

		for( i=0;i<j;i+=2)
		{
			if(div[i]>y)
			{
				printf("%lld\n",div[i]);
				flag=true;
				break;
			}
		}
		if(sqr) j-=2;
		else j--;
		if(!flag)
			for(i=j;i>0;i-=2)
			{
				if(div[i]>y)
				{
					printf("%lld\n",div[i]);
					break;
				}
			}
	}
	return 0;

}
