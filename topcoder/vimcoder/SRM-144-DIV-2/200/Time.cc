
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
 #include<set> 
#include<sstream>
#include<stack>
using namespace std;

#define ms(x,val) memset(x,val,sizeof(x))
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define repi(i,a,n) for(int i=a;i<n;i++)
#define pb push_back
#define PII pair<int,int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999


struct Time{
string whatTime(int seconds)
{
    string ret;
    int h=seconds/3600;
    seconds%=3600;
    int m=seconds/60;
    seconds%=60;

    vector<char>v;
    if(!seconds) v.pb(48);
    while(seconds)
	{
		v.pb(seconds%10+48);
		seconds/=10;
	}
	v.pb(':');
	seconds=m;
	if(!seconds) v.pb(48);
	while(seconds)
	{
		v.pb(seconds%10+48);
		seconds/=10;
	}
	v.pb(':');
	seconds=h;
	if(!seconds) v.pb(48);
	while(seconds)
	{
		v.pb(seconds%10+48);
		seconds/=10;
	}
    for(int i=v.size()-1;i>=0;i--)
	{
		ret=ret+v[i];
	}

    return ret;
}


};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
