
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#define iii unsigned long long
using namespace std;


//int mul(iii a[][2],iii b[][2]){}
iii cur[2][2];
iii a,b,c,d,temp;

void matmul(iii n,int d);
iii mul(iii n)
{
	if(n==1) return 1;
	if(n%2==1)
		matmul(mul(--n),1);
	else {n/=2;  matmul(mul(n),0);}
}


void matmul(iii n,int d)
{

//	if(n==1) return 1;


	if(d==1)
	{
//		n--;
		a=cur[0][0]%temp;b=cur[0][1]%temp;c=cur[1][0]%temp;d=cur[1][1]%temp;
//		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		cur[0][0]=(a+b)%temp;
		cur[0][1]=a;
		cur[1][0]=(c+d)%temp;
		cur[1][1]=c;
//		cout<<n<<endl;
	}
	else
	{
//		n=n>>1;
		a=cur[0][0]%temp;b=cur[0][1]%temp;c=cur[1][0]%temp;d=cur[1][1]%temp;

//		cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		cur[0][0]=(a*a+b*c)%temp;
		cur[0][1]=(a*b+b*d)%temp;
		cur[1][0]=(c*a+d*c)%temp;
		cur[1][1]=(c*b+d*d)%temp;
//		cout<<n<<endl;

	}

	return;
}


int main()
{



	iii s;

	iii n,t;

	while(scanf("%llu%llu",&n,&t)==2)
	{
		if(t==0)
		{
			printf("0\n");
			continue;
		}
		if(n<3)
		{
			if(n==0)
				printf("0\n");
			else if(n==1)
				printf("1\n");
			else
				printf("1\n");
			continue;
		}
		n-=2;
//		if(n%2==1) n--;
//		i=j=k=1;l=0;
		cur[0][0]=cur[0][1]=cur[1][0]=1;cur[1][1]=0;
		temp=(iii)pow(2,t);
		mul(n);

//		i=cur[0][0];j=cur[0][1];


		s=(cur[0][0] + cur[0][1])%temp;
		printf("%llu\n",s);
	}
	return 0;
}
