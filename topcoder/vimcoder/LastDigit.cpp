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
#define printv(vec) for(int i=0;i<vec.size();i++)cout<<vec[i]<<' ';cout<<endl;
#define itr_all(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1000009
#define MOD 1000000007 // 10^9 + 7

template <class T> inline T bigmod(T p,T e,T M)
{
    iii ret = 1;
    for(; e > 0; e >>= 1)
    {
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return (T)ret;
}
template < class T > T gcd(T a , T b ) { if(b==0) return a; else return gcd(b, a%b);}
template < class T > T lcm(T a , T b ) { return  a*b / gcd(a, b);}
template < class T > T absolute(T a ) { if(a>0) return a; else return -a;}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}
inline iii power(iii base,iii p) { iii ans=1; while(p>0) ans*=base,p-=1; return ans;}


struct LastDigit{

	int first_bit(iii s){
		while(s/10){
			s/=10;
		}
		return s;
	}

	iii calc(iii x,iii s,int len){
		iii fb = first_bit(s);

		x*=10;
		x+=fb;

		calc(x,
		


	

long long findX(long long S)
{
    long long ret;

	
	






    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 564LL; long long Arg1 = 509LL; verify_case(0, Arg1, findX(Arg0)); }
	void test_case_1() { long long Arg0 = 565LL; long long Arg1 = -1LL; verify_case(1, Arg1, findX(Arg0)); }
	void test_case_2() { long long Arg0 = 3000LL; long long Arg1 = 2701LL; verify_case(2, Arg1, findX(Arg0)); }
	void test_case_3() { long long Arg0 = 137174210616796LL; long long Arg1 = 123456789555123LL; verify_case(3, Arg1, findX(Arg0)); }
	void test_case_4() { long long Arg0 = 837592744927492746LL; long long Arg1 = -1LL; verify_case(4, Arg1, findX(Arg0)); }
	void test_case_5() { long long Arg0 = 999999999999999999LL; long long Arg1 = 900000000000000000LL; verify_case(5, Arg1, findX(Arg0)); }

// END CUT HERE

};



// BEGIN CUT HERE
int main()
{
LastDigit ___test;
___test.run_test(-1);
int gbase;  
return 0;
}
// END CUT HERE

