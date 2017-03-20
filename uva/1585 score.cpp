#include<stdio.h>
//#include<string.h>
//
//
//int main()
//{char ch[82];
//int cases,total,i,temp,len;
//	scanf("%d",&cases);
//	getchar();
//	while(cases--)
//	{
//		total=0;
//		temp=0;
//
//		gets(ch);
//		len=strlen(ch);
//		for(i=0;i<len;i++)
//		{
//			if(ch[i]=='O') temp++;
//			else {
//			total+=((temp*(temp+1))/2);
//				temp=0;
//			}
//		}
//		printf("%d\n",total+(temp*(temp+1))/2);
//	}
//	return 0;
//}

int main()
{
	char ch;
	int total,temp,cases;
	scanf("%d",&cases);
	while(cases--)
	{
		total=temp=0;
		scanf(" %c",&ch);
		while(ch!=10)
		{
			if(ch=='O') temp++;
			else
			{
				total+=((temp*(temp+1))/2);
				temp=0;
			}
			scanf("%c",&ch);
		}
		printf("%d\n",total+(temp*(temp+1))/2);
	}
	return 0;
}
