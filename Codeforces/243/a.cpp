#include<bits/stdc++.h>

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
	int n,s,x[10000];
	cin>>n>>s;
	bool flag=true;
	int total=0;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
		total+=x[i];
	}
	sort(x,x+n);
	total-=x[n-1];
	if(total<=s) flag=true;
	else flag=false;

	if(flag) cout<<"YES";
	else cout<<"NO";

	return 0;
}

