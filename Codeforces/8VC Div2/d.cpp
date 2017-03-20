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
#define MAXN 200009
int tree1[MAXN],maxval,tree2[MAXN];
 
void update(int idx,int val,int type)
{
    while(idx<=maxval)
    {
        if(type) tree1[idx]+=val;
		else tree2[idx]+=val;
        idx+= (-idx & idx);
    }
}
 
int read(int idx,int type)
{
    int sum=0;
    while(idx!=0)
    {
        if(type) sum+=tree1[idx];
		else sum+=tree2[idx];
        idx-=(idx & -idx);
    }
    return sum;
}


int main()
{
	maxval=200009;

	int n,k,a,b,q,d,thimble,p,type;


	cin>>n>>k>>a>>b>>q;
	while(q--){
		scanf("%d",&type);
		if(type==1){
			scanf("%d %d",&d,&thimble);

			int sum;
			if(d==1) sum=read(d,0);
			else sum=read(d,0)-read(d-1,0);
			
			update(d,min(b-sum,thimble),0);

			if(d==1) sum=read(d,1);
			else sum=read(d,1)-read(d-1,1);

			update(d,min(a-sum,thimble),1);
		}
		else{
			scanf("%d",&p);
			int sum=0;
			if(p+k-1<n){
				sum=read(n,1)-read(p+k-1,1);
			}
			if(p>1){
				sum+=read(p-1,0);
			}
			printf("%d\n",sum);
		}
	}
	






	return 0;
}
