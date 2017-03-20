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



int main(){
    iii w,m;
    cin>>w>>m;

    while(m>1){
        if(m%w==0){
            m/=w;
        }
        else if((m-1)%w==0){
            m=(m-1)/w;
        }
        else if((m+1)%w==0){
            m=(m+1)/w;
        }
        else break;
    }
    
    if(m>1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;
}




//    vector<iii> first,second;
//    int sz;
//
//bool srch(iii val){
//    int high=sz-1,low=0,mid;
//
//    while(low<=high){
//        mid=(low+high)/2;
//        if(second[mid]==val) return true;
//        if(second[mid]>val){
//            low=mid+1;
//        }
//        else high=mid-1;
//    }
//    return false;
//}
//
//
//
//
//int main()
//{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

//    iii w,m;
//    cin>>w>>m;
//
//    vector<iii> coin;
//    iii p=0,net=1;
//    coin.pb(1);
//    while(net<=1000000000){
//        p++;
//        net=power(w,p);
//        coin.pb(net);
//    }
//
//
//    int lim=p/2;
//
//    first.pb(0);
//    second.pb(0);
//
//    int whoa=1;
//    for(int i=0;i<=lim;i++){
//        for(int j=0;j<whoa;j++){
//            first.pb(first[j]+coin[i]);
//            first.pb(first[j]-coin[i]);
//        }
//        whoa += 2*whoa;
//    }
//    sz=1;
//    for(int i=lim+1;i<=p;i++){
//        for(int j=0;j<sz;j++){
//            second.pb(second[j]+coin[i]);
//            second.pb(second[j]-coin[i]);
//        }
//        sz+=2*sz;
//    }
//    sort(first.begin(),first.end());
//    sort(second.begin(),second.end());
//
//    whoa=first.size();
//    sz=second.size();
//    cout<<whoa<<' '<<sz<<endl;
//    return 0;
//
//    for(int i=0;i<whoa;i++){
////        if(srch(second,m-first[i]) || srch(second,m+first[i])){
//        if(srch(m+first[i])){
//            cout<<"YES"<<endl;
//            return 0;
//        }
//    }
//    cout<<"NO"<<endl;
//
//
//    return 0;
//}
