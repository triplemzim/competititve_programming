#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999


int main()
{
//	freopen("in.txt","r",stdin);
	char ch[1000009];
	iii len,pos=0,pos_at_num,for_finish=0;
	iii count=0,temp;
	int at_flag,dot_flag,at_num_flag=0,flag;
	gets(ch);
	len=strlen(ch);

	at_flag=dot_flag=flag=0;
	iii finish=0,middle=0,begini=0;

	for(int i=len-1;i>=0;i--)
	{
		if(!dot_flag)
		{
			if(ch[i]>=97 && ch[i]<=122)
			{
				finish++;
//				cout<<"paici"<<endl;
			}
			else if(ch[i]!='.')
			{
				finish=0;
			}
			else
			{
				dot_flag=1;
			}
		}
		else if(!at_flag)
		{
			if(ch[i]>=97 && ch[i]<123)
			{
				middle++;

			}
			else if(ch[i]>47 && ch[i]<='9')
			{
//				pos_at_num=i;
//				at_num_flag=1;
				middle=0;
			}
			else if(ch[i]=='.')
			{
				finish=middle;
				middle=0;
			}
			else if(ch[i]=='@')
			{
				middle=0;
				at_flag=1;
			}
			else
			{
				finish=middle=0;
				at_flag=dot_flag=0;
			}
		}
		else
		{
			if(ch[i]>=97 && ch[i]<123)
			{
				begini++;
				for_finish++;
			}
			else if(ch[i]=='_' || (ch[i]>47 && ch[i]<='9') )
			{
				pos=i;
				for_finish=0;

			}
			else if(ch[i]=='.')
			{
				count+=(begini*finish);
				finish=for_finish;
				for_finish=0;

				pos=0;
				at_flag=0;
				begini=0;
			}
			else
			{
				count+=(begini*finish);
				finish=for_finish=0;
				begini=0;
				at_flag=dot_flag=0;
			}
		}
	}
//	cout<<ch[0]<<endl;
	if(!(ch[0]=='.' || ch[0]=='@'))
	{
//		cout<<"paici"<<endl;
//		cout<<begini<<' '<<finish<<endl;
		count+=(begini*finish);
	}

	cout<<count<<endl;



	return 0;
}

