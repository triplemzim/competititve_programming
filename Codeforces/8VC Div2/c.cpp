#include<bits/stdc++.h>

using namespace std;

#define iii long long
#define print_all(vec) for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';cout<<endl;
#define pb push_back
#define _all(A) (A).begin(),(A).end()


int main()
{
	iii sum,xr;
	vector<int> sumbit,xrbit;

	cin>>sum>>xr;

	iii temp;

	temp=sum;

	while(temp){
		sumbit.pb(temp%2);
		temp/=2;
	}

	temp=xr;

	while(temp){
		xrbit.pb(temp%2);
		temp/=2;
	}

	
	if(xrbit.size()>sumbit.size()){
		cout<<0<<endl;
		return 0;
	}

	//reverse(sumbit.begin(),sumbit.end());
	//reverse(xrbit.begin(),xrbit.end());

	for(int i=sumbit.size()-xrbit.size();i>0;i--){
		xrbit.pb(0);
	}

	//print_all(sumbit);
	//print_all(xrbit);

	int a,b,carry=0;
	bool flag=false;
	iii dp[111][2]={0};


	a=sumbit[0];
	b=xrbit[0];

	if(a==0 && b==0){
		dp[0][0]=1;
		dp[0][1]=1;
	}
	if(a==1 && b==1){
		dp[0][0]=2;
	}


	for(int i=1;i<sumbit.size();i++){
		a=sumbit[i];
		b=xrbit[i];
		a=sumbit[i];
		b=xrbit[i];

		if(a==0 && b==0){
			dp[i][1]+=dp[i-1][0];
			dp[i][0]+=dp[i-1][0];
		}
		else if(a==1 && b==0){
			dp[i][0]+=dp[i-1][1];
			dp[i][1]+=dp[i-1][1];
		}
		else if(a==0 && b==1){
			dp[i][1]+=dp[i-1][1]*(iii)2;	
		}
		else if(a==1 && b==1) {
			dp[i][0]+=dp[i-1][0]*(iii)2;

		}
	}

	if(sum==xr) dp[(int)sumbit.size()-1][0]-=2;
	cout<<dp[(int)sumbit.size()-1][0]<<endl;




			




	return 0;
}

