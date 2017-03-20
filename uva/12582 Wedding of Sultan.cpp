#include<iostream>
#include<cstdio>
#include<cstring>


using namespace std;

int main()
{
	char ch[20000];
	int count[30]={0},cases,caseno=1;
	scanf("%d",&cases);




	while(cases--)
	{
		bool visited[30]={false};
		scanf("%s",ch);
		int len=strlen(ch);

		visited[(int)ch[0]-65]=true;
		for(int i=1;i<len;i++)
		{
			int sprink=(int)ch[i]-65;
			if(!visited[sprink])
				for(int j=i+1;j<len;j++)
				{
					int n=(int)ch[j]-65;
					if(visited[n]==true)
					{
						count[sprink]++;
						count[n]++;
						break;
					}
				}
			visited[sprink]=true;
		}






		printf("Case %d\n",caseno++);
		for(int i=0;i<26;i++)
			if(count[i])
				printf("%c = %d\n",i+65,count[i]);
		//ch.clear();
		memset(count,0,sizeof(count));
	}
	return 0;
}
