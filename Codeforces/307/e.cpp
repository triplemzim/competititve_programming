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

int BQ;

int n,q,last,sq,l,r,pidx;
iii f,x;
pair<iii,iii> p[1000][1000];
iii a[500009],incval[1000];

void prn(){

    for(int i=0;i<=pidx;i++){
        for(int j=0;j<(i==pidx?last:sq);j++){
            cout<<'('<<p[i][j].first<<' '<<p[i][j].second<<')';
        }
        cout<<endl;
    }
}

void decompose()
{
    BQ=q;
    sq=sqrt(n);

    last=n%sq;
    if(last==0) last=sq;
    int idx=0;
    pidx=-1;
    for(int i=0;i<n;i++){
        if(i%sq==0){
            pidx++;
            idx=0;
        }
        p[pidx][idx]=MP(a[i],i);
        idx++;
    }
    for(int i=0;i<pidx;i++){
        sort(p[i],p[i]+sq);
    }
    sort(p[pidx],p[pidx]+last);

//    prn();

}

    
int binary_src(int id,int type,iii val)
{
    int mid;
    int low=0,high=sq-1;
    if(id==pidx) high=last-1;
    

    while(low<=high){
        mid=(low+high)/2;
        if(p[id][mid].first<val){
            low=mid+1;
        }
        else if(p[id][mid].first>val){
            high=mid-1;
        }
        else {
            if(type==1){
                high=mid-1;
            }
            else low=mid+1;
        }
    }
    if(type==1){
        return p[id][low].first==val?p[id][low].second:-1;
    }
    else return p[id][high].first==val?p[id][high].second:-1;
}

void update(int left,int right,iii val)
{
    left--;
    right--;
    int st=left/sq,fin=right/sq;
    int lim;
    lim=(st==pidx?last:sq);
    for(int i=0;i<lim;i++){
        if(p[st][i].second>=left && p[st][i].second<=right) p[st][i].first+=val;
    }
    for(int i=st+1;i<fin;i++){incval[i]+=val;}

    lim=(fin==pidx?last:sq);
    if(st!=fin){
    for(int i=0;i<lim;i++){
        if(p[fin][i].second<=right && p[fin][i].second>=left) p[fin][i].first+=val;
    }
    }

    sort(p[st],p[st]+(st==pidx?last:sq));
    sort(p[fin],p[fin]+(fin==pidx?last:sq));
//    prn();

}
int t=0,T=0;
void query(iii y)
{
    int left=-1,right=-1;
    bool flag=false;

    for(int i=0;i<=pidx;i++){
        if(flag==false){
            int temp=binary_src(i,1,y-incval[i]);
            if(temp!=-1){
                left=temp;
                right=temp;
                flag=true;
            }
        }
        if(flag==true){
            int temp=binary_src(i,2,y-incval[i]);
            if(temp!=-1 && temp>right){
                right=temp;
            }
        }
    }
//    if(n==500000 && BQ==50000 && a[0]==a[1] && a[2]==a[3] && a[4]==a[5] && a[4]==a[2] && a[2]==a[1] && a[0]==1000000000 &&(t==284) ){
//        cout<<binary_src(0,2,1000000000)<<'-'<<p[0][0].first<<'-'<<p[0][1].first<<'-'<<y<<'-'<<right<<'-'<<left<<endl;
//    }
//    else{
        
    if(left==-1) cout<<-1<<endl;
    else cout<<right-left<<endl;
//    }
}



        
        
        
        


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

   
    cin>>n>>q;

    for (int  i = 0; i < n; i++) {
        cin>>a[i];
    }
    decompose();
    


    int type;

    while(q--){
        scan(type);
        if(type==1){
            scanf("%d %d",&l,&r);
            cin>>x;
            T++;
            update(l,r,x);
        }
        else{
            
            cin>>f;
            t++;
            query(f);

        }
    }




    return 0;
}   
