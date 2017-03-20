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


char s1[1010],s2[1010];
int len1,len2;


vector<int>table[10000];
int lcs_table()
{
	len1=strlen(s1);
	len2=strlen(s2);
	for(int i=0;i<=max(len1,len2);i++) table[i].clear();

	for(int i=0;i<=len2;i++) {table[0].pb(0);}
	for(int i=0;i<=len1;i++) table[i].pb(0);

	for(int i=0;i<len1;i++)
	{
		for(int j=0;j<len2;j++)
		{
			if(s1[i]==s2[j])
			{
				table[i+1].pb(table[i][j]+1);
			}
			else
			{
				table[i+1].pb(max(table[i][j+1],table[i+1][j]));
			}
		}
	}
	return table[len1][len2];
}





int main()
{

//	char a[1010],b[1010];
	while(gets(s1))
	{
		gets(s2);
		cout<<lcs_table()<<endl;

	}


	return 0;
}








