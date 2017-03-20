#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>

using namespace std;


int main()
{
	char ch[100];
	int ans[100];
	unsigned long long sum;
	while(scanf("%s",ch)==1)
	{
		if(ch[0]=='-') break;
		sum=0;int k=0;
		int len=strlen(ch);
		if(len>2 && ch[0]=='0' && ch[1]=='x'){

			for(int i=len-1;i>1;i--)
			{
				if(ch[i]>='A') sum=sum+ ((int)ch[i]-55) * pow(16,k++); 
				else sum=sum + ((int)ch[i]-48) * pow(16,k++);
				
			}
			
			
		
		printf("%llu",sum);
		}
		else
		{
			printf("0x");
			for(int i=0;i<len;i++)
			{
				sum=sum*10+(int) ch[i]-48;
			}
			
			while(sum)
			{
				ans[k++]=sum%16;
				sum/=16;
			}
			for(int i=k-1;i>=0;i--)
			{
				if(ans[i]<10) printf("%d",ans[i]);
				else printf("%c",ans[i]+55);
			}
		}
		
		printf("\n");
	}
	return 0;
}		
