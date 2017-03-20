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


class seg_tree_lazy_prop{
public:
    iii sum;
    iii prop;

}tree[MAXN*3];


int array[MAXN];

void initialize(int node,int left,int right)
{
    if(left==right)
    {
        tree[node].sum=array[left];
        tree[node].prop=0;
        return;
    }
    int L,R;
    L=node*2;
    R=L+1;
    int mid=(left+right)/2;
    initialize(L,left,mid);
    initialize(R,mid+1,right);
    tree[node].sum=tree[L].sum+tree[R].sum;
    tree[node].prop=0;
    return;
}

void update(int node,iii left,iii right,int s,int e,iii val)
{
    if(left>e || right<s) return;
    if(left>=s && right<=e){
        tree[node].sum+= val*(right-left+1);
        tree[node].prop+=val;
        return ;
    }

    int mid=(left+right)/2;
    int i=node<<1,j=i+1;

    update(i,left,mid,s,e,val);
    update(j,mid+1,right,s,e,val);
    tree[node].sum=tree[i].sum+tree[j].sum+tree[node].prop*(right-left+1);
    return ;
}
    
iii read(int node,iii left,iii right,int i,int j,iii carry=0)
{
    if(left>=i && right<=j) return tree[node].sum + carry*(right-left+1);
    if(right<i || left>j) return 0;

    iii part1,part2;
    int mid=(left+right)/2;
    part1=read(node*2,left,mid,i,j,carry+tree[node].prop);
    part2=read(node*2+1,mid+1,right,i,j,carry+tree[node].prop);
    return part1+part2;
}



int main()
{
    for(int i=0;i<10;i++)
    {
        array[i+1]=1;
    }
    initialize(1,1,10);

    print(read(1,1,10,5,10));

    update(1,1,10,5,10,1);
    update(1,1,10,4,10,1); 

    print(read(1,1,10,4,9));
    




    return 0;
}

