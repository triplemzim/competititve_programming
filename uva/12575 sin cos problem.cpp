#include<iostream>
#include<cstdio>
#include<cmath>
#define pi acos(-1)

using namespace std;

int main()
{
	int cases;
	double a,b;
	double sq,thita,phi;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%lf %lf",&a,&b);
		sq=sqrt(a*a + b*b);
		thita=atan2(a,b);
//		cout<<thita*180/pi<<endl;


		if(a<0 && b<0) thita+=(2*pi);
		else if(a<0 && b>0) thita=2*pi+thita;
		else if(a==0 && b==0) thita=0;
		else if(a==0)
		{
			if(b>0) thita=0;
			else thita=pi;
		}
		else if(b==0)
		{
			if(a>0) thita=pi/2;
			else thita=3*pi/2;
		}


		printf("%.2lf %.2lf\n",thita,sq);
	}
	return 0;
}
