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
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

struct info{
    iii mn;
    iii area;
}tree[MAXN*3];


int array[MAXN];

void initialize(int node,int left,int right)
{
    if(left==right)
    {
        tree[node].area=array[left];
        tree[node].mn=array[left];
        return;
    }
    int L,R;
    L=node*2;
    R=L+1;
    int mid=(left+right)/2;
    initialize(L,left,mid);
    initialize(R,mid+1,right);
    tree[node]=min(tree[L].area,tree[R].area);
    iii nw=min(tree[L].mn,tree[R].mn);
    tree[node].mn=nw;

    nw=nw*(right-
    return;
}

void update(int node,int left,int right,int val,int idx)
{
    if(left>idx || right<idx) return;
    if(left==right){
        tree[node]=val;
        return ;
    }

    int mid=(left+right)/2;

    update(node*2,left,mid,val,idx);
    update(node*2+1,mid+1,right,val,idx);
    tree[node]=tree[node*2]+tree[node*2+1];
    return ;
}
    
int read(int node,int left,int right,int i,int j)
{
    if(left>=i && right<=j) return tree[node];
    if(right<i || left>j) return 0;

    int part1,part2;
    int mid=(left+right)/2;
    part1=read(node*2,left,mid,i,j);
    part2=read(node*2+1,mid+1,right,i,j);
    return part1+part2;
}



int main()
{
    for(int i=0;i<10;i++)
    {
        array[i+1]=i+1;
    }
    initialize(1,1,10);

    print(read(1,1,10,1,10));

    for (int  i = 0; i <10 ; i++) {
     update(1,1,10,i+1,i+1);
    }
    for (int  i = 0; i < 10; i++) {
     cout<<"tree: "<<tree[i+1]<<endl;
    }

    for (int  i = 0; i < 10; i++) {
     print(read(1,1,10,1,i+1));
    }




    return 0;
}

