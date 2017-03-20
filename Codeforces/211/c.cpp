#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{
	char ch[200009],last1,last2;
	int er1,er2;
	bool flag;
	gets(ch);
	int len=strlen(ch);
	bool trp=false;
	char a,b,c,d;
	if(len==1)
	{
		cout<<ch[0]<<endl;
		return 0;
	}

	cout<<ch[0]<<ch[1];
	a=ch[0];
	b=ch[1];
	for(int i=2;i<len;i++)
	{
		if(trp==false)
		{
			if(ch[i]==a && ch[i]==b) continue;
			else
			{
				cout<<ch[i];
				c=ch[i];
				trp=true;
			}
		}
		else
		{
			if(ch[i]==c && a==b || ch[i]==c && b==c ) continue;
			else
			{
				if(c!=b){ a=c;b=ch[i]; trp=false; }
				else
				{
					a=b;b=c;c=ch[i];
				}

				cout<<ch[i];
			}
		}



	}

	cout<<endl;
	return 0;
}

