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
	iii num,t,dif;
	cin>>t;
	iii s[100009];
	for(int i=0;i<t;i++)
	{
		cin>>s[i];
	}
	if(t==1)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	sort(s,s+t);

	if(t==2)
	{
		dif=s[1]-s[0];
		if(dif==0)
		{
			cout<<1<<endl;
			cout<<s[0]<<endl;
			return 0;
		}
		if(dif%2==0)
		{
			cout<<3<<endl;
			cout<<s[0]-dif<<' '<<s[0]+dif/2<<' '<<s[1]+dif<<endl;
			return 0;
		}
		cout<<2<<endl;
		cout<<s[0]-dif<<' '<<s[1]+dif<<endl;
		return 0;
	}

	dif=s[1]-s[0];
	iii temp,x,max_dif=1<<40;
	bool flag=false;
	int a=0,b=0;
	for(int i=2;i<t;i++)
	{
		x=s[i]-s[i-1];

		if(flag==true  )
		{
			if(x==dif) a++;
			else if(x==max_dif) b++;
			else
			{
				cout<<0<<endl;
				return 0;
			}
		}
		else
		{
			if(dif>x)
			{
				max_dif=dif;
				dif=x;
				b=a;
				a=1;
				temp=i-1;
				flag=true;
			}
			else if(dif<x)
			{
				max_dif=x;

				b=1;

				temp=i;
				flag=true;
			}
			else a++;
		}
	}
	if(s[1]-s[0]==max_dif) b++;

//	cout<<b<<endl;
	if(b>1)
	{
		cout<<0<<endl;
		return 0;
	}
	if(max_dif==(1<<40))
	{
		if(dif==0)
		{
			cout<<1<<endl;
			cout<<s[0]<<endl;
			return 0;
		}
		cout<<2<<endl;
		cout<<s[0]-dif<<' '<<s[t-1]+dif<<endl;
	}
	else
	{
//		cout<<max_dif<<endl;
		if(s[temp]-dif==s[temp-1]+dif){
		cout<<1<<endl;
		cout<<s[temp]-dif<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
	}






	return 0;
}

