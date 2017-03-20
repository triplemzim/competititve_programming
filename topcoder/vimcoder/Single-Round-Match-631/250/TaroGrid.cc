/*
 * =====================================================================================
 *
 *       Filename:  b.cpp
 *
 *         Author:  Shadow_Crawler (Zim), triplemzim@gmail.com
 *        Company:  BUET
 *
 * =====================================================================================
 */

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()
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

using namespace std;

// }}}

class TaroGrid
{
public:
	int getNumber(vector <string> grid)
	{
        int max_w=0,max_b=0,tempw,tempb;
        int n=grid.size();
        for (int  i = 0; i < n; i++) {
            tempw=tempb=0;
            bool fw=false,fb=false;
            for (int  j = 0; j < n; j++) {
                if(grid[j][i]=='W')
                {
                    fb=false;
                    if(fw==true)
                    {
                        tempw++;
                    }
                    else
                    {
                        max_w=max(max_w,tempw);
                        tempw=1;
                        fw=true;
                    }
                }
                else
                {
                    fw=false;
                    if(fb==true)
                    {
                        tempb++;
                    }
                    else
                    {
                        max_b=max(max_b,tempb);
                        tempb=1;
                        fb=true;
                    }
                }
            }
             max_b=max(max_b,tempb);
            max_w=max(max_w,tempw);

        }
            max_b=max(max_b,tempb);
            max_w=max(max_w,tempw);
            int ret;
            if(max_b>max_w) ret=max_b;
            else ret=max_w;
		return ret;
	}
};

