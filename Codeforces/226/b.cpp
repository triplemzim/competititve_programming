#include<bits/stdc++.h>

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
	char ch[5010];
	scanf("%s",ch);
	int len=strlen(ch);
	int count=0;
	for(int i=3;i<len;i++)
	{
		bool flag=false;
		for(int j=i;j<len;j++)
		{
			if(ch[j-3]=='b' && ch[j-2]=='e' && ch[j-1]=='a' && ch[j]=='r')
			{
				flag=true;
			}
			if(flag) count++;
		}
	}
	cout<<count<<endl;


	return 0;
}

