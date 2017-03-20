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
int n,k,x,color[102],temp[102];

void print()
{
	for(int i=0;i<n;i++)
	{
		cout<<temp[i]<<' ';

	}
	cout<<endl;
}

int main()
{


	cin>>n>>x>>k;
	for(int i=0;i<n;i++)
	{
		cin>>color[i];
		temp[i]=color[i];
	}

	int count=0;
	int mx=0,prev=-1,mx_temp;

	count=1;
	for(int i=1;i<=n;i++)
	{
		if(i!=n && temp[i]==k && temp[i-1]==temp[i])
		{
			count++;
		}
		else if(count>=2)
		{
			mx_temp=count;
//			cout<<count<<endl;
			for(int j=i-count;temp[j]==k;j++)
			{
				temp[j]=-1;

			}
//			print();
			count=1;
			bool flag=true;
//			mx_temp=0;
			while(flag)
			{
				mx=max(mx,mx_temp);
				flag=false;
				int c=1,start=n;
				for(int kk=0;kk<n;kk++)
				{
					if(temp[kk]!=-1)
					{
						prev=temp[kk];
						start=kk;
						break;
					}
				}
//				cout<<start<<endl;

				int s=1;
				for(int kk=start+1;kk<=n;kk++)
				{
					if(kk!=n && temp[kk]==-1) {s++;continue;}
					if(kk!=n && temp[kk]==prev)
					{
						c++;
						s++;
					}
					else if(c>2)
					{
//						cout<<c<<endl;
						mx_temp+=c;
						mx=max(mx,mx_temp);
						flag=true;
						c=1;

						if(kk!=n) prev=temp[kk];
						for(int a=kk-s;a<kk;a++) temp[a]=-1;
						s=1;
//						print();
					}
					else if(kk!=n)
					{
						c=1;
						s=1;
						prev=temp[kk];
					}
				}


			}
			for(int a=0;a<n;a++)
			{
				temp[a]=color[a];
			}
		}
		else
		{
			count=1;
		}
	}

	cout<<mx<<endl;




	return 0;
}

