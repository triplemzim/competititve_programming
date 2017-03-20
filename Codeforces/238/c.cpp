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


#define mod 2
//class matrix
//{
//public:
//	int row,col;
//	iii mtrx[55][55];
//
//
//	matrix(int r,int c,int iv)
//	{
//	   row=r;col=c;
//	   for(int i=0;i<55;i++)for(int j=0;j<55;j++) mtrx[i][j]=iv;
//	}
//
//	matrix mat_mul(matrix one,matrix two)
//	{
//		matrix ret(one.row,two.col,0);
//		for(int i=0;i<one.row;i++)
//		{
//			for(int j=0;j<two.col;j++)
//			{
//				for(int k=0;k<one.row;k++)
//				{
//					ret.mtrx[i][j]+=one.mtrx[i][k]*two.mtrx[k][j];
//				}
//				ret.mtrx[i][j]%=mod;
//			}
//		}
//		return ret;
//	}
//
//	matrix mat_expo(iii exp)
//	{
//		if(exp==0)
//		{
//			matrix bl(row,col,1);
//			return bl;
//		}
//		if(exp==1)
//		{
//			return *this;
//		}
//		matrix res(row,col,0);
//		if(exp&1)
//		{
//			res=mat_expo(exp-1);
//			res=mat_mul(res,*this);
//		}
//		else
//		{
//			res=mat_expo(exp/2);
//			res=mat_mul(res,res);
//		}
////		matrix res=mat_expo(exp/2);
////		res=mat_mul(res,res);
////		if(exp&1)
////		{
////			res=mat_mul(res,*this);
////		}
//		return res;
//	}
//};



int main()
{
//	iii l;
//	matrix m(4,4,0);
//	m.mtrx[0][0]=3;
//	m.mtrx[0][2]=1;
//	m.mtrx[1][0]=1;
//	m.mtrx[1][2]=1;
//	m.mtrx[2][0]=1;
//	m.mtrx[2][2]=3;
//	m.mtrx[3][2]=1;
//
//	cin>>l;
//	iii M=1000000007;
//	cout<<m.mat_expo(l).mtrx[0][0]%M;

	int n,temp,command;
	scanf("%d",&n);
//	matrix m(n,n,0);
	int mm[1010][1010];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&mm[i][j]);

		}
	}
	int q,i,j,sum=0;
	bool flag=true;
	bool flip[1010]={0},flip_col[1010]={0},a,b;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&command);
		if(command==1)
		{
			scanf("%d",&temp);
			flag=true;
//			for(i=1;i<=n;i++) mm[temp][i]=!mm[temp][i];
			flip[temp]=!flip[temp];
		}
		else if(command==2)
		{
			scanf("%d",&temp);
			flag=true;
//			for(i=1;i<=n;i++) mm[i][temp]=!mm[i][temp];
			flip_col[temp]=!flip_col[temp];
		}
		else
		{
			if(flag==false)
			{
				printf("%d",sum);
				continue;
			}
			sum=0;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
				{
//					a=mm[i][j];
//					b=mm[j][i];
					if(flip[i] && flip_col[j]) a=mm[i][j];
					else if(flip[i] || flip_col[j]) a=!mm[i][j];
					else a=mm[i][j];

					if(flip[j] && flip_col[i]) b=mm[j][i];
					else if(flip[j] || flip_col[i]) b=!mm[j][i];
					else b=mm[j][i];
					sum=((sum+a*b));
				}
			}
//			ms(flip,0);
//			ms(flip_col,0);
			sum=(sum&1);
			printf("%d",sum);
			flag=false;
		}
	}
	return 0;
}












