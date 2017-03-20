#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;
int store[5001][1046]={0};
int main()
{
	int s=0,temp,cur=1,track[5009];

	store[0][0]=0;store[1][0]=1;track[0]=1; track[1]=1;
	int len,carry=0,i,j;
	for(i=2;i<=5000;i++)
	{

		for(j=0;j<track[i-1];j++)
		{
			temp=carry+store[i-1][j]+store[i-2][j];

			store[i][j]=temp%10;
			carry=temp/10;
		}
		if(carry)
		{
			while(carry)
			{
				store[i][j++]=carry%10;

				carry/=10;
			}
		}
		track[i]=j;
	}

	int n;
	while(scanf("%d",&n)==1)
	{
		printf("The Fibonacci number for %d is ",n);
		for(i=track[n]-1;i>=0;i--)
		{
			printf("%d",store[n][i]);
		}
		printf("\n");
	}

	return 0;
}



//#include<iostream>
//#include<cstdio>
//#include<cmath>
//#include<cstring>
//#include<vector>
//
//using namespace std;
//vector<int>store[5009];
//int main()
//{
//	int s=0,temp,cur=1,track[5009];
//
//	store[0].push_back(0);store[1].push_back(1);track[0]=1; track[1]=1;
//	int len,carry=0,i,j;
//	for(i=2;i<=5000;i++)
//	{
//		len=store[i-2].size();
//		for(j=0;j<track[i-1];j++)
//		{
//			if(j<len) temp=carry+store[i-1][j]+store[i-2][j];
//			else temp=carry+store[i-1][j];
//			store[i].push_back(temp%10);
//			carry=temp/10;
//		}
//		if(carry)
//		{
//			while(carry)
//			{
//				store[i].push_back(carry%10);
//				j++;
//				carry/=10;
//			}
//		}
//		track[i]=j;
//	}
//
//	int n;
//	while(scanf("%d",&n)==1)
//	{
//		printf("The Fibonacci number for %d is ",n);
//		for(i=track[n]-1;i>=0;i--)
//		{
//			printf("%d",store[n][i]);
//		}
//		cout<<endl;
//	}
//
//	return 0;
//}
