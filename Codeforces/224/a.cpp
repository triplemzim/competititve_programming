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
#include<cassert>

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



int main()
{
	char ch[100];
	int l=0,r=0,dif,total,rem;
	bool flag=false;
	gets(ch);
	int ll=strlen(ch);
	for(int i=0;i<ll;i++)
	{
//		if((int)ch==12) break;
		if(ch[i]=='|') flag=true;
		if(flag==false)
		{
			l++;
		}
		else if(flag==true && ch[i]!='|') r++;
	}
	char c[100];
	gets(c);
	int len=strlen(c);
	dif=l-r;
	if(dif<0) dif=-dif;
//	cout<<"dif= "<<dif<<endl;
	if(len<dif){
		cout<<"Impossible"<<endl;
	}
	else if((len-dif)%2==0)
	{
		int i;
		for(i=0;i<ll;i++)
		{
			if(ch[i]=='|') break;
			cout<<ch[i];
		}
		total=(len-dif)/2;
		if(l<r) total=r+total;
		else total+=l;
//		cout<<total<<endl;

		int index=0;
		bool d=false;
		for(i=0;i<total-l;i++)
		{
			index=i;
			d=true;

			cout<<c[i];
		}
		cout<<'|';
		flag=false;
		for(int j=0;j<ll;j++)
		{
			if(flag) cout<<ch[j];
			if(ch[j]=='|') flag=true;
		}
		if(d==true) index++;
		for(i=index;i<len;i++)
		{
			cout<<c[i];
		}
		cout<<endl;
	}
	else cout<<"Impossible"<<endl;




	return 0;
}

