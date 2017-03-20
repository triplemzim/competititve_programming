
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
#define MOD 1000000007 // 10^9 + 7

template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}



#define MAXLG 16
#define MAXN 65536

struct entry{
    int nr[2],p;
    bool operator<(const entry a)const
    {
        return nr[0]==a.nr[0]? (nr[1]<a.nr[1]?1:0): (nr[0]<a.nr[0]?1:0);
    }
}L[MAXN];
int rank[MAXLG][MAXN],len,step,LCP[MAXN];
char ch[MAXN];

int suffix_array();
int lcp(int x,int y);
    int sidx[MAXN];
    int ace[MAXN];

int table[MAXN];
void kmp_table(char *st){
    int ln=strlen(st);
    int k=-1;
    ms(table,0);
    table[0]=-1;
    for(int i=1;i<ln;i++){
        while(k>-1 && st[k+1]!=st[i]) k=table[k];
        if(st[k+1]==st[i]) k++;
        table[i]=k;
    }
}

void substring_match(char *st){
    kmp_table(st);
    int k=-1;
    int ln=strlen(st); 
    len=strlen(ch);

    for(int i=0;i<len;i++){
        while(k>-1 && ch[i]!=st[k+1]) k=table[k];
        if(ch[i]==st[k+1]) k++;
        if(k==ln-1){
            ace[i-k]=i-k;
//            cout<<i-k<<' ';
        }
    }
//    cout<<endl;
}




    



int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);
    int cases,caseno=1,STEP;
    scan(cases);
    getchar();

char st[MAXN];
while(cases--){
//    gets(ch);
//    gets(st);
    scanf("%s",ch);
    scanf("%s",st);
    len=strlen(ch);
    ms(ace,-1);
    
    substring_match(st);
    int temp=ace[len-1];
    for(int i=len-1;i>=0;i--){
        if(ace[i]!=-1){
            temp=ace[i];
        }
        ace[i]=temp;
    }
//    for(int i=0;i<len;i++)
//    {
//        cout<<ace[i]<<' ';
//    }
//    cout<<endl;

    STEP=suffix_array();
//    cout<<STEP<<endl;
//    for(int i=0;i<len;i++){
//        cout<<sidx[i]<<' ';
//    }
//    cout<<"else"<<endl;

    int ln=strlen(st);
    LCP[0]=0;
    iii count=0;
    if(ace[sidx[0]]!=-1) {
        int last=ace[sidx[0]]+ln;
        count=last-sidx[0]-1;
    }
    else count=len-sidx[0];
    for(int i=1;i<len;i++)
    {
        step=STEP;
        LCP[i]=lcp(sidx[i],sidx[i-1]);
//        cout<<"("<<sidx[i]<<' '<<sidx[i-1]<<")"<<LCP[i]<<' ';
//        cout<<len-sidx[i]-LCP[i]<<" + ";
        int where=ace[sidx[i]];
        if(where!=-1)
        {
            int last=where+ln;
            if(last>sidx[i]+LCP[i]){
                count+=last-(sidx[i]+LCP[i])-1;
            }
            

        }
        else{ 
            count+=len-sidx[i]-LCP[i];
//            cout<<"where: "<<len-sidx[i]<<' '<<LCP[i]<<endl;

        }
            

    }
//    cout<<endl;
    printf("Case %d: %lld\n",caseno++,count);
    

    
}
        



    return 0;
}

int lcp(int x, int y)
{
    int cp=0;
    for(int i=step-1;i>=0 && x<len && y<len ;i--)
    {
        if(rank[i][x]==rank[i][y])
        {
            
            cp+=power(2,i);
            x+=power(2,i);
            y+=power(2,i);
        }
    }
    return cp;
}



int suffix_array()
{
//    scanf("%s",ch);
    ms(rank,0);
    len=strlen(ch);

    for(int i=0;i<len;i++)
    {
        rank[0][i]=ch[i]-'a';
    }

    int cnt;
    for(cnt=1,step=1;cnt>>1<len;step++,cnt<<=1)
    {
        for (int  i = 0; i < len; i++) {
            L[i].nr[0]=rank[step-1][i];
            L[i].nr[1]=i+cnt<len? rank[step-1][i+cnt]:-1;
            L[i].p=i;
        }

        sort(L,L+len);

        for(int i=0;i<len;i++)
        {
            rank[step][L[i].p]= i>0 && L[i-1].nr[0]==L[i].nr[0] && L[i-1].nr[1]==L[i].nr[1] ? rank[step][L[i-1].p] : i;
        }
    }
    for(int i=0;i<len;i++) {
        sidx[i]=L[i].p;
    }

    return step;
}
    


   
