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


int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    int n;
    string st[111];
    int minlen;
    scan(n);
    for (int  i = 0; i < n; i++) {
        cin>>st[i];
        if(i==0) minlen=st[i].length();
        else minlen=min(minlen,(int)st[i].length());
    }


    map<pair<int,int> ,bool> mp;
    bool ch[333]={false};

    int val[333]={0};

    int v=1,s=0;
    bool flag=true;

    vector<string>V;
    for(int i=0;i<minlen;i++){
        V.clear();
        for(int j=0;j<n;j++){
            V.pb(st[j]);
        }
        int vsize=V.size();

        
        char c=V[0][i];
        if(ch[c]==false) val[c]=v++,ch[c]=true;

        for(int k=1;k<vsize;k++){
            if(mp[MP(k,k-1)]==true) continue;
            if(V[k][i]!=V[k-1][i]){
                char c1=V[k][i],c2=V[k-1][i];
                if(val[c1] && val[c2]){
                    if(val[c1]<val[c2]){
                        flag=false;
                    }
                }
                mp[MP(k,k-1)]=true;
//                cout<<k<<' '<<k-1<<endl;
                if(val[c2]==0) val[c2]=v++,ch[c2]=true;
                if(val[c1]==0) val[c1]=v++,ch[c1]=true;
            }
        }
    }

    if(flag){
        for(int i=1;i<27;i++){
            for(int j='a';j<'z'+1;j++){
                if(val[j]==i) cout<<(char)j;
            }
        }
        for(char x='a';x<'z'+1;x++){
            if(ch[x]==false) cout<<x;
        }
        cout<<endl;
    }
    else cout<<"Impossible"<<endl;

            






    return 0;
}
