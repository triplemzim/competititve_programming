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

int tree[4][MAXN],maxval;
int trec[4][MAXN],treh[4][MAXN],tref[4][MAXN];

int read(int idx,int tre[],int i)
{
    iii sum=0;
    while(idx>0){
        sum+=tre[i][idx];
        idx-=(-idx & idx);
    }
    return sum;
}

void update(int idx,iii val,int tre[],int i)
{
    while(idx<=maxval)
    {
        tre[i][idx]+=val;
        idx+=(idx & -idx);
    }
}

int chef[4][MAXN];

int main()
{
//	  ios::sync_with_stdio(false);
//	  freopen("in.txt","r",stdin);

    char ch[1000009];
    int len;
    maxval=len+7;
    scanf("%s",ch);
    len=strlen(ch);

    for(int i=len-1;i>=0;i--){
        chef[0][i]=chef[0][i+1];
        chef[1][i]=chef[1][i+1];
        chef[2][i]=chef[2][i+1];
        chef[3][i]=chef[3][i+1];
        if(ch[i]=='c') ch[0][i]++;
        else if(ch[i]=='h') ch[1][i]++;
        else if(ch[i]=='e') ch[2][i]++;
        else if(ch[i]=='f') ch[3][i]++;
    }

    for(int i=0;i<len;i++){
        if(ch[i]=='c'){
            update(




    return 0;
}
