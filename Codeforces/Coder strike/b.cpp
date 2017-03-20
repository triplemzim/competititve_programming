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
	int n,k,speed[109];
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>> speed[i];

	sort(speed,speed+n);

	if(k)cout<<speed[n-k]<<endl;
	else cout<<speed[n-1]<<endl;




	return 0;
}

