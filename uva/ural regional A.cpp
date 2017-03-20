#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>

using namespace std;


 int main()
 {
	int num[100009];
	long long sum1=0,sum2=0,in1,in2,initial1,initial2,up1,up2;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}

	scanf("%d%d",&in1,&in2);

	if(in1>in2)
	{
		initial1=ceil((in1+in2)/2);

		if(initial1*2<in1+in2) initial1++;

//		cout<<initial1<<endl;

		for(int i=initial1;i<=n;i++)
		{
			sum1+=num[i];
		}
		for(int i=initial1-1;i>0;i--)
		{
			sum2+=num[i];
		}
	}
	else if(in1<in2)
	{
		initial1=(in1+in2)/2;

		for(int i=1;i<=initial1;i++)
		{
			sum1+=num[i];
		}
		for(int i=initial1+1;i<=n;i++)
		{
			sum2+=num[i];
		}
	}

	printf("%lld %lld\n",sum1,sum2);

	return 0;

}
