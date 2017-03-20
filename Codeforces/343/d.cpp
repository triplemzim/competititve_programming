#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define print(x) printf("debug= %d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vecotr<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

double tree[MAXN];

int minVal(int x, int y) { return (x < y)? x: y; }
 
// A utility function to get the middle index from corner indexes.
int getMid(int s, int e) {  return s + (e -s)/2;  }

int array[MAXN/3];

void initialize(int node,int left,int right)
{
    if(left==right)
    {
        tree[node]=array[left];
        return;
    }
    int L,R;
    L=node*2;
    R=L+1;
    int mid=(left+right)/2;
    initialize(L,left,mid);
    initialize(R,mid+1,right);
    tree[node]=tree[L]+tree[R];
    return;
}

void update(int node,int left,int right,double val,int idx)
{
    if(left>idx || right<idx) return;
    if(left==right){
        tree[node]=val;
        return ;
    }

    int mid=(left+right)/2;

    update(node*2,left,mid,val,idx);
    update(node*2+1,mid+1,right,val,idx);
    tree[node]=max(tree[node*2],tree[node*2+1]);
    return ;
}
    
double read(int node,int left,int right,int i,int j)
{
    if(left>=i && right<=j) return tree[node];
    if(right<i || left>j) return 0;

    double part1,part2;
    int mid=(left+right)/2;
    part1=read(node*2,left,mid,i,j);
    part2=read(node*2+1,mid+1,right,i,j);
    return max(part1,part2);
}

double vol[100009];
pair<double,int> pvol[100009];
int idx[100009];

double calc_vol(double r,double h)
{
	return (r*r*h);
}

int main()
{
	int n;
	double r,h;	


	scan(n);

	for(int i=0;i<n;i++){
		scanf("%lf %lf",&r,&h);
		pvol[i]=MP(calc_vol(r,h),i);
		vol[i]=pvol[i].first;
	}

	sort(pvol,pvol+n);


	for(int i=0;i<n;i++){
		idx[pvol[i].second]=i;
	}

	
	idx[pvol[0].second] = 0;
    
	for(int i=1;i<n;i++){
	    if (pvol[i].first == pvol[i - 1].first){
	        idx[pvol[i].second] = idx[pvol[i - 1].second];
	    }
		else{
		    idx[pvol[i].second] = idx[pvol[i - 1].second] + 1;
		}
	}

	for(int i=0;i<n;i++){
		double temp=read(1,0,n,0,idx[i]-1);
		update(1,0,n,temp+vol[i],idx[i]);
	}

	printf("%.8lf\n",pi*read(1,0,n,0,n));











    return 0;
}

