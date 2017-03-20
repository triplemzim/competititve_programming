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

struct node
{
	public:

	bool endmark;
	node *next[27];
	node()
	{
		endmark=false;
		for(int i=0;i<27;i++)	next[i]=NULL;
	}
}*root;

void insrt(char str[],int len)
{
	node *curr=root;
	for(int i=0;i<len;i++)
	{
		if(curr->next[str[i]-'a']==NULL)
		{
			curr->next[str[i]-'a']=new node();
		}
		curr=curr->next[str[i]-'a'];
	}
	curr->endmark=true;
	return ;
}

bool srch(char str[],int len)
{
	node *cur=root;
	for(int i=0;i<len;i++)
	{
		int id=str[i]-'a';
		if(cur->next[id]==NULL) return false;
		else
		{
			cur=cur->next[id];
		}
	}
	return cur->endmark;
}

int main()
{






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



