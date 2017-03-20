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
	queue<int>q;
	char ch[100009];
	scanf("%s",ch);
	int len=strlen(ch);
	bool color[100009]={false};
//	set<int> s;
	for(int i=0;i<len-1;i++)
	{
		if((int)ch[i]-48 + (int) ch[i+1]-48==9)
		{
			if(color[i]==false) q.push(i);
			if(!color[i+1])q.push(i+1);
			color[i]=color[i+1]=true;
		}
	}
	if(len==1)
	{
		if(ch[0]=='9') printf("1\n");
		else printf("0");
		return 0;
	}

	int count=1,total=1,last=q.front();
//	it=s.begin();
//	last=*it;
//	s.erase(last);
//	it=s.begin();
	if(!q.empty()) q.pop();
	while(!q.empty())
	{
//		bool flag=false;
//		cout<<q.front();
		if(q.front()==last+1)
		{
			count++;
//			flag=true;
		}
		else
		{


			if(count>1 && count%2==1) total*=(count-2);
			count=1;
		}
		last=q.front();q.pop();
//		s.erase(last);
//		it=s.begin();
	}
//	cout<<count;
//	if(count%2==0) total++;
	if(count>1 && count%2) total*=(count-2);
	cout<<total<<endl;




	return 0;
}






