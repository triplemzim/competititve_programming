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
	int c,d,n,m,k;
	cin>>c>>d>>n>>m>>k;
	int total=n*m-k;

	if(total<=0)
	{
		cout<<0<<endl;
		return 0;
	}

	int count=0;

	while(total>0)
	{
		if(n<=total)
		{
			if(n*d<c){
				count+=(n*d);
				total-=(n);
//				cout<<total;

//				cout<<count<<endl;
			}
			else{
				count+=c;
				total-=n;
			}
		}
		else
		{
			if(total*d<c) count+=(total*d);
			else count+=c;
			total=0;
		}

	}
	cout<<count<<endl;



	return 0;
}
