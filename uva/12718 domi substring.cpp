#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<iterator>
#include<cassert>

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



int main()
{
	char ch[1000009];
	while(scanf("%s",ch)!=EOF)
	{
		int len=strlen(ch);
		bool flag=false;
		for(int i=len-1;i>=0;i--)
		{
			if(ch[i]=='[')
			{
				flag=true;
				int temp=i+1;
				while(!(ch[temp]=='[' || ch[temp]==']') && temp<len)
				{
					cout<<ch[temp];
					temp++;
				}

			}
//			else if ( ch[i]==']')
//			{
//				flag=false;
//			}
//			else if(flag)
//			{
//				cout<<ch[i];
//			}

		}
//		break;
		flag=false;
		for(int i=0;i<len;i++)
		{
			if(ch[i]=='[')
			{
				flag=true;
			}
			else if(ch[i]==']')
			{
				flag=false;
			}
			else if(flag==false) cout<<ch[i];
		}
		cout<<endl;
	}



	return 0;
}

