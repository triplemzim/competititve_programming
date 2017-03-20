#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long

using namespace std;



int main()
{
	int n,a[309]={0};
	cin>>n;
	int total=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		total+=a[i];
	}

	int cur=1;
	int ins=2;
	while(total)
	{

		if(a[cur])
		{
			cout<<'P';
//			flag=true;
			a[cur]--;
			total--;
		}
		if(total){

			if((a[cur-1] && cur-1>0) || (cur+1>n))
			{
				cur=cur-1;
				cout<<'L';
	//			flag=false;
			}
			else if(cur+1<=n)
			{
				cur=cur+1;
				cout<<'R';
	//			flag=false;
			}
		}
//		else
//		{
//			cur=cur-1;
//			cout<<

	}


	return 0;
}


//#define sets(n,pos) (n|(1<<pos))
//#define check(n,pos) (bool(n&(1<<pos)))
//#define mx 100000000
//#define lim 10000
//unsigned prime[mx>>6];
//void seive()
//{
//	unsigned k,i,j;
//	prime[2>>6]=sets(prime[2>>6],0);
//	for(i=3;i<lim;i+=2)
//	{
//		if(check(prime[i>>6],((i>>1)&31))==0)
//		{
//			if(i<100) cout<<i<<" ";
//			k=i<<1;
//			for(j=i*i;j<=mx;j+=k)
//			{
//				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
//			}
//		}
//	}
//	return;
//}



