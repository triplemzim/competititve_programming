/****** BISMILLAH HIR RAHMANIR RAHIM ******/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ul;
typedef unsigned long long ull;
typedef vector <int> vi;
typedef set<int> si;
typedef set<string> ss;
typedef map<string,int>    msi;
typedef map<string,string> mss;
typedef map<int, vector<int> > mvii;
typedef map<string, vector <string> > mvss;
typedef map<char,int> mchi;
typedef map<int,char> mich;
typedef map<int, int> mii;
typedef queue <int> qi;
typedef map <int, vector<string> > mvis;
typedef map <string, vector<int> > mvsi;
typedef vector <string> vs;
typedef pair <int, int> pii;

#define MP make_pair
#define SORT(a) sort (a.begin(), a.end())
#define REVERSE(a) reverse (a.begin(), a.end())
#define PI acos(-1)
#define ms(x,y) memset (x, y, sizeof (x))
#define INF 2000000000
#define pb push_back
#define MAX 100002
#define debug cout<<"A"<<endl
#define prnt(a) cout<<a<<endl
#define mod 1000000009
#define FOR(i,a,b) for (int i=(a); i<(b); i++)
#define FORr(i,a,b) for (int i=(a); i>=b; i--)

int num[1000],len;

bool Check()
{
	if (len==0)
		return true;
	for(int i=0;i<=len/2;i++)
	{
		if(num[i]!=num[len-i-1]) return false;
	}
	return true;
}


int main()
{

	int n,lim;
    n=3;
    bool flag;
	while(scanf("%d",&n)!=EOF)
    {
//    while(n<1000001)
//	{
//        n++;
		int temp=n,b;

        flag=false;
        if(n==2||n==1)
        {
          if(n==2) printf("3\n"); 
          else printf("2\n");
            continue;
        }
//	    for(int base=2;base<=n-1;base++)
//		{
//			len=0;
//			temp=n;
//			while(temp)
//			{
//				num[len++]=temp%base;
//				temp=temp/base;
////				cout<<num[len-1]<<' ';
//			}
////			cout<<endl;
//
//			if(Check()==true)
//			{
////                cout<<n<<' ';
//                flag=true;
////                if(base==2) cout<<n<<" -- ";
////				printf("%d\n", base);
//				b=base;
//				break;
//			}
//		}
        lim=n>>1;
		for(int base=2;base<=lim;base++)
		{
			len=0;
			temp=n;
			while(temp)
			{
				num[len++]=temp%base;
				temp=temp/base;
//				cout<<num[len-1]<<' ';
			}
//			cout<<endl;

			if(Check()==true)
			{
//                if(b!=base){
//                     cout<<"hoynai"<<n<<' '<<base<<' '<<b<<endl;
//                     return 0;
//                }
//                cout<<n<<' ';
                flag=true;
//                if(base==2) cout<<n<<" -- ";
				printf("%d\n", base);
				break;
			}
		}
        if(flag==false) printf("%d\n",n-1);
	}
	

    return 0;
}
