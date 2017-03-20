#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
#define debug(x) printf("DEBUG: %d\n",x)
#define printL(x) printf("%I64d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vector<int>
#define printv(vec) for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';cout<<endl;
#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 100009
#define mod 1000000007 // 10^9 + 7

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

class matrix
{
public:
	int row,col;
	iii mtrx[5][5];


	matrix(int r,int c,int iv)
	{
	   row=r;col=c;
	   for(int i=0;i<5;i++)for(int j=0;j<5;j++) mtrx[i][j]=iv;
	}
	matrix(){}


	matrix mat_add(matrix one,matrix two)
	{
		matrix ret(one.row,one.col,0);
		for(int i=0;i<one.row;i++){
			for(int j=0;j<one.col;j++){
				ret.mtrx[i][j]= one.mtrx[i][j]+two.mtrx[i][j];
				ret.mtrx[i][j]%=mod;
			}
		}
		return ret;
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
					ret.mtrx[i][j]%=mod;
				}
			}
		}
		return ret;
	}

	matrix mat_expo(iii exp)
	{
		if(exp==0)
		{
			matrix bl(row,col,0);
			for(int i=0;i<row;i++){
				for(int j=0;j<col;j++){
					if(i==j) bl.mtrx[i][j]=1;
				}
			}
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
	void prnt(){
		for(int	i = 0;i<row;i++){
		   for(int j=0;j<col;j++){
			   cout<<mtrx[i][j]<<' ';
		   }
		   cout<<endl;
		}
	}

};

matrix tree[MAXN*3+1];

//matrix f[100009];
iii a[100009];
matrix m(2,2,1),fib(2,1,1),tmp;
matrix bl(2,2,0);


matrix mat_add(matrix one,matrix two)
{
	matrix ret(one.row,one.col,0);
	for(int i=0;i<one.row;i++){
		for(int j=0;j<one.col;j++){
			ret.mtrx[i][j]= one.mtrx[i][j]+two.mtrx[i][j];
			ret.mtrx[i][j]%=mod;
		}
	}
	return ret;
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
		return bl;
	}
	if(exp==1)
	{
		return m;
	}
	matrix res(2,2,0);
	if(exp&1)
	{
		res=mat_expo(exp-1);
		res=mat_mul(res,m);
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



iii calc_fib(matrix temp)
{
	matrix fib(2,1,1),ans;
	fib.mtrx[1][0]=0;
	ans = mat_mul(temp,fib);
	return ans.mtrx[1][0];
}

void initialize(int node,int left,int right)
{
    if(left==right)
    {
        tree[node]=mat_expo(a[left]);
		//cout<<node<<' '<<left<<' '<<a[left]<<endl;
		//tree[node].prnt();
        return;
    }
    int L,R;
    L=node*2;
    R=L+1;
    int mid=(left+right)/2;
    initialize(L,left,mid);
    initialize(R,mid+1,right);
    tmp = mat_mul(tree[L],tree[R]);
	tree[node] = mat_add(tree[L],tree[R]);
	tree[node] = mat_add(tree[node],tmp);
    return;
}

void update(int node,int left,int right,int val,int idx)
{
    if(left>idx || right<idx) return;
    if(left==right){
        tree[node]=mat_expo(val);
        return ;
    }

    int mid=(left+right)/2;

	int L,R;
	L = node *2;
	R = L+1;
    update(L,left,mid,val,idx);
    update(R,mid+1,right,val,idx);
    tmp = mat_mul(tree[L],tree[R]);
	tree[node] = mat_add(tree[L],tree[R]);
	tree[node] = mat_add(tree[node],tmp);
    return ;
}
matrix unit(2,2,0);    
matrix read(int node,int left,int right,int i,int j)
{
    if(left>=i && right<=j) return (tree[node]);
    if(right<i || left>j) return unit;

    matrix part1,part2;
    int mid=(left+right)/2;
    part1=read(node*2,left,mid,i,j);
    part2=read(node*2+1,mid+1,right,i,j);
	tmp = mat_mul(part1,part2);
	tmp = mat_add(part1,tmp);
	tmp = mat_add(part2,tmp);
    return tmp;
}


int main()
{
	matrix ans,temp;
	iii l;
	m.mtrx[1][1]=0;
	fib.mtrx[1][0]=0;
	bl.mtrx[0][0]=bl.mtrx[1][1]=1;
	/*
	ans = m.mat_mul(m.mat_expo(5),fib);
	ans.prnt();
	ans = m.mat_mul(m.mat_expo(3),fib);
	ans.prnt();
	*/

	int t;
	int n,q;
	//while(t--){
		cin>>n>>q;
		for(int i=0;i<n;i++){
			scanf("%lld",a+i);
		}
/*		ans = m.mat_expo(a[0]);
		f[0]= ans;
		ans = ans.mat_mul(ans,ans);
		
		for(int i =1;i<n;i++){
			temp = m.mat_expo(a[i]);
			ans = m.mat_mul(f[i-1],temp);
			ans = ans.mat_add(ans,temp);
			ans = ans.mat_add(ans,f[i-1]);
			f[i]=ans;
		}
		for(int i=0;i<n;i++){
			cout<<calc_fib(f[i])<<endl;
		}
*/
		n--;
		initialize(1,0,n);
		/*
		cout<<read(1,0,n,0,0)<<endl;
		cout<<read(1,0,n,0,1)<<endl;
		cout<<read(1,0,n,0,2)<<endl;
		*/
		char ch;
		iii a,b;
		while(q--){
			scanf(" %c %d %d",&ch,&a,&b);
			if(ch == 'Q'){
				temp=read(1,0,n,a-1,b-1);
				printf("%lld\n",calc_fib(temp));
			}
			else {
				update(1,0,n,b,a-1);
			}
		}
			
//	}
		
		


		

		

		

	return 0;
}

