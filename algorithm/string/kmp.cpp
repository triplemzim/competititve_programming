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
            return i-k;
		}
	}
	free(Pi);
	return count;
}

int main(int argc, const char *argv[])
{
	char target[] = "ABC ABCDAB ABCDABCDABDE";
	char *ch = target;
	char pattern[] = "ABCDABD";
	int i;

	i = kmp(target, strlen(target), pattern, strlen(pattern));
	if (i >= 0)
		printf("matched @: %s\n", ch + i);
	return 0;
}
