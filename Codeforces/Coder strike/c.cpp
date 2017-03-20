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
	char ch[100009];
	char ans[100009];
	int flag[100009]={0};
	bool change[100009]={false};
	cin>>n;
	scanf("%s",ans);
	int len=strlen(ans);
	for(int i=0;i<len;i++) if(ans[i]=='?') flag[i]++;

	for(int i=1;i<n;i++)
	{
		scanf("%s",ch);
		for(int j=0;j<len;j++)
		{
			if(ch[j]=='?') flag[j]++;
			if(ch[j]!=ans[j])
			{
				if(ans[j]=='?')
				{
					if(change[j]==false)
					{
						ans[j]=ch[j];
						change[j]=true;
					}
//					if(ans[j]!='?') change[j]=true;
				}
				else
				{
					change[j]=true;
					if(ch[j]!='?') ans[j]='?';
				}

			}
		}
	}
//	cout<<flag[0]<<endl;
	for(int i=0;i<len;i++)
	{
		if(flag[i]==n) cout<<'x';
		else cout<<ans[i];
	}




	return 0;
}

