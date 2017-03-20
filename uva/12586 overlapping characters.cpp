#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

char c[45],ch[37][16][45];
int len;
int cal(int i)
{
	for(int r=0;r<16;r++)
	{
		for(int co=0;co<43;co++)
		{
			if(ch[i][r][co]=='*')
			{
				int flag=true;
				for(int k=0;k<len;k++)
				{

					int ind=(int)c[k];
					if(ind<65) ind-=48;
					else ind-=55;
					if(ind==i) continue;
					if(ch[ind][r][co]=='*') {flag=false;break;}
				}
				if(flag==true) return 1;
			}
		}
	}
	return 0;

}

int main()
{
	char alph[40];
	int n,q;
	scanf("%d %d",&n,&q);

	scanf("%s",alph);
	for(int i=0;i<n;i++)
	{
		int ind=(int)alph[i];
		if(ind<65) ind-=48;
		else ind-=55;
		for(int j=0;j<16;j++)
		{
			scanf("%s",ch[ind][j]);
		}
		scanf("%s",c);
	}

//	while(scanf("%s",c)==1)
//		printf("%d\n",cal((int)c[0]-55,(int)c[1]-55));
//
//	vector<int> qu[40];
//	for(int i=0;i<n;i++)
//	{
//		int ind=(int)alph[i];
//		if(ind<65) ind-=48;
//		else ind-=55;
//		for(int j=0;j<n;j++)
//		{
//			if(i==j) continue;
//			int indj=(int)alph[j];
//			if(indj<65) indj-=48;
//			else indj-=55;
//			int pos=cal(ind,indj);
//
////			cout<<"pAAAAAAAAAAAAAICI "<<pos<<endl;
//			if(pos)
//			{
//				qu[ind].push_back(indj);
////				cout<<ind<<" "<<indj<<endl;
////				qu[indj].push(ind);
//			}
//		}
//	}
	int caseno=1;
	while(q--)
	{
		scanf("%s",c);
		len=strlen(c);

		printf("Query %d: ",caseno++);
		for(int i=0;i<len;i++)
		{
			int ind=(int)c[i];
			bool flag=true;

			if(ind<65) ind-=48;
			else ind-=55;
			if(cal(ind)) printf("Y");
			else printf("N");
//			for(int j=0;j<len;j++)
//			{
//
//				if(i==j) continue;
//				flag=false;
//				int indi=(int)c[j];
//				if(indi<65) indi-=48;
//				else indi-=55;
//
//				if(!cal(ind,indi)
//				{
//					flag=false;
//					break;
//				}
//				if(flag==false) break;
//			}
//			if(flag) printf("Y"

//				for(int k=0;k<qu[ind].size();k++)
//				{
//					if(qu[ind][k]==indi){ flag=true; break;}
//				}
//				if(flag==false) break;
//			}
//			if(flag) printf("Y");
//			else printf("N");
		}
		printf("\n");
	}
	return 0;
}
