










//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 


#define code "MessageMess.cpp"


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ 

















#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;

#define FORIT(i, m) for (__typeof((m).begin()) i=(m).begin(); i!=(m).end(); ++i)
#define REP(i,n) for(__typeof(n) i=0; i<(n); i++)
#define FOR(i,a,b) for(__typeof(b) i=(a); i<=(b); i++)

#define sz size()
#define pb push_back
#define MP make_pair

#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define REV(x) reverse( ALL( x ) )

#define VI vector<int>
#define VS vector<string>
#define LL long long

#define INF (1<<29)
#define eps (1e-11)

int dr[] = {-1,+0,+1,+0,+1,+1,-1,-1 };
int dc[] = {+0,+1,+0,-1,+1,-1,+1,-1 };

inline bool compare( double a, double b ) { return fabs( a-b ) < 1e-9 ; }

/// lam lam lam ///

/*  VERSION 0.4
    * it cleans the unused defines
    * cleans the commented lines that has comment sign in the first two column
    * it tries not to put too many blank line inbetween two codes - remember this wont work properly
      if you put spaces in the blank lines  
      
    HOW TO USE IT
    * put the name in the code defining
    * put this code in the same folder
    * compile this code
    * run this code
    
    Its still in 0th version, it can have bugs. I'll try to update it everytime i find a bug   
*/
    
int main() {
    VS in, out;
    char s[100000];
    
    freopen(code,"r",stdin);
    while( gets( s ) ) in.pb( s );
    REP(i,in.sz) {
        string x = in[i], dabba;
        stringstream ss( x );
        ss >> dabba;
        if( dabba == "#define" ) { // checking a define
            ss >> dabba;
            string u;
            REP(j,dabba.sz) {
                if( dabba[j] == '(' ) break;
                u += dabba[j];
            }
            bool ok = false;
            
//            cout << "checking " << u << endl;
            
            FOR(j,i+1,in.sz-1) {
                if( in[j].find(u) != string::npos ) {
                    ok = true;
                    break;
                }   
            }
            if( ok ) out.pb( x );
        }else if( dabba == "//" && x[0] == '/') {
            ss >> dabba;
            if( dabba == "BEGIN" || dabba == "END" ) out.pb( x );
        }else if( out.sz && x == "" && out[out.sz-1] == "" ) continue; 
        else out.pb( x );
        
    }   
    out.pb("// Powered by smilitude's cleaner");
    freopen(code,"w",stdout);
    REP(i,out.sz) printf("%s\n",out[i].c_str());
    
    return 0;
}
