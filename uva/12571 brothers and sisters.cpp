#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	int cases;
	unsigned n,q,a,x[100009];
	unsigned mx,temp;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%u %u",&n,&q);
		for(int i=0;i<n;i++)	scanf("%u",&x[i]);

		while(q--)
		{
			mx=0;
			scanf("%u",&a);

			for(int i=0;i<n;i++)
			{
				temp=a&x[i];
				if(temp>mx) mx=temp;
				if(mx==a) break;
			}
			printf("%u\n",mx);
		}


	}
	return 0;
}
