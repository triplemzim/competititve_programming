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

int parent[1000000];

int find_parent(int i)
{
	if(parent[i]==i) return i;
	return parent[i]=find_parent(parent[i]);
}
int union_set(int i,int j)
{
	parent[parent[i]]=parent[parent[j]];
}

int issame(int i,int j)
{
	if(parent[find_parent(i)]==parent[find_parent(j)]) return 1;
	return 0;
}

int main()
{
	int su,un,cases,connections,a,b;
	char ch;
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%d",&connections);

		su=un=0;
		for(int i=0;i<=connections;i++) parent[i]=i;
		getchar();
		scanf("%c",&ch);
		while((int)ch!=10)
		{

			scanf("%d %d",&a,&b);
//			cout<<(int)ch<<endl;
			if(ch=='c')
			{
				if(issame(a,b)==0)
				{
					union_set(a,b);
				}

			}
			else if(ch=='q')
			{
				if(issame(a,b)==0) un++;
				else su++;
			}

			getchar();
			if(scanf("%c",&ch)==EOF) break;
		}
		printf("%d,%d\n",su,un);
		if(cases) printf("\n");
	}




	return 0;
}







