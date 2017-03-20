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
#define MAXN 100009
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}

int n,q,num[MAXN],tree[MAXN*3];

int build(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=num[b];
        return 0;
    }
    int left=node*2,right=node*2+1,mid=(b+e)/2;

    build(left,b,mid);
    build(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
    return 0;
}

int query(int b,int e,int l,int r,int node)
{
    if(r<b || l>e) return 0;
    if(b<=l && r<=e) return tree[node];

    int left=node*2,right=node*2+1,mid=(l+r)/2;

    int A=query(b,e,l,mid,left);
    int B=query(b,e,mid+1,r,right);

    return A+B;
}

int update(int b,int e,int idx,int val,int node)
{
    if(b>idx || e<idx) return 0;
    if(b==e)
    {
        tree[node]=val;
        return 0;
    }


    int left=node*2,right=node*2+1,mid=(b+e)/2;

    update(b,mid,idx,val,left);
    update(mid+1,e,idx,val,right);
    tree[node]=tree[left]+tree[right];

    return 0;
}





int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases,caseno=1,idx,type,a,b,newVal;

    scan(cases);
    while(cases--)
    {
        scan(n);
        scan(q);
        for (int  i = 0; i < n; i++) {
            scan(num[i+1]);
        }

        build(1,1,n);
        printf("Case %d:\n",caseno++);

        for (int  i = 0; i < q; i++) {
            scan(type);
            if(type==1)
            {
                scan(idx);
                
                
                int val=query(idx+1,idx+1,1,n,1);
//                cout<<"deleting.. "<<val<<endl;
                update(1,n,idx+1,0,1);
                print(val);
                
            }
            else if(type==2)
            {
                scan(idx);
                scan(newVal);
                int val=query(idx+1,idx+1,1,n,1);
//                update(1,n,idx+1,-val,1);
                update(1,n,idx+1,val+newVal,1);
            }
            else
            {
                scan(a);
                scan(b);
                print(query(a+1,b+1,1,n,1));
            }
        }
    }




    return 0;
}                       
