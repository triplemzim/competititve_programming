#include<iostream>
#include<cstdio>
#include<string.h>

using namespace std;

int main()
{
//printf("%c",147);
	int n,caseno=1;
	char str[110];
	while(scanf("%d",&n)==1 && n)
	{
		getchar();
		printf("Case %d:\n",caseno++);
		printf("#include<string.h>\n#include<stdio.h>\nint main()\n{\n");

		for(int i=0;i<n;i++)
		{
			gets(str);

			int len=strlen(str);
			printf("printf(\"");
			for(int k=0;k<len;k++)
			{
				char c=str[k];
				if((int)c==92 || c=='"' || c=='"' )
				{
					printf("\\%c",c);
				}
				else printf("%c",c);
			}


			printf("\\");printf("n");

			printf("\");\n");
		}
		printf("printf(\"\\");
		printf("n");
		printf("\");\n");
		printf("return 0;\n}\n");
	}
	return 0;
}
