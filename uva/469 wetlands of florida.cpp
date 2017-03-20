//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<stdlib.h>
//
//
//using namespace std;
//
//char cell[100][100];
//int length[100],result[10010];
//int color[100][100];
//int r,s;
//
//int get_len(int i,int j)
//{
//
//	if(i>r || j>=length[i] || i<0 || j<0) return 0;
//
//	if(color[i][j]!=0) return 0;
//	if(cell[i][j]=='L') return 0;
//
//	color[i][j]=s;
//
//	int count=1;
//
//	count+=get_len(i-1,j-1);
//	count+=get_len(i-1,j);
//	count+=get_len(i-1,j+1);
//	count+=get_len(i,j-1);
//	count+=get_len(i,j+1);
//	count+=get_len(i+1,j-1);
//	count+=get_len(i+1,j);
//	count+=get_len(i+1,j+1);
//
//	return count;
//
//}
//
//int main()
//{
//
//memset(length,0,sizeof(length));
//	int cases;
//	bool blank=false;
//
//	scanf("%d",&cases);
//	getchar();
//	getchar();
//	while(cases--)
//	{
//		if(blank) printf("\n");
//		else blank=true;
//		memset(color,0,sizeof(color));
//
//		int row=0;
//		gets(cell[row]);
//
//		while(cell[row][0]=='L' || cell[row][0]=='W')
//		{
//			length[row]=strlen(cell[row]);
//			row++;
//			gets(cell[row]);
//
//		}
//		r=row-1;
//		int i=0,j=0;
//		s=0;
//		while(strlen(cell[row])!=0)
//		{
//			bool flag=false;
//			for(int k=0;k<strlen(cell[row]);k++)
//			{
//				if(cell[row][k]==' ')
//				{
//					flag=true;
//					continue;
//				}
//				if(flag)
//				{
//					j=j*10+ (int)cell[row][k]-48;
//				}
//				else
//				{
//					i=i*10+(int)cell[row][k]-48;
//				}
//			}
//			i--;j--;
//
//			if(color[i][j]!=0)
//			{
//				printf("%d\n",result[color[i][j]]);
//			}
//			else
//			{
//				s++;
//				result[s]=get_len(i,j);
//				cout<<result[s]<<endl;
//			}
//			i=0;j=0;
//			if(scanf("%s",cell[row])==EOF) break;
//			else
//			{
//				char s[15];
//				scanf("%s",s);
//				int l=strlen(cell[row]);
//				cell[row][l]=' ';
//				for(int i=l+1;i<=strlen(s)+l;i++)
//					cell[row][i]=s[i-l-1];
//				cell[row][strlen(s)+l+1]='\0';
//			}
//		}
//
//	}
//
//	return 0;
//}
#include<iostream>
#include<cstdio>
#include<cstring>
#include<stdlib.h>


using namespace std;

char cell[102][102];
int length[102],result[10010];
int color[102][102];
int r,s;

int get_len(int i,int j)
{

   if(i>r || j>=length[i] || i<0 || j<0) return 0;

   if(color[i][j]!=0) return 0;
   if(cell[i][j]=='L') return 0;

   color[i][j]=s;

   int count=1;

   count+=get_len(i-1,j-1);
   count+=get_len(i-1,j);
   count+=get_len(i-1,j+1);
   count+=get_len(i,j-1);
   count+=get_len(i,j+1);
   count+=get_len(i+1,j-1);
   count+=get_len(i+1,j);
   count+=get_len(i+1,j+1);

   return count;

}

int main()
{

memset(length,0,sizeof(length));
   int cases;
   bool blank=false;
	char c;
   scanf("%d",&cases);
   getchar();
   getchar();
   while(cases--)
   {
      if(blank) printf("\n");
      else blank=true;
      memset(color,0,sizeof(color));

      int row=0;
      gets(cell[row]);

      while(cell[row][0]=='L' || cell[row][0]=='W')
      {
         length[row]=strlen(cell[row]);
         row++;
         gets(cell[row]);

      }
      r=row-1;
      int i=0,j=0;
      s=0;
      do
      {
         bool flag=false;
         for(int k=0;k<strlen(cell[row]);k++)
         {
            if(cell[row][k]==' ')
            {
               flag=true;
               continue;
            }
            if(flag)
            {
               j=j*10+ (int)cell[row][k]-48;
            }
            else
            {
               i=i*10+(int)cell[row][k]-48;
            }
         }
         i--;j--;

         if(color[i][j]!=0)
         {
            printf("%d\n",result[color[i][j]]);
         }
         else
         {
            s++;
            result[s]=get_len(i,j);
            cout<<result[s]<<endl;
         }
         i=0;j=0;


      }while(gets(cell[row]) && strlen(cell[row])!=0);

   }

   return 0;
}
