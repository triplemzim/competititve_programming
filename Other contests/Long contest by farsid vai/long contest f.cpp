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
#define MOD 100000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}
#define lim 100001

iii bst[100009];
void calc_bst()
{
    bst[0]=1;
    bst[1]=1;
    for(int i=2;i<1119;i++)
    {
        bst[i]=0;
        for(int j=0;j<i;j++)
        {
            bst[i]+=(bst[j]*bst[i-j-1])%MOD;
            bst[i]%=MOD;
        }
//        if(i<10) cout<<i<<' '<<bst[i]<<endl;
    }
//    cout<<bst[900]<<endl;
//    cout<<bst[50]<<endl;
//    cout<<bst[5]<<endl;
}


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);


    calc_bst();
    vector<iii> track;
    map<iii,bool> mp;

    int test,cases=1;
    iii a,b,x,y;
    a=2;b=100009;x=2;y=b;
    for(iii i=2;i<b;i++)
    {
        iii temp=i*i;
        while(temp<10000000001){
            if(mp.find(temp)==mp.end())
            {
                mp[temp]=true;
//                if(i<10) cout<<temp<<endl;
                track.pb(temp);
            }
            temp*=i;
        }
    }
    sort(track.begin(),track.end());
//    for(int i=0;i<40;i++) cout<<track[i]<<' ';
//    cout<<endl;
//    cout<<bst[29]<<endl;

    cin>>test;
    while(test--){
        scanf("%lld %lld",&a,&b);
        printf("Case %d: ",cases++);

        int low=0,high=track.size()-1,mid;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(a<track[mid])
            {
                high=mid-1;
            }
            else if(a>track[mid])
            {
                low=mid+1;
            }
            else
            {
                low=mid;
                break;
            }
        }
        x=low;
        low=0;high=track.size()-1;
        while(low<=high)
        {
            mid=(low+high)/2;
            if(b<track[mid])
            {
                high=mid-1;
            }
            else if(b>track[mid]) low=mid+1;
            else
            {
                high=mid;
                break;
            }
        }
        y=high;
        x=y-x+1;
        if(x) cout<<bst[x]<<endl;
        else cout<<0<<endl;
        
    }

            

    return 0;
}
