//round 301 div 2


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

double dp[110][110][110];

double calc_paper(double p,double r,double s,int type)
{
    if(type==3){
        if(p==0) return 0;
        if(s==0) return 1.0;
        if(r==0) return 0;
    }
    else if(type==2){
        if(s==0) return 0;
        if(r==0) return 1;
        if(p==0) return 0;
    }
    else{
        if(r==0) return 0;
        if(p==0) return 1;
        if(s==0) return 0;
    }

    double &ret = dp[(int)p][(int)r][(int)s];
    if(ret>=0) return ret;

    double paper=0,c=0;
    double total=p+s+r;
    total=(total*(total-1))/2;

    if(p>0 && s>0){
            paper=(p*s)*calc_paper(p-1,r,s,type);

    }
    if(r>0 && s>0)
    {
        paper+=r*s*calc_paper(p,r,s-1,type);

    }
    if(p>0 && r>0){
        paper+=p*r*calc_paper(p,r-1,s,type);

    }

    paper=paper/total;

    double same=((p*(p-1)/2)+(r*(r-1)/2)+(s*(s-1)/2))/total;


    return ret=paper/(1-same);
}


int main()
{
    double rock,paper,scissor;

    cin>>rock>>scissor>>paper;

    ms(dp,-1);
    printf("%.11lf ",calc_paper(paper,rock,scissor,1));
    ms(dp,-1);
    printf("%.11lf ",calc_paper(paper,rock,scissor,2));
    ms(dp,-1);
    printf("%.11lf\n",calc_paper(paper,rock,scissor,3));



    return 0;
}

