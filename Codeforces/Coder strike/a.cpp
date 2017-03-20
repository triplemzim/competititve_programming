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
	int start,len,pos;
	char ch[1000];
	bool flag;
	cin>>len>>pos;
	scanf("%s",ch);

	if(len/2>=pos)
	{
		start=0;
		flag=true;
	}
	else
	{
		start=len-1;
		flag=false;
	}
	if(flag)
	for(int i=0;i<pos-1;i++)
	{
		if(flag) cout<<"LEFT"<<endl;
		else cout<<"RIGHT"<<endl;
	}
	else
	{
		for(int i=pos;i<len;i++)
		{
			if(flag) cout<<"LEFT"<<endl;
			else cout<<"RIGHT"<<endl;
		}
	}

	cout<<"PRINT "<<ch[start]<<endl;
		if(flag) start++;
		else start--;

	for(int i=1;i<len;i++)
	{
		if(!flag) cout<<"LEFT"<<endl;
		else cout<<"RIGHT"<<endl;

		cout<<"PRINT "<<ch[start]<<endl;
		if(flag) start++;
		else start--;
	}



	return 0;
}

