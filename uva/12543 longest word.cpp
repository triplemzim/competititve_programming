#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>

using namespace std;

int main()
{
	char cur[10000+10],longest[100+10],temp[1000];
	int len1,len2,len3=0,count=0;
	while(scanf("%s",cur)==1)
	{
		len1=strlen(cur);
		if(len1==5)
		{
			if(strcmp(cur,"E-N-D")==0) break;
		}
		len2=0;
		char c;
		for(int i=0;i<len1;i++)
		{
			c=cur[i];
			if(!(c>='A' && c<='Z') && !(c>='a' && c<='z') && c!='-')
			{
//				cout<<"paici";
				if(len2>len3)
				{
					temp[len2]='\0';
					strcpy(longest,temp);
					len3=len2;
				}
				len2=0;
			}
			else
			{
				temp[len2++]=c;
			}
		}
		if(len2>len3)
		{
			temp[len2]='\0';
			strcpy(longest,temp);
			len3=len2;
		}
	}
	for(int i=0;i<len3;i++)
	{
		printf("%c",tolower(longest[i]));
	}
	printf("\n");

	return 0;
}

