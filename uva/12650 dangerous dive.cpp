#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n,r,s;
	while(scanf("%d%d",&n,&r)==2)
	{
		if(n==r)
		{

			while(r--)
			{
				scanf("%d",&s);
			}
			printf("*\n");
		}
		else
		{
			int divers[10010]={0};

			while(r--)
			{

				scanf("%d",&s);
				divers[s]=1;
			}
			for(int i=1;i<=n;i++)
			{
				if(!divers[i]) printf("%d ",i);
			}
			printf("\n");
		}
	}
	return 0;
}
