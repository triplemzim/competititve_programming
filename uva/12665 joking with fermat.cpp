#include<iostream>
#include<cstdio>
#include<cmath>
#define iii unsigned long long
#include<cstring>
using namespace std;

//iii min(iii a,iii b)
//{
//	if(a>b) return b;
//	else return a;
//}
//iii max(iii a, iii b)
//{
//	if(a>b) return a;
//	else return b;
//}

int main()
{
	iii low,high,dif,lim;
	iii inc,total[11];
	int first_d,last_d,caseno=1;
	while(scanf("%llu%llu",&low,&high)==2)
	{
		memset(total,0,sizeof(total));
		first_d=low%10;
		lim=cbrt(high);
		last_d=lim%10;
		dif=high-low;

		if(dif<=132)
		{
			printf("Case %d: 0\n",caseno++);
			continue;
		}
		else
		{
			for(int i=min(first_d,last_d);i<=max(first_d,last_d);i++)
			{
				total[i]++;
			}
			inc=(lim-low)/10;
			for(int i=0;i<10;i++)
			{
				total[i]+=inc;
			}
		}
		inc=min(total[1],total[8])+min(total[2],total[5])+min(total[3],total[6])+min(total[4],total[9])+min(total[7],total[0]);
		printf("Case %d: %llu\n",caseno++,inc);
	}
	return 0;
}
