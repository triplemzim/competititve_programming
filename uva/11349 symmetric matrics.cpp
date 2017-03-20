#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int main()
{

	long long n,mat[101][101],cases,caseno=1;
	char c;
	scanf("%d",&cases);
	scanf("%c",&c);
	cout<<c;
	while(cases--)
	{
		bool flag=true;
		scanf(" %c %c %lld",&c,&c,&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%lld",&mat[i][j]);
				if(mat[i][j]<0) flag=false;
			}
		}



		int i=0,j=0;
		if(flag)
		{
			for(i=0;i<=n/2;i++)
			{
				for(j=0;j<n;j++)
				{
					if(mat[i][j]!=mat[n-i-1][n-j-1])
					{
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
		}
		if(flag)
		{
			for(i=0;i<=n/2;i++)
			{
				for(j=0;j<n;j++)
				{
					if(mat[j][i]!=mat[n-j-1][n-i-1])
					{
						flag=false;
						break;
					}
				}
				if(!flag) break;
			}
		}
//		else if(flag)
//		{
//			for(i=0;i<n;i++)
//			{
//				for(j=0;j<n;j++)
//				{
//					if(mat[i][j]!=mat[n-i-1][j] || mat[i][j]!=mat[i][n-j-1])
//					{
//						flag=false;
//						break;
//					}
//				}
//				if(!flag) break;
//			}
//		}

//		if(flag)
//		while(i<=n/2)
//		{
//			if(mat[i][j]!=mat[n-i-1][n-j-1])
//			{
//				flag=false;
//				break;
//			}
//			i++;j++;
//		}
//		if(flag)
//		{
//			i=0;j=n-1;
//			while(i<=n/2)
//			{
//				if(mat[i][j]!=mat[n-i-1][n-j-1])
//				{
//					flag=false;
//					break;
//				}
//				i++;
//				j--;
//			}
//		}
//		if(flag)
//		{
//			i=n/2;j=0;
//			while(j<=n/2)
//			{
//				if(mat[i][j]!=mat[i][n-j-1])
//				{
//					flag=false;
//					break;
//				}
//
//				j++;
//			}
//		}
//
//		if(flag)
//		{
//			i=0;j=n/2;
//			while(i<=n/2)
//			{
//				if(mat[i][j]!=mat[n-i-1][j])
//				{
//					flag=false;
//					break;
//				}
//
//				i++;
//			}
//		}

		if(flag==true)
		{
			printf("Test #%lld: Symmetric.\n",caseno++);
		}
		else
			printf("Test #%lld: Non-symmetric.\n",caseno++);
	}
	return 0;
}
