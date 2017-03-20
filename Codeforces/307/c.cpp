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

int calc(iii second,iii box[],int n,int m)
{
    int idx=n;
    iii val=box[n];
    while(idx && box[idx]==0){
        idx--;
    }
    val=box[idx];


    while(m>0){

        iii temp=second-idx;
        
        
        while(temp>0 && idx>0){
            if(temp>=val){
                temp-=val;
                idx--;
                while(idx && box[idx]==0){ idx--;}

                val=box[idx];
            }
            else{
                val-=temp;
                break;
            }
        }
        m--;
    }
    if(idx<=0) return 0;
    else return 1;
}





int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n,m;
    iii box[MAXN];

    scan(n);
    scan(m);
    iii low,high,mid;
    low=0;
    high=0;
    for(int i=1;i<=n;i++){
        cin>>box[i];
        high+=1+box[i];

    }


    while(low<=high){
        mid=(low+high)/2;
        int temp=calc(mid,box,n,m);
        if(temp==0){
            high=mid-1;
        }
        else if( temp==1){
            low=mid+1;
        }
    }

    cout<<low<<endl;


    

        


    return 0;
}
