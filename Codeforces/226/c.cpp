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

#define sets(n,pos) (n|(1<<pos))
#define check(n,pos) (bool(n&(1<<pos)))
#define mx 10000000
#define lim 10000000
bool color[10000009]={0};
vector<int>p;
unsigned prime[mx>>6];
void seive()
{
	unsigned k,i,j;
	p.pb(1);p.pb(2);
	color[2]=true;
	prime[2>>6]=sets(prime[2>>6],0);
	for(i=3;i<=lim;i+=2)
	{
		if(check(prime[i>>6],((i>>1)&31))==0)
		{	p.pb(i);
//			color[i]=true;
//			if(i<100) cout<<i<<" ";
			k=i<<1;
			for(j=i*i;j<=mx;j+=k)
			{
				prime[j>>6]=sets(prime[j>>6],((j>>1)&31));
			}
		}
	}
	return;
}

iii n,x[10000009],t[10000009]={0};
int main()
{
	seive();
//	cout<<p.size();

	iii count,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>x[i];
	}
	sort(x,x+n);
	int k=sqrt(x[n-1]);
	for(unsigned j=2;j<10000001;j+=2)
	{
		count=0;
		if(check(prime[j>>6],((j>>1)&31))==0){

			for(int i=n-1;x[i]>=j;i--)
			{
				if(x[i]%j==0) count++;
	//			if(color[x[i]/p[j]]==true)
	//			{
	//				t[p[x[i]/p[j]]]++;
	//			}
			}

		}
		t[j]=t[j-2]+count;if(j==2) j--;

//		if(count) cout<<p[j]<<' '<<count<<endl;
	}

	cin>>m;
	iii l,s;
	vector<int> ::iterator a,b;
	for(int i=0;i<m;i++)
	{
		cin>>l>>s;
		if(s>10000000) s=x[n-1];
		if(l>s) l=s;
//		if(l==s)
//		{
//			cout<<0<<endl;
//			continue;
//		}
//		a=lower_bound(p.begin(),p.end(),l);
//		b=lower_bound(p.begin(),p.end(),s);
//		if(p[b-p.begin()]!=s) b--;
////		if(color[p[a-p.begin()]]==false) a--;
//		a--;
////		cout<<<<endl;
////		cout<<p[b-p.begin()]<<endl;
//		cout<<t[p[b-p.begin()]]-t[p[a-p.begin()]]<<endl;
if(s%2==0) s--;
if(l%2==0) s--;
cout<<t[s]-t[l-1]<<endl;
	}
	return 0;
}



