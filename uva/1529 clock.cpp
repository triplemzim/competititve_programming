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
#define pi acos(-1)
#define rep(i,a,n) for(int i=a;i<n;i++)

using namespace std;



int main()
{
	double lh,lm,lhh,lmm,temp_lh,temp_lm;

	while(cin>>lh>>lm>>lhh>>lmm)
	{
		int dif;
		if(lhh<lh || (lhh==lh && lmm<lm)) temp_lh=lhh+12;
		else temp_lh=lhh;
		if(lmm<lm) temp_lm=lmm+60;
		else temp_lm=lmm;
		dif=temp_lh-lh;
		cout<<dif;
		if(temp_lh>12) dif--;
		if(temp_lm>=60) dif--;
		dif=dif*60+temp_lm-lm;

		int count=dif/60;

		cout<<count<<endl;
		lh+=count;
		if(lh>=12) lh-=12;

		lh*=5;
		lhh*=5;
		lh+=(lm/12);
		lhh+=(lmm/12);

		if(lmm>=lm)
		{
			if(lhh<lmm) count++;
		}
		else
		{
			if(lm<=lh && lmm<=lhh) count++;
		}

		cout<< count<<endl;



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



