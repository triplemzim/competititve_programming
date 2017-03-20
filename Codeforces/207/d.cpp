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

iii find_gcd(int a,int b)
{
	if(b==0) return a;
	else return find_gcd(b,a%b);
}
char s1[10000009],s2[10000009];

int main()
{
	iii n,m;
	cin>>n>>m;
	scanf("%s %s",s1,s2);

	int len1=strlen(s1),len2=strlen(s2);

	iii gcd=find_gcd(len1,len2);
//	cout<<gcd;
	int i1=0,i2=0;
	iii count=0;

	if(len1>len2)
	{
		for(int i=0;i<len1;i++)
		{
			if(i1==len2) i1=0;
			if(s2[i1++]==s1[i]) count++;
		}
	}
	else
	{
		for(int i=0;i<len2;i++)
		{
			if(i1==len1) i1=0;
			if(s1[i1++]==s2[i]) count++;
		}
	}
	iii lc=(len1*len2)/gcd;

	count=(len1*n)-((len1*n)/lc)*count;
	cout<<count<<endl;


	return 0;
}

