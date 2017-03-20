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

int cases,n,k,num[10009];
bool flag=false;

int dp[10009][101];

bool color[10009]={false};

int modulo(int x,int y)
{
    if(x<0)
        x=x+(-x/y+1)*y;
    return x%y;
}

int test_divisibility(int i,int mod)
{
	if(i>=n)
	{
		if(modulo(mod,k)==0) return flag=true;
		return 0;
	}
	if(dp[i][modulo(mod,k)]!=-1) return dp[i][modulo(mod,k)];

	int temp1=modulo(num[i],k),temp2=modulo(-num[i],k);

	temp1=test_divisibility(i+1,mod+num[i]);
	temp2=test_divisibility(i+1,mod-num[i]);
//	temp1=test_divisibility(i+1,temp1);
//	temp2=test_divisibility(i+1,temp2);

	return dp[i][modulo(mod,k)]=temp1>temp2? temp1 : temp2 ;








}


int main()
{
//	freopen("in.txt","r",stdin);
//	cin>>cases;
//	while(cases--)
//	{
		ms(dp,-1);
		ms(color,false);
		cin>>n>>k;
		flag=false;
		for(int i=0;i<n;i++)
		{
			cin>>num[i];
		}
		int q=test_divisibility(0,0);

		if(flag)
		{
			cout<<"Divisible"<<endl;
		}
		else cout<<"Not divisible"<<endl;
//	}



	return 0;
}

