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




int main()
{
	iii pos[12]={0},neg[12]={0};
	int n;
	iii count=0;
	cin>>n;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		if(temp<0) neg[-temp]++;
		else pos[temp]++;
//		pos[0].pb(0);
	}
	for(int i=1;i<=10;i++)
	{
		count+=(pos[i]*neg[i]);
	}

	count+=((pos[0]*(pos[0]-1))/2);
	cout<<count<<endl;



	return 0;
}




