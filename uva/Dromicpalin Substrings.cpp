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

vector<string> v;
int c[27];
char ch[1009];
int palin(int mini,int maxi)
{
	bool flag=false;
	ms(c,0);

	int len=v.size();

	for(int i=mini;i<=maxi;i++)
	{
		c[ch[i]-96]++;
	}
	for(int i=0;i<27;i++)
	{

		if(flag==true && c[i]%2==1) return 0;
		if(c[i]%2==1)
		{
			flag=true;
		}
	}
	return 1;
}



int main()
{
	int cases,caseno=1;
//	int st[1009][27];
	cin>>cases;
	while(cases--)
	{
		scanf("%s",ch);
//		ms(st,0);
		int len=strlen(ch);
		int total=0;
//		for(int i=0;i<len;i++)
//		{
//			st[i][ch[i]-96]++;
//		}
		for(int i=0;i<len;i++)
		{
			ms(c,0);
			for(int j=i;j<len;j++)
			{
//				v.pb(ch[j]);
				bool p=true,flag=true;
				c[ch[j]-96]++;
				for(int i=0;i<27;i++)
				{
					if(flag==false && c[i]%2==1)
					{
						p=false;
						break;
					}
					if(c[i]%2==1) flag=false;
//				total+=palin(i,j);
				}
				if(p) total++;

//				total+=palin();
			}
//			v.clear();
		}
		printf("Case %d: %d\n",caseno++,total);
	}


	return 0;
}

