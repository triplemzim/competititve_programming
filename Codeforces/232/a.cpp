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
	int n;
	bool check[110]={false};
	int upper,lower,x,y;
	cin>>n;
	cin>>lower>>upper;
	n--;
	int l[110],r[110],index=0;
	while(n--)
	{
		cin>>l[index]>>r[index];
		index++;
	}
	int count=0;
	bool flag;
	for(int i=lower+1;i<=upper;i++)
	{
		flag=false;
		for(int j=0;j<index;j++)
		{
			if(i-1>=l[j] && i<=r[j])
			{
				flag=true;
				break;
			}
		}
//		cout<<flag<<endl;
		if(flag==false) count++;
	}

	cout<<count<<endl;



	return 0;
}


/*
6
0 9
0 1
2 3
4 5
6 7
8 9
*/
