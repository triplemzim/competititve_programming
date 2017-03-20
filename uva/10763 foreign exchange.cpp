#include<iostream>
#include<cstdio>
#include<map>

using namespace std;
#define mp make_pair

int main()
{
	map<pair<int,int>,bool> m;
	int n,total;
	int x,y;
	while(scanf("%d",&n)==1 && n)
	{
		total=0;
		for(int i=0;i<n;i++)
		{
			cin>>x>>y;
			if(m.find(mp(y,x))==m.end())
			{
				m[mp(x,y)]=true;
				total++;
			}
			else total--;
		}
		if(total==0)
		{
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
		m.clear();
	}
	return 0;
}

