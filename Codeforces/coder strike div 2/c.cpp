//status: WA

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
	int status[100009]={0},n,m;
	char c;
	int temp,cur[100009]={0},last_sign[100009]={0};
	int count=0;
	cin>>n>>m;
	vector<int> v;
	vector<char> ch;

	int last_plus=0;

	for(int i=0;i<m;i++)
	{
		scanf(" %c %d",&c,&temp);
		v.pb(temp);
		ch.pb(c);



//
		if(c=='-') cur[temp]=-1;
		else cur[temp]=1;
		if(c=='-') last_sign[temp]=-1;
		else last_sign[temp]=1;

		if(c=='+') last_plus=i;
//		if(ch=='-')
//		{
//			if(status[temp]==0) status[temp]=-2;
//			else status[temp]=-1;
//		}
//		else
//		{
//			if(status[temp]==0) status[temp]=1;
//			else status[temp]=2;
//		}
	}
	for(int i=0;i<last_plus;i++)
	{
		if(ch[i]=='-') {
			status[v[i]]=-5;
//			cout<<v[i]<<endl;
		}
		else status[v[i]]=0;
	}
	for(int i=last_plus;i<v.size();i++)
	{
		if(ch[i]=='-' && i!=v.size()-1) status[v[i]]=-5;
	}

	for(int i=last_plus-1;i>=0;i--)
	{
		if(v[i]==v[last_plus]) break;
		else status[v[last_plus]]=-5;
	}

	if(last_plus<v.size()-1)
	{
		if(v[last_plus]!=v[last_plus+1])
		{
			if(ch[last_plus+1]=='-')
			{
				status[v[last_plus]]=-5;
			}
		}
	}
	if(v.size()>1 && last_sign[v[last_plus]]==1) status[v[v.size()-1]]=-5;


	int total=0;
	bool flag=false;
	for(int i=1;i<=n;i++)
	{
		if(status[i]!=-5)
		{
//			cout<<i<<' ';
			total++;
			flag=true;
		}
	}
	if(flag==false) cout<<0<<endl;
	else
	{
		cout<<total<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		if(status[i]!=-5)
		{
			cout<<i<<' ';
//			total++;
			flag=true;
		}
	}


	return 0;
}

