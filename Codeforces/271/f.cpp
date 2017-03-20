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

int n;
iii s[100009],tree[1000000];

void build_tree(int cur,int b,int e)
{
    if(b==e) {
        tree[cur]=s[b];
        return;
    }

    int left=cur*2,right=left+1,mid=(b+e)/2;

    build_tree(left,b,mid);
    build_tree(right,mid+1,e);
    tree[cur]=gcd(tree[left],tree[right]);

    return;
}

iii qry(int cur,int b,int e,int i,int j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[cur];
    
    int left=cur*2,right=left+1,mid=(b+e)/2;
    iii ans=gcd(qry(left,b,mid,i,j),qry(right,mid+1,e,i,j));
    return ans;
}

map<iii,int>mp;
vector<int> v[100009];
vector<int>::iterator it;

int lowerb(int val,int index)
{
    
    int low=0,high=v[index].size()-1,mid=(low+high)/2;
    while(low<=high)
    {
        if(v[index][mid]==val) return mid-1;
        if(v[index][mid]>val)
        {
            high=mid-1;
            mid=(low+high)/2;
        }
        else
        {
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return high;
}
        
int higherb(int val,int index)
{
    
    int low=0,high=v[index].size()-1,mid=(low+high)/2;
    while(low<=high)
    {
        if(v[index][mid]==val) return mid;
        if(v[index][mid]>val)
        {
            high=mid-1;
            mid=(low+high)/2;
        }
        else
        {
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    return high;
}


int main()
{
//    freopen("in.txt","r",stdin);
    char ch='abc0';
    printf("%d",ch);
    int index=1;
    
    scan(n);
    for (int  i = 0; i < n; i++) {
        cin>>s[i+1];
        if(mp.count(s[i+1])<1) mp[s[i+1]]=index++;
        v[mp[s[i+1]]].pb(i+1);
    }
    
    build_tree(1,1,n);

//    cout<<qry(1,1,n,1,3)<<endl;
//    cout<<qry(1,1,n,3,5)<<endl;

    int q;
    scan(q);
    int a,b,low1,low2,gcd;
    while(q--)
    {
        scan(a);
        scan(b);
        gcd=qry(1,1,n,a,b);
        index=mp[gcd];

        low1=lowerb(a,index);
        low2=higherb(b,index);
//        cout<<"debug: "<<b<<' '<<low2<<' '<<low1<<endl;
        cout<<(b-a+1)-low2+low1<<endl;

    }
         

    return 0;
}
