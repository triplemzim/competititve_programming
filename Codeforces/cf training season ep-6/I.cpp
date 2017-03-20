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

bool tie[55]={false};
 map<string,int> mp;

class jdata
{
    public:

    int total_time=0;
    string team_name;
    bool problem_status[100]={false};
    int submission_total_time[100]={0},submission_time[100]={0},s_time[100]={0};
    int total_ac=0,penalty[100]={0};
    char last_ac='\0';
    vector<char> subsq;

    void update(int &time,char &id,string &vdct)
    {
        if(vdct=="rejected")
        {
            if(problem_status[id]==false)
                penalty[id]+=20;
        }
        else if(problem_status[id]==false)
        {
            total_ac++;
            int t=time+penalty[id];
            total_time+=t;
            problem_status[id]=true;
            last_ac=id;
            submission_total_time[id]=total_time;
            submission_time[id]=t;
            subsq.pb(id);
            s_time[id]=time;
        }
    }



};

bool compare(const jdata &x,const jdata &y)
{
    if(x.total_ac>y.total_ac) return true;
    else if(x.total_ac<y.total_ac) return false;
    else
    {
        if(x.total_time<y.total_time) return true;
        else if(x.total_time>y.total_time) return false;
        else
        {
//            cout<<x.team_name<<' '<<y.team_name<<endl;
            for(int i=x.subsq.size()-1;i>=0;i--)
            {
                char ch=x.subsq[i],CH=y.subsq[i];
//                cout<<x.submission_total_time[ch]<<' '<<y.submission_total_time[CH]<<endl;

                if(x.s_time[ch]<y.s_time[CH]) return true;
                else if(x.s_time[ch]>y.s_time[CH]) return false;
                if(x.submission_total_time[ch]<y.submission_total_time[CH]) return true;
                else if(x.submission_total_time[ch]>y.submission_total_time[CH]) return false;

            }

            if(x.team_name<y.team_name)
            {
                tie[mp[y.team_name]]=true;
                return true;
            }
            else
            {
                tie[mp[x.team_name]]=true;
                return false;
            }
        }
    }
}


int main()
{
freopen("in.txt","r",stdin);

    int cases,n,m;
    int time,idx;
    string vdct,name;
    char id;
    cin>>cases;
    while(cases--)
    {
        jdata data[55];
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            cin>>data[i].team_name;
            mp[data[i].team_name]=i;
        }
        for(int i=0;i<m;i++)
        {
            cin>>time>>name>>id>>vdct;
            idx=mp[name];
            data[idx].update(time,id,vdct);
        }
        sort(data,data+n,compare);

        int Rank=0;
        for(int i=0;i<n;i++)
        {
            if(tie[mp[data[i].team_name]]==false) Rank=i+1;
            cout<<Rank<<' '<<data[i].team_name<<' '<<data[i].total_ac<<' '<<data[i].total_time<<endl;
        }
    }






    return 0;
}
