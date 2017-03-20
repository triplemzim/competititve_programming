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

iii n,m,a,minans;
int b;
vector< pair<iii,int> > server,vlow,vhigh;
stack< iii > anslow,anshigh;
stack< iii> stlow,sthigh;
iii clow[1000009]={0},chigh[1000009]={0},low[200009],high[200009],idlow=0,idhigh=0;

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    cin>>n>>m;
//    scanf("%I64d %I64d",&n,&m);
    pair<iii,int> p;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
//        scanf("%I64d %d",&a,&b);
        
        p=MP(a,b);
        server.pb(p);
        if(b)
        {
            low[idlow++]=a;
            vlow.pb(MP(a,i+1));
//            if(mplow[a].find()==mp.end())
//            {
//                mplow[a]=vl++;
//            }
        }
        else {
//            if(mphigh.find(a)==mphigh.end())
//            {
//                mphigh[a]=vh++;
//            }
//            mphigh[a].pb(i+1);
            vhigh.pb(MP(a,i+1));
            high[idhigh++]=a;
        }
        
        
    }
    sort(server.begin(),server.end());
    sort(low,low+idlow);
    sort(high,high+idhigh);
    sort(vlow.begin(),vlow.end());
    sort(vhigh.begin(),vhigh.end());

    int mnC=0;
    iii sum=0;
    for(int i=server.size()-1;i>=0;i--)
    {
        sum+=server[i].first;
        mnC++;
        if(sum>=m) break;
    }
    minans=mnC;

    iii temp=1;
    clow[0]=low[idlow-1];
    for(int i=idlow-2;i>=0;i--)
    {
        clow[temp]=clow[temp-1]+low[i];
//        cout<<clow[temp]<<' ';
        temp++;
    }
//    cout<<endl;
    temp=1;
    chigh[0]=high[idhigh-1];
    for(int i=idhigh-2;i>=0;i--)
    {
        chigh[temp]=chigh[temp-1]+high[i];
//        cout<<chigh[temp]<<' ';
        temp++;
    }
//    cout<<endl;

    iii cur_sum=0,ida,idb;
    if(mnC>idlow)
    {
        cur_sum=clow[idlow-1]+chigh[mnC-idlow-1];
        ida=idlow-1;
        idb=mnC-idlow-1;
    }
    else
    {
        cur_sum=clow[mnC-1];
        ida=mnC-1;
        idb=-1;
    }
//    cout<<ida<<' '<<idb<<endl;

    while(cur_sum<m)
    {
//        cout<<cur_sum<<endl;
        cur_sum=clow[ida-1]+chigh[idb+1];
        ida--;
        idb++;
    }
    cout<<minans<<' '<<ida+1<<endl;

    for(int i=idlow-1;i>=idlow-1-ida;i--)
    {
        cout<<vlow[i].second<<' ';
//        temp=low[i];
//        cout<<mplow[temp][0]<<' ';
//        mplow[temp].erase(mplow[temp].begin());
    }
    
    for(int i=idhigh-1;i>=idhigh-1-idb;i--)
    {
        cout<<vhigh[i].second<<' ';
//        temp=high[i];
//        cout<<mphigh[temp][0]<<' ';
//        mphigh[temp].erase(mphigh[temp].begin());
    }




    return 0;
}
