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
#define MP make_pair
#define eps 1e-9
#define inf 999999999


#define mod 10000007
class matrix
{
public:
	int row,col;
	iii mtrx[55][55];


	matrix(int r,int c,int iv)
	{
	   row=r;col=c;
	   for(int i=0;i<55;i++)for(int j=0;j<55;j++) mtrx[i][j]=iv;
	}

	matrix mat_mul(matrix one,matrix two)
	{
		matrix ret(one.row,two.col,0);
		for(int i=0;i<one.row;i++)
		{
			for(int j=0;j<two.col;j++)
			{
				for(int k=0;k<one.row;k++)
				{
					ret.mtrx[i][j]+=one.mtrx[i][k]*two.mtrx[k][j];
				}
				ret.mtrx[i][j]%=mod;
			}
		}
		return ret;
	}

	matrix mat_expo(iii exp)
	{
		if(exp==0)
		{
			matrix bl(row,col,1);
			return bl;
		}
		if(exp==1)
		{
			return *this;
		}
		matrix res(row,col,0);
		if(exp&1)
		{
			res=mat_expo(exp-1);
			res=mat_mul(res,*this);
		}
		else
		{
			res=mat_expo(exp/2);
			res=mat_mul(res,res);
		}
//		matrix res=mat_expo(exp/2);
//		res=mat_mul(res,res);
//		if(exp&1)
//		{
//			res=mat_mul(res,*this);
//		}
		return res;
	}
};



int main()
{
	iii l;
	matrix m(4,4,0);
	m.mtrx[0][0]=3;
	m.mtrx[0][2]=1;
	m.mtrx[1][0]=1;
	m.mtrx[1][2]=1;
	m.mtrx[2][0]=1;
	m.mtrx[2][2]=3;
	m.mtrx[3][2]=1;

	cin>>l;
	iii M=1000000007;
	cout<<m.mat_expo(l).mtrx[0][0]%M;


	return 0;
}











