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

vector<int>v[26];
int parent[26];
int n;

void initialize()
{
	for(int i=0;i<n;i++)
	{
		v[i].pb(i);
		parent[i]=i;
	}
	return ;
}

void clr(int a)
{
	int p=parent[a];
	bool flag=false;
	for(int i=0;i<v[p].size();i++)
	{
//		cout<<"element "<<a<<' '<<v[p][i]<<endl;
		if(v[p][i]==a) flag=true;
		if(flag)
		{
			parent[v[p][i]]=v[p][i];
			if(v[p][i]!=a) v[v[p][i]].pb(v[p][i]);
			v[p].erase(v[p].begin()+i);
			i--;
		}
	}
	return;
}
void move_onto(int a,int b)
{
	if(parent[a]==parent[b]) return;
	int p=parent[b];
	clr(a);
	clr(b);
	parent[b]=p;
	v[parent[b]].pb(b);
	v[parent[b]].pb(a);
	parent[a]=parent[b];
}

void move_over(int a,int b)
{
	if(parent[a]==parent[b]) return;

	clr(a);
	v[parent[b]].pb(a);
	parent[a]=parent[b];
}

void pile_onto(int a,int b)
{
	if(parent[a]==parent[b]) return;

	bool flag=false;
	int pa=parent[a],p=parent[b];

	clr(b);
	parent[b]=p;
	v[p].pb(b);

	for(int i=0;i<v[pa].size();i++)
	{
		if(v[pa][i]==a) flag=true;
		if(flag)
		{
			v[p].pb(v[pa][i]);
			parent[v[pa][i]]=p;
			v[pa].erase(v[pa].begin()+i);
			i--;
		}
	}

}
void pile_over(int a,int b)
{
	if(parent[a]==parent[b]) return;
	int p=parent[a],pp=parent[b];
	bool flag=false;
//	cout<<v[p].size()<<endl;
//	repi(i,0,v[p].size()) cout<<v[p][i]<<' ';
	for(int i=0;i<v[p].size();i++)
	{
//		cout<<v[p][i]<<endl;
		if(v[p][i]==a) flag=true;
		if(flag)
		{
			v[pp].pb(v[p][i]);
			parent[v[p][i]]=pp;
			v[p].erase(v[p].begin()+i);
			i--;
		}
	}
//	clr(a);
}



int main()
{
	cin>>n;
	initialize();
	char str[10];
	int a,b;
	scanf("%s",str);
	while(strcmp(str,"quit")!=0)
	{
		if(str[0]=='p')
		{
			cin>>a;
			scanf("%s",str);
			cin>>b;
			if(str[1]=='n')
			{
				pile_onto(a,b);
			}
			else
			{
				pile_over(a,b);
			}
		}
		else
		{
			cin>>a;
			scanf("%s",str);
			cin>>b;
			if(str[1]=='n') move_onto(a,b);
			else move_over(a,b);
		}

		scanf("%s",str);
	}
	for(int i=0;i<n;i++)
	{
		cout<<i<<":";
		for(int j=0;j<v[i].size();j++)
		{
			cout<<' '<<v[i][j];
		}
		cout<<endl;
	}



	return 0;
}


