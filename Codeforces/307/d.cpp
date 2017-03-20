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
#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


iii mod =10000007;
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

iii bigMod(iii base,iii power,iii MOD)
{
    if(power==1) return base%MOD;
    if(power==0) return (iii)1;

    if(power&1) return (bigMod(base,power-1,MOD)*(base%MOD))%MOD;
    else{
        iii temp=bigMod(base,power/2,MOD)%MOD;
        return (temp*temp)%MOD;
    }
}
#define sets(n,pos) (n|(1<<pos))
#define reset(n,pos) (n& ~(1<<pos))
#define check(n,pos) (bool(n&((iii)1<<pos)))



int main()
{
    matrix m(2,2,0),got(2,2,0);
    m.mtrx[0][0]=m.mtrx[0][1]=m.mtrx[1][0]=1;
    m.mtrx[1][1]=0;

//    got=m.mat_expo(2);
//    for(int i=0;i<2;i++){
//        for(int j=0;j<2;j++){
//            cout<<got.mtrx[i][j]<<' ';
//        }
//        cout<<endl;
//    }
    
    iii n,k,l,M;
    cin>>n>>k>>l>>M; 
    mod=M;

    if(l<63 && (((iii)1)<<l) <=k) {
        cout<<"0"<<endl;
        return 0;
    }

    iii two=bigMod(2,n,mod);
    int one=0,zero=0;

    for(iii i=0;i<l;i++){
        if(check(k,i)==true){
            one++;
        }
        else {
            zero++;
        }
    }

    got=m.mat_expo(n-2);
    iii val= (got.mtrx[0][0]*(iii)3)%mod +(got.mtrx[0][1]* (iii)2)%mod;
    val%=mod;
        if(n==2) val=3;

    iii noone=two-val,ans=1;
    while(noone<0) noone+=mod;
    noone%=mod;
    for(int i=0;i<one;i++){
        ans*=noone;
        ans%=mod;
    }
    for(int j=0;j<zero;j++){
        ans*=val;
        ans%=mod;
    }

    cout<<ans%mod<<endl;






    return 0;
}


