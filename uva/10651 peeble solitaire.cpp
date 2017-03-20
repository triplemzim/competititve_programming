//verdict: AC

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
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))




int mask,mn;




void calc(int bit_mask,int i)
{
	if(mn>i) mn=i;

	int temp;
	for(int j=0;j<12;j++)
	{
		if(j<10 && bool(bit_mask&(1<<j))==0 && bool(bit_mask&(1<<(j+1)))==1 && bool(bit_mask&(1<<(j+2)))==1)
		{
			temp=bit_mask;
			temp=sets(temp,j);
			temp=reset(temp,j+1);
			temp=reset(temp,j+2);

			calc(temp,i-1);
		}
		if(j>1 && bool(bit_mask&(1<<j))==0 && bool(bit_mask&(1<<(j-1)))==1 && bool(bit_mask&(1<<(j-2)))==1)
		{
			temp=bit_mask;
			temp=sets(temp,j);
			temp=reset(temp,j-1);
			temp=reset(temp,j-2);

			calc(temp,i-1);
		}

	}
	return;
}


int main()
{
//	freopen("in.txt","r",stdin);
	char ch[13];
	int count;
	int n;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",ch);
		mask=count=0;

		for(int i=0;i<12;i++)
		{
			if(ch[i]=='o') mask=mask|(1<<i),count++;
		}
		mn=count;
		calc(mask,count);

		printf("%d\n",mn);

//		for(int i=0;i<12;i++)
//		{
//			cout<<mask&(1<<i)<<' ';
//		}


	}
	return 0;
}

