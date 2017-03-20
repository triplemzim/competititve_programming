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


string s1,s2;
int len1,len2;


vector<int>table[10000];
int lcs_table()
{
	len1=s1.length();
	len2=s2.length();

	for(int i=0;i<=len2;i++) table[0].pb(0);
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


void print_lcs(int i,int j)
{
	if(i==0 || j==0) return;

	if(table[i-1][j]!=table[i][j] && table[i][j-1]!=table[i][j])
	{
		print_lcs(i-1,j-1);
		cout<<s1[i-1];
	}
	else if(table[i-1][j]==table[i][j])
	{
		print_lcs(i-1,j);
	}
	else print_lcs(i,j-1);
}



int main()
{


	cin>>s1>>s2;
	cout<<lcs_table()<<endl;

	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++) cout<<table[i][j]<<' ';
		cout<<endl;
	}

	print_lcs(len1,len2);


	return 0;
}























