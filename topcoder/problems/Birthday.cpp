
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
#define inf 1<<30


struct Birthday{
string getNext(string date, vector <string> birthdays)
{
    string ret;

    int day_count[]={0,30,30+28,30+28+31,30+28+31+30,30+28+31+30+31,30+28+31+30+31+30,30+28+31+30+31+30+31,30+28+31+30+31+30+31+31,30+28+31+30+31+30+31+31+30,30+28+31+30+31+30+31+31+30+31,30+28+31+30+31+30+31+31+30+31+30,30+28+31+30+31+30+31+31+30+31+30+31};

    int temp_month,temp_dt,month=0,dt=0;
    char ch;
    month=(date[0]-48)*10+date[1]-48;
    dt=(date[3]-48)*10+date[4]-48;
    int temp,dif=inf,ans_month=0,ans_date=0;

    for(int i=0;i<birthdays.size();i++)
    {
		temp_month=(birthdays[i][0]-48)*10+birthdays[i][1]-48;
		temp_dt=(birthdays[i][3]-48)*10+birthdays[i][4]-48;
		if(temp_month==month)
		{
			temp=abs(dt-temp_dt);
		}
		else if(temp_month<month)
		{
			temp=day_count[month-1]+dt-temp_dt-day_count[temp_month-1];
		}
		else
		{
			temp=day_count[temp_month-1]+temp_dt-day_count[month-1]-dt;
		}
		if(temp<dif)
		{
			dif=temp;
			ans_month=temp_month;
			ans_date=temp_dt;
		}
    }
    ret="\0";
    ch=((ans_date%10)+48);
    ret=ch+ret;
    ans_date/=10;
    ch=(ans_date%10)+48;
    ret=ch+ret;
	ret='/'+ret;
	ch=(ans_month%10)+48;
	ret=ch+ret;
	ans_month/=10;
	ch=(ans_month%10)+48;
	ret=ch+ret;
//	ret=ret+'\0';


    return ret;
}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "06/17"; string Arr1[] = {"02/17 Wernie", "10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(0, Arg2, getNext(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "06/17"; string Arr1[] = {"10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(1, Arg2, getNext(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "02/17"; string Arr1[] = {"02/17 Wernie", "10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "02/17"; verify_case(2, Arg2, getNext(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "12/24"; string Arr1[] = {"10/12 Stefan"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "10/12"; verify_case(3, Arg2, getNext(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "01/02"; string Arr1[] = {"02/17 Wernie",
 "10/12 Stefan",
 "02/17 MichaelJordan",
 "10/12 LucianoPavarotti",
 "05/18 WilhelmSteinitz"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arg2 = "02/17"; verify_case(4, Arg2, getNext(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main()
{
Birthday ___test;
___test.run_test(-1);
int gbase;
cin>>gbase; // erase this line if you are not using dev-cpp! :)
return 0;
}
// END CUT HERE
