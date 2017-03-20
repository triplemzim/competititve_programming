//#include<iostream>
//#include<cstdio>
//
//
//using namespace std;
#include<stdio.h>
int main()
{
	long sum,temp1,temp2,temp3,m;



	for(long i=2;i<201;i++)
	{
		temp1=i*i*i;
		temp2=0;

		for(long j=2;temp2<temp1;j++)
		{
			temp2=j*j*j;temp3=0;
			for(long k=j+1;temp3<temp1;k++)
			{
				temp3=temp2+k*k*k;sum=0;
				for(m=k+1;sum<temp1;m++)
				{
					sum=temp3+ m*m*m;

				}
				if(sum==temp1)
				{
					printf("Cube = %ld, Triple = (%ld,%ld,%ld)\n",i,j,k,m-1);

				}
			}

		}
	}

	return 0;
}
