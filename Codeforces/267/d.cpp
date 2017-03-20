#include<bits/stdc++.h>

using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define scanL(x) scanf("%I64d",&x)
#define print(x) printf("%d\n",x)
//#define debug(x) printf("DEBUG: %d\n",x)
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


#define DEBUG 1 
#if DEBUG && !ONLINE_JUDGE 
    #define debug(args...) (Debugger()) , args
    class Debugger { public: Debugger(const std::string& _separator = ", ") : first(true), separator(_separator){} template<typename ObjectType> Debugger& operator , (const ObjectType& v) { if(!first) std::cerr << separator; std::cerr << v; first = false; return *this; } ~Debugger() { std::cerr << endl;} private: bool first; std::string separator; }; template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::vector<T>& v) { bool first = true; os << "["; for(unsigned int i = 0; i < v.size(); i++) { if(!first) os << ", "; os << v[i]; first = false; } return os << "]"; } template<typename T> inline std::ostream &operator << (std::ostream & os,const std::set<T>& v) { bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii; first = false; } return os << "]"; } template<typename T1, typename T2> inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v) { bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii) { if(!first) os << ", "; os << *ii ; first = false; } return os << "]"; } 
#else 
        #define debug(args...) 
#endif


struct ob
{
    string ch;
    int R,len;
    int clen(){len=ch.length();return len;}
    bool operator<(const ob x)const{ return R==x.R ? len < x.len : R<x.R ;}
    int cR()
    {
        R=0;
        for (int  i = 0; i < len; i++) {
            if(ch[i]=='r') R++;
        }
        return R;
    }
    void con()
    {
        for (int  i = 0; i < len; i++) {
            ch[i]=tolower(ch[i]);
        }
    }
};


vector< ob > v[100009],essay;
map<string,int>mp;

bool color[100009];

ob bfs(ob &Ch)
{
    ms(color,false);
    int idx,in;
    string top;
    ob ret=Ch;
    queue<string > q;

    q.push(Ch.ch);
    if(mp.find(top)!=mp.end()) color[mp[top]]=true;
    while(!q.empty())
    {
        top=q.front();
        
        q.pop();
        if(mp.find(top)==mp.end())
            continue;
        else idx=mp[top];

        for(int i=0;i<(int)v[idx].size();i++)
        {
//            if(top=="aa") cout<<"paici :"<<v[idx][i].ch<<' ';
            in=mp[v[idx][i].ch];
            if(color[in]==false)
            {
                color[in]=true;
                if(v[idx][i]<ret) ret=v[idx][i];
                q.push(v[idx][i].ch);
            }
        }
    }
    
    return ret;
}
        
// int ind,s,lim; 
// ob ret;
//void dfs(ob src)
//{
//    ret=src;
//    ind=mp[src.ch];
//    lim=v[mp[src.ch]].size();
//    for(int i=0;i<lim;i++)
//    {
//        s=mp[v[lim][i].ch];
//        if(color[s]==false)
//        {
//            if(v[ind][i]<ret) ret=v[ind][i];
//            color[s]=true;
//            dfs(v[ind][i]);
//        }
//    }
//}
         
         


int main()
{
    freopen("in.txt","r",stdin);
    
    
    string temp,str;
    int n,m,idx=0;
    ob CH,a,b;
    scan(n);
     for (int  i = 0; i <n ; i++) {
         cin>>CH.ch;
//         len=temp.length();
//         for (int  i = 0; i < len; i++) {
//             temp[i]=tolower(temp[i]);
//         }
         CH.clen();
         CH.con();
         CH.cR();
         essay.pb(CH);
//         cout<<CH.ch<<endl;

     }

    cin>>m;
    for (int  i = 0; i < m; i++) {
        cin>>a.ch>>b.ch;
        a.clen();b.clen();
        a.con();b.con();
        a.cR();b.cR();
        if(mp.find(a.ch)==mp.end()) mp[a.ch]=idx++;
        if(mp.find(b.ch)==mp.end()) mp[b.ch]=idx++;

        v[mp[a.ch]].pb(b);
//        cout<<a.ch<<' '<<b.ch<<' '<<(a<b)<<endl;
//        cout<<a.ch<<' '<<b.ch<<endl;
    }
    for (int  i = 0; i <n; i++) {
//        ms(color,false);
//        color[mp[essay[i].ch]]=true;
//        dfs(essay[i]);
//        essay[i]=ret;
        essay[i]=bfs(essay[i]);
//        debug(essay[i].ch);
//        if(n==36) cout<<essay[i].ch<<endl;
        
        
    }
    int count=0,total=0;

    for (int  i = 0; i < n; i++) {
//        cout<<essay[i].ch<<' ';
        total+=essay[i].len;
        count+=essay[i].R;
    }
    cout<<count<<' '<<total<<endl;



    return 0;
}
