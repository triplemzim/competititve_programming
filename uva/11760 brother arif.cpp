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

#define ull unsigned long long
#define iii long long

using namespace std;



int main()
{
	bool flag,row[10009],col[10009];
	int r,c,n,a,b,caseno=1;
	while(scanf("%d%d%d",&r,&c,&n)==3)
	{
		if(!r && !c && !n) break;
		memset(row,true,sizeof(row));
		memset(col,true,sizeof(col));

		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			row[a]=false;
			col[b]=false;
		}
		scanf("%d%d",&a,&b);
		flag=false;
		if(row[a] && col[b]) flag=true;
		if(a)
		{
			if(row[a-1] && col[b]) flag=true;
		}
		if(a<r-1)
		{
			if(row[a+1] && col[b]) flag=true;
		}
		if(b)
		{
			if(row[a] && col[b-1]) flag=true;
		}
		if(b<c-1)
		{
			if(row[a] && col[b+1]) flag=true;
		}

		if(flag)
		{
			printf("Case %d: Escaped again! More 2D grid problems!\n",caseno++);
		}
		else
		{
			printf("Case %d: Party time! Let's find a restaurant!\n",caseno++);
		}

	}







	return 0;
}






