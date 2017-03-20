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
	int n;
	char domino[3010];
	cin>>n;
	scanf("%s",domino);
	int count=0;
	bool f_f=false;
	int i;
	for(i=0;i<n;i++)
	{
		if(domino[i]=='R') break;
		else if(domino[i]=='L'){ count=0; break;}
		else count++;
	}
	int last=i++;
	char cur;
	for(i=i;i<n;i++)
	{
		if(domino[i]=='L')
		{
			if((i-last+1)%2==1)count++;
			last=i;
		}
		else if(domino[i]=='R')
		{
			count+=(i-last-1);
			last=i;
		}
	}
	if(domino[last]=='L') count+=(n-1-last);
	cout<<count<<endl;


	return 0;
}

