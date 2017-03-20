#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>


using namespace std;

char name[11][25];
int cases,attack[11],defend[11],n,sorted[11];

int flip(int i,int j)
{
	char ch[25];
	strcpy(ch,name[i]);
	strcpy(name[i],name[j]);
	strcpy(name[j],ch);
	int temp;
	temp=attack[i];
	attack[i]=attack[j];
	attack[j]=temp;

	temp=defend[i];
	defend[i]=defend[j];
	defend[j]=temp;
}

int stcmp(int i,int j,int len)
{
//	cout<<(int)name[0][0]<<" "<<(int)name[1][0];
	for(int k=0;k<len;k++)
	{
		if((int)name[i][k]<(int)name[j][k]) return 1;
		else if((int)name[i][k]>(int)name[j][k]) return 0;
	}
	return -1;
}
int main()
{

	int caseno=1;
//	while(1){
//	scanf("%s %s",name[0],name[1]);
//	cout<<stcmp(0,1,min(strlen(name[0]),strlen(name[1])));
//	}
	scanf("%d",&cases);
	while(cases--)
	{
		for(int i=0;i<10;i++)
		{
			scanf("%s%d%d",name[i],&attack[i],&defend[i]);
		}

		for(int i=0;i<9;i++)
		{
			for(int j=i+1;j<10;j++)
			{
				if(attack[i]<attack[j])
				{
					flip(i,j);
				}
				else if(attack[i]==attack[j])
				{
					if(defend[i]>defend[j])
					{
						flip(i,j);
					}
					else if(defend[i]==defend[j])
					{
						int lex=stcmp(i,j,min(strlen(name[i]),strlen(name[j])));
						if(lex==0)
						{
							flip(i,j);
						}
						else if(lex==-1)
						{
							if(strlen(name[i])>strlen(name[j]))
							{
								flip(i,j);
							}
						}
					}
				}

			}
		}

		for(int i=0,j=5;i<4,j<9;i++,j++)
		{
			for(int k=i+1,l=j+1;k<5,l<10;k++,l++)
			{
				int len1=strlen(name[i]),len2=strlen(name[k]);
				int lex=stcmp(i,k,min(len1,len2));
				if(lex==0) flip(i,k);
				else if(lex==-1)
					if(len1>len2) flip(i,k);

				len1=strlen(name[j]),len2=strlen(name[l]);
				lex=stcmp(j,l,min(len1,len2));
				if(lex==0) flip(j,l);
				else if(lex==-1)
					if(len1>len2) flip(j,l);
			}
		}

		printf("Case %d:\n(%s, %s, %s, %s, %s)\n(%s, %s, %s, %s, %s)\n",caseno++,name[0],name[1],name[2],name[3],name[4],name[5],name[6],name[7],name[8],name[9]);
	}
	return 0;
}


