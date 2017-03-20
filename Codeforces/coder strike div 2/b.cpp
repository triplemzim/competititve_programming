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

int mirror[]={'A','H','I','M','O','T','U','V','W','X','Y'};

bool test(char c)
{
	bool flag=false;
	for(int i=0;i<11;i++)
	{
		if(c==mirror[i])
		{
			flag=true;
			break;
		}
	}
	return flag;
}

int main()
{
	char ch[100009];
	gets(ch);
	bool flag=true;
	int len=strlen(ch);
	for(int i=0;i<=len/2;i++)
	{
		if(!(test(ch[i])==true && ch[i]==ch[len-i-1]))
		{
			flag=false;
			break;
		}
	}
	if(flag) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;


	return 0;
}

