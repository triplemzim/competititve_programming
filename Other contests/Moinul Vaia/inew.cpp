
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

#define MAXN 300009
#define MAXLG 25

int shuru[MAXN],shesh[MAXN];
char A[MAXN];
struct entry {
    int  nr[2], p;
} L[MAXN];

int  P[MAXLG][MAXN], N, i, stp, cnt, nthsuffix[MAXN], suffixnumber[MAXN];

int  cmp(struct entry a, struct entry b)
{
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}
int  lcp(int  x, int  y)
{
    int  k, ret = 0;
    if (x == y) return N - x;
    for (k = stp - 1; k >= 0 && x < N && y < N; k --)
    {
        if (P[k][x] == P[k][y])
        {
            x += 1 << k, y += 1 << k, ret += 1 << k;
        }
    }
    return ret;
}
void buildsuffix()
{
    N=0;
    for ( i = 0; *(A+i) ; i ++)
    {
        P[0][i] = *(A+i);
        N++;
    }
    for (stp = 1, cnt = 1; cnt >> 1 < N; stp ++, cnt <<= 1)
    {
        for (i = 0; i < N; i ++)
        {
            L[i].nr[0] = P[stp - 1][i];
            L[i].nr[1] = i + cnt < N ? P[stp - 1][i + cnt] : -1;
            L[i].p = i;
        }
        sort(L, L + N, cmp);
        for (i = 0; i < N; i ++)
        {
            P[stp][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[stp][L[i - 1].p] : i;
        }
    }
    for (i = 0; i < N; i ++)
    {
        nthsuffix[P[stp-1][i]]=i;
        suffixnumber[i]=P[stp-1][i];
    }
}
long long  no_distinct_substr()
{
    long long ans=0;
    ans = N - L[0].p;
    
    int LCP,pos;

    pos=L[0].p;

    if(shuru[pos]!=-1) ans=shesh[pos]-pos;

    for(i = 1; i < N; i++)
    {
        LCP=lcp(nthsuffix[i-1],nthsuffix[i]);
        pos=L[i].p;
        if(shuru[pos]!=-1 && pos+LCP<shesh[pos]){
            ans+=shesh[pos]-pos-LCP;
//            cout<<shesh[pos]<<' '<<pos<<' '<<LCP<<endl;
        }

    
        else if(shuru[pos]==-1)  ans += N - L[i].p - LCP;
    }
    return ans;
}

int *compute_prefix_function(char *pattern, int psize)
{
	int k = -1;
	int i = 1;
	int *Pi = (int*)malloc(sizeof(int)*psize);
	if (!Pi)
		return NULL;

	Pi[0] = k;
	for (i = 1; i < psize; i++) {
		while (k > -1 && pattern[k+1] != pattern[i])
			k = Pi[k];
		if (pattern[i] == pattern[k+1])
			k++;
		Pi[i] = k;
	}
	return Pi;
}

int kmp(char *target, int tsize, char *pattern, int psize)
{
	int i;
	int *Pi = compute_prefix_function(pattern, psize);
	int k = -1;
    int count=0;
	if (!Pi)
		return 0;
	for (i = 0; i < tsize; i++) {
		while (k > -1 && pattern[k+1] != target[i])
			k = Pi[k];
		if (target[i] == pattern[k+1])
			k++;
		if (k == psize - 1) {
            count++;  //a pattern found from position i-k
            shesh[i-k]=i;
            shuru[i-k]=i-k;
		}
	}
	free(Pi);
	return count;
}


int main(int argc, const char *argv[])
{
    freopen("in.txt","r",stdin);
    
    int cases,caseno=1;
    scan(cases);
    getchar();
    char st[MAXN];
    while(cases--){
        scanf("%s",A);
        scanf("%s",st);
        buildsuffix();
        ms(shuru,-1);
        ms(shesh,-1);
        kmp(A,strlen(A),st,strlen(st));

        int temp=-1,temp2=-1;
        for(int i=N-1;i>=0;i--){
            if(shuru[i]!=-1) temp=shuru[i],temp2=shesh[i];
            shuru[i]=temp;
            shesh[i]=temp2;
//            cout<<shuru[i]<<' '<<shesh[i]<<endl;
        }

        printf("Case %d: %lld\n",caseno++,no_distinct_substr());
    }


    
    return 0;
}
