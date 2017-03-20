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


int coin[7],total;
#define lim ((6*20000)>>1)+9
bool ans;




void test(int x,int sum)
{
	int n,temp;
	bool flag=false,track[lim]={false};

	int taken[lim]={0};
	track[0]=true;
//	cout<<total<<endl;
	for(int i=1;i<7;i++)
	{
		for(int j=0;j<total+1;j++)
		{
			taken[j]=0;
		}
		for(int j=0;j<=total;j++)
		{
			int k=j+i;
			if(track[j]==true && track[k]==false && taken[j]<coin[i])
			{
//				cout<<k<<endl;
				track[k]=true;
				taken[k]=taken[j]+1;
			}
		}
	}

	if(track[total]) ans=true;
	return;
}


int main()
{
//	freopen("in.txt","r",stdin);
	int caseno=1;
	bool flag;

	while(1)
	{
		flag=false;
		ans=false;
//		ms(dp,-1);
		total=0;
		for(int i=1;i<7;i++)
		{
			cin>>coin[i];
			if(coin[i]) flag=true;
//			coin[i]=(coin[i]&1);
			total+=(coin[i]*i);
		}
		if(!flag) break;

		if(total%2==0) {
			total=total>>1;
//			cout<<'t'<<total<<endl;
			test(0,0);
//			if(track[total]) ans=true;
		}



		if(ans) printf("Collection #%d:\nCan be divided.\n\n",caseno++);
		else printf("Collection #%d:\nCan't be divided.\n\n",caseno++);

	}






	return 0;
}

