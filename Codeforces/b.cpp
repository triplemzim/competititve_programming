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

int main()
{
	ull track[20],w,m,k,cost,total,temp;
	int digit;
	temp=10;
	for(int i=1;i<=17;i++)
	{
		track[i]=temp;
		temp*=10;
	}
	cin>>w>>m>>k;
	temp=m;
	digit=0;
	while(temp)
	{
		temp/=10;
		digit++;
	}
//	cout<<"digit "<<digit<<endl;
	w/=k;
	cost=0;
	ull i=track[digit]-m;
//	cout<<i<<endl;
	ull count=0;

	while(digit*i<=w)
	{
		count+=i;

		w-=(i*digit);
//		cout<<"count "<<count<<endl;
//		cout<<w<<endl;
		digit++;
		i=track[digit]-track[digit-1];
//		cout<<i<<endl;

	}

//	w-=count;
//	cout<<w<<endl;
	count+=(w/digit);
	cout<<count<<endl;



	return 0;
}






