#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;
int len;
char q[510];
void shift()
{
	for(int i=1;i<len;i++)
		q[i-1]=q[i];
	q[len-1]='\0';

}


int main()
{



	int cases,count,n,k,caseno=1;
	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%d%d",&n,&k);
		count=0;
		q[0]='\0';
		getchar();
		char c;
		scanf("%c",&c);
		len=0;
		while((int)c!=10)
		{
//			cout<<len<<endl;
			if(len>k){ shift();len--;}
			for(int i=0;i<len;i++)
			{
				if(c==q[i])
				{
					count++;
					break;
				}
			}
			q[len++]=c;
			scanf("%c",&c);
		}
		printf("Case %d: %d\n",caseno++,count);
	}

	return 0;
}
