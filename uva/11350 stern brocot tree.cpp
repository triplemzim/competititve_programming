#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char com[100];
	long long int n,nu,den,r_d,r_n,l_d,l_n;
	bool flag=true;
	scanf("%lld",&n);
	while(n--)
	{
		flag=true;
		scanf("%s",com);
		if(com[0]=='R') flag=false;
		int len=strlen(com);
		if(flag)
		{
			r_n=1;r_d=1;l_d=1;l_n=0;nu=den=1;
		}
		else
		{
			l_n=l_d=r_n=nu=den=1; r_d=0;
		}
			for(int i=0;i<len;i++)
			{
				if(com[i]=='L')
				{
					r_n=nu;r_d=den;
					nu+=l_n;
					den+=l_d;
				}
				else
				{
					l_n=nu;l_d=den;
					nu+=r_n;
					den+=r_d;
				}
			}
			printf("%lld/%lld\n",nu,den);
	}
	return 0;
}
