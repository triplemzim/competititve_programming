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

int parent[100009];


int find_parent(int i)
{
	if(parent[i]==i) return i;

	return parent[i]=find_parent(parent[i]);
}

int issame(int i,int j)
{
	if(parent[find_parent(i)]==parent[find_parent(j)]) return 1;
	return 0;
}

int main()
{
	int set_size[100009],a,b;
	int f,cases,index;
	scanf("%d",&cases);

	char f1[25],f2[25];
	map<string,int> fnd;
//	memset(set_size,1,sizeof(set_size));
	while(cases--)
	{

		scanf("%d",&f);
//		ms(set_size,1);
		for(int i=0;i<=f;i++)	set_size[i]=1;

		index=0;
		for(int i=0;i<f;i++)
		{

			scanf("%s%s",f1,f2);

			if(fnd.find(f1)==fnd.end())
			{
				parent[index]=index;
//				cout<<"1 no: "<<index<<endl;
				fnd[f1]=index++;

			}
			if(fnd.find(f2)==fnd.end())
			{
				parent[index]=index;
//				cout<<"2 no: "<<index<<endl;
				fnd[f2]=index++;
			}
			a=fnd[f1];
			b=fnd[f2];
			
			if(a!=b && !issame(a,b)) set_size[find_parent(a)]+=set_size[find_parent(b)];
			printf("%d\n",set_size[find_parent(a)]);
			
			if(!issame(a,b)) parent[find_parent(b)]=parent[find_parent(a)];


		


			
			
		}
		fnd.clear();
	}














	return 0;
}






