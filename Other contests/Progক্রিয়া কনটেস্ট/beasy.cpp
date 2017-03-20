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
iii tree[MAXN],maxval;

int read(int idx)
{
    iii sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(-idx & idx);
    }
    return sum;
}

void update(int idx,iii val)
{
    while(idx<=maxval)
    {
        tree[idx]+=val;
        idx+=(idx & -idx);
    }
}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int cases;
    iii a,b;
    bool ace[1111]={false};
    maxval=1010;
    ms(tree,0);
    vector<iii> v;
    for(iii i=2;i<32;i++)
    {
        for(iii j=2;j<10;j++){
            iii k=power(i,j);
            for(iii s=k;s<1001;s+=k){
                if(ace[s]==false){
                    ace[s]=true;
                    v.pb(s);
//                    cout<<s<<' ';
                }
            }
        }
    }
//    cout<<endl;
//    cout<<v.size()<<endl;
    for(int i=0;i<(int)v.size();i++){
        for(int j=i+1;j<(int)v.size();j++){
            int temp=v[i]+v[j];
            if(temp<1001 && ace[temp]==false){
                ace[temp]=true;
                v.pb(temp);
            }
        }
    }
    for(int i=0;i<(int)v.size();i++){
        update(v[i],1);
    }
    for(int i=1;i<1001;i++){
        if(ace[i]==false) cout<<i<<' ';
    }
    cout<<endl;

    scan(cases);
    while(cases--){
        cin>>a>>b;

        cout<<read(b)-read(a-1)<<endl;
    }


    return 0;
}
