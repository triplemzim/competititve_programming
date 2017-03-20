#include<iostream>
#include<cstdio>
#include<string.h>
#include<math.h>

using namespace std;
int mul[370];
int ans[370][1000];
int lim,star;
int track[370];
int add(int n,int k)
{
    while(n)
    {
        n=ans[star][k]+n;
        ans[star][k++]=n%10;
        n/=10;
    }
    return k;
}

int multiply(int n)
{
    int k=0,s;
    for(int i=0;i<lim;i++)
    {
        s=add(ans[star-1][i]*n,k++);
    }
    return s;
}

int main()
{
    memset(ans,0,sizeof(ans));
    mul[0]=1;
    ans[0][0]=1;
    lim=1;
    for(int i=2;i<367;i++)
    {
        star=i-1;
		lim=track[i]=multiply(i);
    }
    int flag;
    int n,sum,num[11]={0};


    while(scanf("%d",&n)==1 && n)
    {
		if(n==1)
		{
			printf("%d! --\n",n);
			printf("   (0)    %d    (1)    %d    (2)    %d    (3)    %d    (4)    %d\n",num[0],1,num[2],num[3],num[4]);
			printf("   (5)    %d    (6)    %d    (7)    %d    (8)    %d    (9)    %d\n",num[5],num[6],num[7],num[8],num[9]);
		}
		else{

			for(int i=track[n]-1;i>=0;i--)
			{
				num[ans[n-1][i]]++;
			}
			printf("%d! --\n",n);
			printf("   (0)    %d    (1)    %d    (2)    %d    (3)    %d    (4)    %d\n",num[0],num[1],num[2],num[3],num[4]);
			printf("   (5)    %d    (6)    %d    (7)    %d    (8)    %d    (9)    %d\n",num[5],num[6],num[7],num[8],num[9]);

		memset(num,0,sizeof(num));
		}
    }
    return 0;
}


//3! --
//   (0)    0    (1)    0    (2)    0    (3)    0    (4)    0
//   (5)    0    (6)    1    (7)    0    (8)    0    (9)    0

