
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

int tree[MAXN][MAXN];
int mx_x,mx_y;       //must be defined elsewhere

void update(int x,int y,int val)
{
	int temp_y=y;
	while(x<=mx_x){
		y=temp_y;;
		while(y<=mx_y){
			tree[x][y]+=val;
			y+=(y&-y);
		}
		x+=(x&-x);
	}
}

int read(int x,int y)
{
	int sum=0;
	int temp_y=y;
	while(x>0){
		y=temp_y;
		while(y>0){
			sum+=tree[x][y];
			y-=(y&-y);
		}
		x-=(x&-x);
	}
	return sum;
}


int calc(int x)
{
	int count=0;
	while(x>0 && x%5==0){
		count++;
		x/=5;
	}
	return count;
}




int main()
{

	int m;
	int n;
	cin>>m;

	int ans=0;
	for(int i=5;ans<m;i+=5){
		ans+=calc(i);
		n=i;
	}


	if(ans!=m){
		cout<<0<<endl;
		return 0;
	}
	else{
		cout<<5<<endl;
		for(int i=n;i<n+5;i++){
			cout<<i<<' ';
		}
		cout<<endl;
	}
	
	


	return 0;
}

