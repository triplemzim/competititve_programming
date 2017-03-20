#include<bits/stdc++.h>
using namespace std;


#define ms(x,val) memset(x,val,sizeof(x))
#define scan(x) scanf("%d",&x)
#define print(x) printf("debug= %d\n",x)
#define ull unsigned long long
#define iii long long
#define pi acos(-1)
#define pb push_back
#define PII pair<int,int>
#define vi vecotr<int>
#define MAPL map<long long, int > 
#define MAPI map<int,int> 
#define MAPP map< pair<int,int> , int>
#define MP make_pair
#define eps 1e-9
#define inf 999999999
#define MAXN 1009
#define MOD 1000000007 // 10^9 + 7


int main()
{

	int n;
	vector<int> s,t,a,b;

	int temp;
	scan(n);

	for(int i=0;i<n;i++){
		scan(temp);
		s.pb(temp);
	}
	for(int i=0;i<n;i++){
		scan(temp);
		t.pb(temp);
	}

	int zero=0;
	for(int i=0;i<n;i++){
		if(s[i]==0) zero++;
	}
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]) break;
		if(i==n-1){
			cout<<"YES"<<endl;
			return 0;
		}
	}


	if(zero==0){
		cout<<"NO"<<endl;
		return 0;
	}

	int st_s,st_t=0;

	for(int i=0;i<n;i++){
		if(s[i]!=0) a.pb(s[i]);
		if(t[i]!=0) b.pb(t[i]);
	}
	
	if(a.size()!=b.size()){
		cout<<"NO"<<endl;
		return 0;
	}

	for(int i=0;i<(int)a.size();i++){
		if(b[i]==a[0]){
			st_t=i;
			break;
		}
	}
	

	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]!=b[(st_t+i)%len]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;


		







	return 0;
}
