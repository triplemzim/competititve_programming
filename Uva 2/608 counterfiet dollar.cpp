#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>

using namespace std;


int main()
{

	char c[5],s1[15],s2[15];
	map<char,char> m;
	map<char,char>::iterator it;

	int cases;
	scanf("%d",&cases);

	while(cases--)
	{
		scanf("%s%s%s",s1,s2,c);

		if(c[0]=='e')
		{
			for(int i=0;i<strlen(s1);i++)
			{
				m[s1[i]]='e';
				m[s2[i]]='e';
			}
		}
		else
		{
			char right,left;
			right=c[0];
			if(right=='u') left='d';
			else left='u';

			for(int i=0;i<strlen(s1);i++)
			{
				m[s1[i]]=left;
				m[s2[i]]=right;
			}
		}
		for(int s=0;s<2;s++)
		{
			scanf("%s%s%s",s1,s2,c);
			if(c[0]=='e')
			{
				for(int i=0;i<strlen(s1);i++)
				{
					m[s1[i]]='e';
					m[s2[i]]='e';
				}
			}
			else
			{
				char right,left;
				right=c[0];
				if(right=='u') left='d';
				else left='u';


				for(int i=0;i<strlen(s1);i++)
				{
					if(m[s1[i]]!='e')
					{
						if(right==m[s1[i]]) m[s1[i]]='e';
						else m[s1[i]]=left;
					}
					if(m[s2[i]]!='e')
					{
						if(left==m[s2[i]]) m[s2[i]]='e';
						else m[s2[i]]=right;
					}
				}
				for(it=m.begin();it!=m.end();it++)
				{
					if((*it).second!='e')
					{
						bool flag=true;

						for(int i=0;i<strlen(s1);i++)
						{
							if((*it).first==s1[i] || (*it).first==s2[i])
							{
								flag=false;
								break;
							}
						}
						if(flag) (*it).second='e';


					}

				}
//				cout<<m['A']<<endl;
			}

		}
		for(it=m.begin();it!=m.end();it++)
		{
			if((*it).second=='u')
			{
				printf("%c is the counterfeit coin and it is light.\n",(*it).first);
				break;
			}
			else if((*it).second=='d')
			{
				printf("%c is the counterfeit coin and it is heavy.\n",(*it).first);
				break;
			}
		}

		m.clear();

	}
	return 0;
}
