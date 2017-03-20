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

void seive();

int main()
{
	int debt[110]={0};
	int n,m,a,b,bdt;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b>>bdt;
		debt[b]+=bdt;
		debt[a]-=bdt;
	}
	int total=0;
	for(int i=1;i<=n;i++)
	{
		if(debt[i]>0) total+=debt[i];
	}
	cout<<total<<endl;





	return 0;
}





