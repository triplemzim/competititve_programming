// status: AC

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define pii pair<int,int>
#define iii long long
#define ull unsigned long long
#define mod 10
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
                    ret.mtrx[i][j]+=(one.mtrx[i][k]*two.mtrx[k][j])%mod;
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
//        matrix res=mat_expo(exp/2);
//        res=mat_mul(res,res);
//        if(exp&1)
//        {
//            res=mat_mul(res,*this);
//        }
        return res;
    }
};


int r,c,n;

void print(matrix x)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<x.mtrx[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<endl;
}
matrix solve(int k,matrix ret_m)
{
    if(k==0)
    {
        matrix bl(n,n,1);
        return bl;
    }
    if(k==1) return ret_m;

    matrix temp(n,n,0);
    if(k&1)
    {
        temp=solve(k-1,ret_m);
        matrix t=ret_m;
        t=t.mat_expo(k);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++) temp.mtrx[i][j]+=t.mtrx[i][j];
    }
    else
    {
        matrix t=ret_m;
        t=t.mat_expo(k/2);
        temp=solve(k/2,ret_m);
        t=temp.mat_mul(temp,t);

        for(int i=0;i<n;i++)for(int j=0;j<n;j++) temp.mtrx[i][j]=(temp.mtrx[i][j]+t.mtrx[i][j])%mod;
    }
    return temp;

}


int main()
{
    int k,temp;


    while(cin>>n)
    {
        if(!n) break;
        cin>>k;
        r=c=n;
        matrix mat(r,c,0),ans(r,c,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>mat.mtrx[i][j];
            }
        }

        ans=solve(k,mat);
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cout<<ans.mtrx[i][j]%mod;
                if(j!=c-1) cout<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}

