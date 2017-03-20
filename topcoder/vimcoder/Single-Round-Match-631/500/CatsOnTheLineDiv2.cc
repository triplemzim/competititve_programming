/*
 * =====================================================================================
 *
 * Description:  Not solved
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
class store{
    public:
    int pos,num;

    bool operator<(const store x)const { return pos<x.pos;}
};

class CatsOnTheLineDiv2
{
public:
	string getAnswer(vector <int> position, vector <int> count, int time)
	{
        store st[1009];
        int n=count.size();
        for (int  i = 0; i < n; i++) {
            st[i].pos=position[i];
            st[i].num=count[i];
        }
        sort(st,st+n);

        int low=-1010;
        bool flag=true;
        int temp=time;
        int left,right;
        for(int i=0;i<n;i++)
        {
            temp=time;
            int p=st[i].pos;
            if(i==0) right=left=1000;
            //for left
            if(time>st[i].num)
            {
                
            }




            if(st[i].num>0) flag=false;

        }

        if(flag) return "Possible";
        else return "Impossible";

	}
};

